#include "raylib.h"

int main() {
    InitWindow(1400, 800, "EduCore Education");
    SetTargetFPS(60);
    enum appState { homePage, mathPage, exercises, test, materials };
    appState currentPage = homePage;
    Color eduBlue = { 0, 160, 233, 255 };   // RGB values for EduCore Blue
    Color eduOrange = { 252, 176, 33, 255 }; // RGB values for EduCore Orange
    Color mainBackground = { 10, 14, 20, 255 };
    Color subSectionsBg = { 20, 30, 45, 255 }; // RGB values for background color for the main parts of the app
    Color sectionOutlines = { 7, 112, 182, 255 }; // RGB values for the outlines of the sections
    Color eduTurquoise = { 0, 120, 130, 255 }; // RGB values for EduCore Turquoise
    float spacing = 20.0f; // Spacing between elements
    float separationLineY = 220.0f; // Y position for the separation line
    float mainSectionHeight = (float)GetScreenHeight() - separationLineY - spacing * 2.0f; // Height for the main section
    float mainSectionY = separationLineY + spacing; // Y position for the main section

    int subjectTextWidth = MeasureText("Please choose a subject", 30);
    float centerX = 40.0f + (1320.0f / 2.0f) - (subjectTextWidth / 2.0f);

    Rectangle backButtonRect = { 20.0f, 10.0f, 120.0f , 50.0f };
    Rectangle subMathSection = { 74.0f , mainSectionY + 5.0f * spacing, 390.0f , 290.0f };
    Rectangle subMathSectionHw = { subMathSection.x + 390.0f + spacing * 2.0f, subMathSection.y, subMathSection.width, subMathSection.height };
    Rectangle subMathSectionTest = { subMathSection.x + 390.0f * 2.0f + spacing * 4.0f, subMathSection.y, subMathSection.width, subMathSection.height };
    Rectangle subMathSectionLabel = { subMathSection.x - 2.0f, subMathSection.y - 1.0f, subMathSection.width + 3.0f, 40.0f };

    Rectangle mathSection = { 80.0f , mainSectionY + 5.0f * spacing, 1320.0f - 80.0f , 200.0f };
    float labelHeight = 40.0f;
    Rectangle labelRect = { mathSection.x - 2.0f, mathSection.y - 1.0f, mathSection.width + 3.0f, labelHeight };

    Image image = LoadImage("eduCoreLogo.png");
    ImageResize(&image, 200, 200);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();
        switch (currentPage) {
        case homePage: {

            if (CheckCollisionPointRec(mousePoint, mathSection)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = mathPage; // change the window to the math page
                }
            }
        }
                     break;

        case mathPage: {
            
            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = homePage; // change the window to the home page
                }
            }
            if (CheckCollisionPointRec(mousePoint, subMathSectionTest)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = test; // change the window to the math test page
                }
            }
            if (CheckCollisionPointRec(mousePoint, subMathSection)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math materials and lessons page
                }
            }
            if (CheckCollisionPointRec(mousePoint, subMathSectionHw)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = exercises; // change the window to the exrecices page
                }
            }
        }
                     break;

        case test: {
           
            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = mathPage; // change the window to the math page
                }
            }
        }
                 break;

        case materials: {
            
            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = mathPage; // change the window to the math page
                }
            }
        }
        break;

        case  exercises: {
            
            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = mathPage; // change the window to the math page
                }
            }
        }
        break;
        }

        bool hoverBack = CheckCollisionPointRec(mousePoint, backButtonRect);
		bool hoverSubMathText = CheckCollisionPointRec(mousePoint, subMathSection);
        bool hoverSubMathTextHw = CheckCollisionPointRec(mousePoint, subMathSectionHw);
        bool hoverSubMathTextTest = CheckCollisionPointRec(mousePoint, subMathSectionTest);
		Color hoverSubTextColor = hoverSubMathText ? LIGHTGRAY : GRAY;
        Color hoverSubTextColorHw = hoverSubMathTextHw ? LIGHTGRAY : GRAY;
        Color hoverSubTextColorTest = hoverSubMathTextTest ? LIGHTGRAY : GRAY;
        Color backBtnColor = hoverBack ? eduBlue : subSectionsBg;
        BeginDrawing();
        ClearBackground(mainBackground);

        switch (currentPage) {
        case homePage:
            DrawText("Welcome to ", 20, 70, 70, eduBlue);
            DrawText("EduCore Online School !", 20, 140, 70, eduOrange);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText(" Please choose a subject", (int)centerX, (int)(mainSectionY + 30.0f), 30, RAYWHITE);

            DrawRectangleRounded(mathSection, 0.2f, 10, mainBackground);
            DrawRectangleRounded(labelRect, 1.0f, 10, eduTurquoise);
            DrawRectangle((int)labelRect.x, (int)(labelRect.y + labelHeight / 2.0f), (int)labelRect.width, (int)(labelHeight / 2.0f), eduTurquoise);
            DrawRectangleRoundedLines(mathSection, 0.2f, 10, eduTurquoise);

            DrawText(" MATHS    [ + - * /]", (int)(mathSection.x + 20.0f), (int)(mathSection.y + 10.0f), 25, RAYWHITE);
            DrawText("Explore the world of numbers and equations with our comprehensive math courses.", (int)(mathSection.x + 20.0f), (int)(mathSection.y + 50.0f), 20, RAYWHITE);
            DrawText("From basic arithmetic to advanced calculus, our curriculum is designed to build a strong foundation in mathematics.", (int)(mathSection.x + 20.0f), (int)(mathSection.y + 55.0f + spacing), 20, RAYWHITE);
            DrawText("Content: ", (int)(mathSection.x + 20.0f), (int)(mathSection.y + 60.0f + spacing * 3.0f), 20, sectionOutlines);
            DrawText("Materials & Lessons / Exercises for HW and practice / Tests", (int)(mathSection.x + 20.0f), (int)(mathSection.y + 70.0f + spacing * 4.0f), 20, GRAY);

            DrawText("Discover more subjects with EduCorePlus", 90, (int)(mainSectionY + 10.0f * spacing + 200.0f), 25, sectionOutlines);
            break;

        case mathPage:
            DrawText("Welcome to ", 20, 70, 70, eduBlue);
            DrawText("Maths", 20, 140, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            // subMath Section Materials
            DrawRectangleRounded(subMathSection, 0.2f, 10, mainBackground);
            DrawRectangleRounded(subMathSectionLabel, 1.0f, 10, eduTurquoise);
            DrawRectangle((int)subMathSectionLabel.x, (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)subMathSectionLabel.width, (int)labelHeight, eduTurquoise);
            DrawText("Materials & Lessons", (int)(subMathSection.x + spacing), (int)(subMathSection.y + spacing - 5.0f), 30, RAYWHITE);
			DrawText("Access comprehensive study guides", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 85.0f), 18, hoverSubTextColor);
            DrawText("and step-by-step explanations to master", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 110.0f), 18, hoverSubTextColor);
            DrawText("new mathematical concepts.", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 135.0f), 18, hoverSubTextColor);
            DrawRectangleRounded({ subMathSectionLabel.x + 42.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
            DrawText("View", (int)(subMathSection.x + spacing + 140.0f), (int)(subMathSection.y + spacing + 205.0f), 30, RAYWHITE);
			// subMath Section HW and practice
            DrawRectangleRounded(subMathSectionHw, 0.2f, 10, mainBackground);
            DrawRectangleRounded({ subMathSectionHw.x, subMathSectionHw.y, subMathSectionHw.width, labelHeight }, 1.0f, 10, eduTurquoise);
            DrawRectangle((int)(subMathSectionLabel.x + 391.0f + spacing * 2.0f), (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)(subMathSectionLabel.width - 1.0f), (int)labelHeight, eduTurquoise);
            DrawText("HW and practice", (int)(subMathSectionHw.x + spacing), (int)(subMathSectionHw.y + spacing - 5.0f), 30, RAYWHITE);
            DrawText("Sharpen your skills with interactive", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 85.0f), 18, hoverSubTextColorHw);
            DrawText("problem sets and exercises designed to", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 110.0f), 18, hoverSubTextColorHw);
            DrawText("reinforce what you've learned in class.", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 135.0f), 18, hoverSubTextColorHw);
            DrawRectangleRounded({ subMathSectionLabel.x + 472.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
            DrawText("Practise", (int)(subMathSectionHw.x + spacing + 110.0f), (int)(subMathSectionHw.y + spacing + 205.0f), 30, RAYWHITE);
			//  subMath Section Tests
            DrawRectangleRounded(subMathSectionTest, 0.2f, 10, mainBackground);
            DrawRectangleRounded({ subMathSectionTest.x, subMathSectionTest.y, subMathSectionTest.width, labelHeight }, 1.0f, 10, eduTurquoise);
            DrawRectangle((int)(subMathSectionLabel.x + 391.0f * 2.0f + spacing * 4.0f), (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)(subMathSectionLabel.width - 2.0f), (int)labelHeight, eduTurquoise);
            DrawText("Tests", (int)(subMathSectionTest.x + spacing), (int)(subMathSectionTest.y + spacing - 5.0f), 30, RAYWHITE);
            DrawText("Evaluate your progress and prepare for", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 85.0f), 18, hoverSubTextColorTest);
            DrawText("exams with timed quizzes and mock tests", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 110.0f), 18, hoverSubTextColorTest);
            DrawText("covering all key curriculum topics.", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 135.0f), 18, hoverSubTextColorTest);
            DrawRectangleRounded({ subMathSectionLabel.x + 902.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
            DrawText("Start Test", (int)(subMathSectionTest.x + spacing + 90.0f), (int)(subMathSectionTest.y + spacing + 205.0f), 30, RAYWHITE);
            break;

        case test:
            DrawText("Welcome to ", 20, 70, 70, eduBlue);
            DrawText("Maths Test", 20, 140, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            break;

        case materials:
            DrawText("Welcome to ", 20, 70, 70, eduBlue);
            DrawText("Maths Materials & Lessons", 20, 140, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            break;

        case exercises:
            DrawText("Welcome to ", 20, 70, 70, eduBlue);
            DrawText("Maths Exercises", 20, 140, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            break;
        }

        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}