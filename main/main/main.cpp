#include "raylib.h"
int main() {
    InitWindow(800, 600, "My Raylib App");
    SetTargetFPS(60); 
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Hello, Raylib!", 300, 270, 30, DARKGRAY);
        EndDrawing();
    }     
    CloseWindow();
    return 0;
}