cmake_minimum_required(VERSION 3.11)
project(raylib_project)

set(CMAKE_BUILD_TYPE "Release")

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Raylib
set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
  endif()
endif()

# Bullet Physics
set(BULLET_PHYSICS_DIR "${CMAKE_SOURCE_DIR}/deps/bullet3")
# Bullet source directories
set(BULLET_INCLUDE_DIRS ${BULLET_PHYSICS_DIR}/src)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BULLET_LIBRARIES
        ${BULLET_PHYSICS_DIR}/build/lib/Debug/BulletDynamics_Debug.lib
        ${BULLET_PHYSICS_DIR}/build/lib/Debug/BulletCollision_Debug.lib
        ${BULLET_PHYSICS_DIR}/build/lib/Debug/LinearMath_Debug.lib
    )
else()
    set(BULLET_LIBRARIES
        ${BULLET_PHYSICS_DIR}/build/lib/Release/BulletDynamics.lib
        ${BULLET_PHYSICS_DIR}/build/lib/Release/BulletCollision.lib
        ${BULLET_PHYSICS_DIR}/build/lib/Release/LinearMath.lib
    )
endif()

include_directories(${BULLET_INCLUDE_DIRS})

include_directories(deps/bullet3)
link_directories(${BULLET_LIB_DIR})

# add executable
add_executable(
  ${PROJECT_NAME} 
  src/main.cpp
)

target_link_libraries(
  ${PROJECT_NAME}
  raylib
  ${BULLET_LIBRARIES}
)