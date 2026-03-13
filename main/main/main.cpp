#include "raylib.h"
int main() {
    InitWindow(1400, 800, "EduCore Education");
    SetTargetFPS(60); 
    enum appState { homePage, mathPage, exrecices, test, materials };
    appState currentPage = homePage;
	Color eduBlue = { 0, 160, 233, 255 };   // RGB values for EduCore Blue
	Color eduOrange = { 252, 176, 33, 255 }; // RGB values for EduCore Orange
    Color mainBackground = { 10, 14, 20, 255 };
	Color subSectionsBg = { 20, 30, 45, 255 }; // RGB values for background color for the main parts of the app
    Color sectionOutlines = { 7, 112, 182, 255 }; // RGB values for the outlines of the sections
	Color eduTurquoise = { 0, 206, 209, 255 }; // RGB values for EduCore Turquoise
	float spacing = 20.0f; // Spacing between elements
	float separationLineY = 220.0f; // Y position for the separation line
	float mainSectionHeight = GetScreenHeight() - separationLineY - spacing * 2; // Height for the main section
	float mainSectionY = separationLineY + spacing; // Y position for the main section

    int textWidth = MeasureText("Please choose a subject", 30);
    float centerX = 40 + (1320 / 2.0f) - (textWidth / 2.0f);

    Rectangle mathSection = { 80 , mainSectionY + 5 * spacing, 1320 - 80 , 200 };
    float labelHeight = 40.0f; // Колко дебел да е цветният "лейбъл"
    Rectangle labelRect = { mathSection.x - 2, mathSection.y - 1, mathSection.width + 3, labelHeight };

    Image image = LoadImage("eduCoreLogo.png");
    ImageResize(&image, 200, 200);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);
    while (!WindowShouldClose()) {
        switch (currentPage) {
            case homePage: {
                Vector2 mousePoint = GetMousePosition();
                if (CheckCollisionPointRec(mousePoint, mathSection)) {
                    if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
					    currentPage = mathPage; // chnge the window to the math page
                    }
                }
            } 
            break;
        }
        BeginDrawing();
        ClearBackground(mainBackground);

        switch (currentPage) {
            case homePage:
                DrawText("Welcome to ", 20, 60, 70, eduBlue);
                DrawText("EduCore Online School !", 20, 130, 70, eduOrange);
                DrawTexture(texture, 1150, 10, WHITE);
                DrawRectangle(40, separationLineY, GetScreenWidth() - 80, 2, eduBlue);
                DrawRectangleRounded({ 40, separationLineY + 30, 1320 , mainSectionHeight }, 0.1f, 10, subSectionsBg);
                DrawText(" Please choose a subject", centerX, mainSectionY + 30, 30, RAYWHITE);

                DrawRectangleRounded(mathSection, 0.2f, 10, mainBackground);
                // 2. draw a lebal on the top of the maths section
                DrawRectangleRounded(labelRect, 1.0f, 10, sectionOutlines); // Използваме твоя цвят
                // 3 draw the bottom part of the label to create a separation between the label and the main section
                DrawRectangle(labelRect.x, labelRect.y + labelHeight / 2, labelRect.width, labelHeight / 2, sectionOutlines);
                // 4.Adds the outline for the maths section
                DrawRectangleRoundedLines(mathSection, 0.2f, 10, sectionOutlines);
                // 5. Heading and content for the maths section
                DrawText(" MATHS    [ + - * /]", mathSection.x + 20, mathSection.y + 10, 25, RAYWHITE);
                DrawText("Explore the world of numbers and equations with our comprehensive math courses.", mathSection.x + 20, mathSection.y + 50, 20, RAYWHITE);
                DrawText("From basic arithmetic to advanced calculus, our curriculum is designed to build a strong foundation in mathematics.", mathSection.x + 20, mathSection.y + 55 + spacing, 20, RAYWHITE);
                DrawText("Content: ", mathSection.x + 20, mathSection.y + 60 + spacing * 3, 20, eduTurquoise);
                DrawText("Exercises for HW and practice / Materials & Lessons / Test", mathSection.x + 20, mathSection.y + 70 + spacing * 4, 20, GRAY);

                DrawText("Discover more subjects with EduCorePlus", 90, mainSectionY + 10 * spacing + 200, 25, eduTurquoise);
                break;

            case mathPage:
                DrawText("WELCOME TO MATH QUIZ!", 100, 100, 30, eduTurquoise);
                DrawText("Press Backspace to return", 100, 200, 20, GRAY);
                break;
        }

        EndDrawing();
    }   
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}