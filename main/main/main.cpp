#include "raylib.h"
int main() {
    InitWindow(1400, 800, "EduCore Education");
    SetTargetFPS(60); 
	Color eduBlue = { 0, 160, 233, 255 };   // RGB values for EduCore Blue
	Color eduOrange = { 252, 176, 33, 255 }; // RGB values for EduCore Orange
    Color mainBackground = { 10, 14, 20, 255 };
	Color subSectionsBg = { 20, 30, 45, 255 }; // RGB values for background color for the main parts of the app
	float spacing = 20.0f; // Spacing between elements
	float separationLineY = 220.0f; // Y position for the separation line
	float mainSectionHeight = GetScreenHeight() - separationLineY - spacing * 2; // Height for the main section
	float mainSectionY = separationLineY + spacing; // Y position for the main section

    Image image = LoadImage("eduCoreLogo.png");
    ImageResize(&image, 200, 200);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(mainBackground);
		DrawText("Welcome to ", 20, 60, 70, eduBlue);
        DrawText("EduCore Online School !", 20, 130, 70, eduOrange);
        DrawTexture(texture, 1150, 10, WHITE);
        DrawRectangle(40, separationLineY, GetScreenWidth() - 80, 2, eduBlue);
        DrawRectangleRounded({ 40, separationLineY + 30, 1320 , mainSectionHeight }, 0.1f, 10, subSectionsBg);
		DrawText(" Please choose subject", 550 , mainSectionY + 30, 30, RAYWHITE);
		
        EndDrawing();
    }   
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}