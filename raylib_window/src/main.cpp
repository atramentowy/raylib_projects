#include "raylib.h"

int main(void) {
    // Initialization
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Basic raylib Project");

    SetTargetFPS(60);  // Set FPS to 60

    // Main game loop
    while (!WindowShouldClose()) {
        // Update

        // Draw
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawText("Hello, raylib!", 190, 200, 20, LIGHTGRAY);
        DrawCircle(screenWidth / 2, screenHeight / 2, 50, RED);

        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}