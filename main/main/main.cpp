#include "raylib.h"

int main() {
    InitWindow(1400, 800, "EduCore Education");
    SetTargetFPS(60);
    enum appState { homePage, mathPage, exercises, test, materials, resursesTab1, resursesTab2, resursesTab3, resursesTab4, resursesTab5, exPractice };
    appState currentPage = homePage;
    Color eduBlue = { 0, 160, 233, 255 };   // RGB values for EduCore Blue
    Color eduOrange = { 252, 176, 33, 255 }; // RGB values for EduCore Orange
    Color mainBackground = { 10, 14, 20, 255 };
    Color subSectionsBg = { 20, 30, 45, 255 }; // RGB values for background color for the main parts of the app
    Color sectionOutlines = { 7, 112, 182, 255 }; // RGB values for the outlines of the sections
    Color eduTurquoise = { 0, 120, 130, 255 }; // RGB values for EduCore Turquoise
    Color eduGreen = { 46, 204, 113, 255 };
    Color eduRed = { 231, 76, 60, 255 };
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
    Rectangle resusrsesP1 = { 480.0f, 160.0f, 50.0f , 45.0f };
    Rectangle resusrsesP2 = { 540.0f, 160.0f, 50.0f , 45.0f };
    Rectangle resusrsesP3 = { 600.0f, 160.0f, 50.0f , 45.0f };
    Rectangle resusrsesP4 = { 660.0f, 160.0f, 50.0f , 45.0f };
    Rectangle resusrsesP5 = { 720.0f, 160.0f, 50.0f , 45.0f };
    Rectangle hwPracticeRect = { 70.0f, 160.0f ,200.0f ,45.0f };
    Rectangle exPracticeRect = { 280.0f, 160.0f ,200.0f ,45.0f };

    float labelHeight = 40.0f;
    Rectangle labelRect = { mathSection.x - 2.0f, mathSection.y - 1.0f, mathSection.width + 3.0f, labelHeight };

    Image image = LoadImage("eduCoreLogo.png");
    ImageResize(&image, 200, 200);
    Texture2D texture = LoadTextureFromImage(image);
    UnloadImage(image);

    struct Question {
        const char* text;
        const char* answers[3]; // а, б, в
        int correct;            // 0, 1 или 2
    };

    // Твоите 10 въпроса (без системи)
    Question practiceQuiz[10] = {
        {"Solve: (x - 3)(x + 2) = 0", {"x=3, x=-2", "x=-3, x=2", "x=1"}, 0},
        {"Solve: 2x + 10 = 3x - 5", {"x=5", "x=15", "x=-15"}, 1},
        {"Roots of: x^2 - 7x + 10 = 0", {"x=2, 5", "x=-2, -5", "x=3, 4"}, 0},
        {"Solve: 3(x - 4) = 0", {"x=0", "x=-4", "x=4"}, 2},
        {"Solve: x^2 - 9 = 0", {"x=3", "x=+-3", "x=9"}, 1},
        {"Solve: x^2 - 4xy + 4y^2 = 0", {"x=2y", "x=y", "x=4y"}, 0},
        {"Solve: 4x - 12 = 2x + 6", {"x=6", "x=12", "x=9"}, 2},
        {"Discriminant of: x^2 + 4x + 4 = 0", {"D=16", "D=0", "D=8"}, 1},
        {"Solve: x^2 + xy - 6y^2 = 0", {"x=2y, -3y", "x=y, 6y", "x=3y, -2y"}, 0},
        {"Solve: x^2 - xy = 0", {"x=1", "x=0, y", "x=0, x=y"}, 2}
    };

    int currentQ = 0;       // Кой въпрос сме в момента
    int selectedAns = -1;   // Кой отговор е цъкнал потребителя (-1 значи никой)

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

            if (CheckCollisionPointRec(mousePoint, resusrsesP1)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab1; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
                }

            }
        }
                      break;
        case resursesTab1: {

            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
                }

            }
        }
        break;
        
        case resursesTab2: {

            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP1)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab1; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
                }

            }
        }
        break;

        case resursesTab3: {

            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP1)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab1; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
                }

            }
        }
        break;

        case resursesTab4: {

            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP1)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab1; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
                }

            }
        }
        break;

        case resursesTab5: {

            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = materials; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP1)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab1; // change the window to the math page
                }
            }

            if (CheckCollisionPointRec(mousePoint, resusrsesP2)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab2; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP3)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab3; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP4)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab4; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, resusrsesP5)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = resursesTab5; // change the window to the math page
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
            if (CheckCollisionPointRec(mousePoint, exPracticeRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = exPractice; // change the window to the exPractice page
                }
            }
        }
        break;



        case exPractice: {
            if (CheckCollisionPointRec(mousePoint, backButtonRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = mathPage; // change the window to the math page
                }
            }
            if (CheckCollisionPointRec(mousePoint, hwPracticeRect)) {
                if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    currentPage = exercises;
                }
            }
        }break;
        }

        bool hoverBack = CheckCollisionPointRec(mousePoint, backButtonRect);
        bool  hoverResursesP1 = CheckCollisionPointRec(mousePoint, resusrsesP1);
        bool  hoverResursesP2 = CheckCollisionPointRec(mousePoint, resusrsesP2);
        bool  hoverResursesP3 = CheckCollisionPointRec(mousePoint, resusrsesP3);
        bool  hoverResursesP4 = CheckCollisionPointRec(mousePoint, resusrsesP4);
        bool  hoverResursesP5 = CheckCollisionPointRec(mousePoint, resusrsesP5);
        bool hoverSubMathText = CheckCollisionPointRec(mousePoint, subMathSection);
        bool hoverSubMathTextHw = CheckCollisionPointRec(mousePoint, subMathSectionHw);
        bool hoverSubMathTextTest = CheckCollisionPointRec(mousePoint, subMathSectionTest);
        bool hoverHwPracticeRect = CheckCollisionPointRec(mousePoint, hwPracticeRect);
        bool hoverExPracticeRect = CheckCollisionPointRec(mousePoint, exPracticeRect);
        Color hwPracticeRectColor = hoverHwPracticeRect && currentPage != exercises ? eduBlue : currentPage == exercises ? eduTurquoise : subSectionsBg;
        Color exPracticeRectColor = hoverExPracticeRect && currentPage != exPractice ? eduBlue : currentPage == exPractice ? eduTurquoise : subSectionsBg;
        Color hoverSubTextColor = hoverSubMathText ? LIGHTGRAY : GRAY;
        Color hoverSubTextColorHw = hoverSubMathTextHw ? LIGHTGRAY : GRAY;
        Color hoverSubTextColorTest = hoverSubMathTextTest ? LIGHTGRAY : GRAY;
        Color backBtnColor = hoverBack ? eduBlue : subSectionsBg;
        Color resursesColorP1 = hoverResursesP1 ? eduBlue : subSectionsBg;
        Color resursesColorP2 = hoverResursesP2 ? eduBlue : subSectionsBg;
        Color resursesColorP3 = hoverResursesP3 ? eduBlue : subSectionsBg;
        Color resursesColorP4 = hoverResursesP4 ? eduBlue : subSectionsBg;
        Color resursesColorP5 = hoverResursesP5 ? eduBlue : subSectionsBg;
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
            DrawText("LEARNING RESOURCES", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("Study Material Navigation Guide", 50, (int)(separationLineY + 50.0f), 30, eduBlue);
            DrawText("Select a numbered tab below to access theory and examples:", 50, (int)(separationLineY + 90.0f), 24, RAYWHITE);
            DrawText("Tab 1: Product Equations", 100, (int)(separationLineY + 150.0f), 25, eduOrange);
            DrawText("- Learn how to solve (ax + b)(cx + d) = 0 using zero-product property.", 450, (int)(separationLineY + 150.0f), 22, RAYWHITE);
            DrawText("Tab 2: Linear Equations", 100, (int)(separationLineY + 190.0f), 25, eduOrange);
            DrawText("- Basic rules and steps for solving first-degree equations.", 450, (int)(separationLineY + 190.0f), 22, RAYWHITE);
            DrawText("Tab 3: Quadratic Equations", 100, (int)(separationLineY + 230.0f), 25, eduOrange);
            DrawText("- Comprehensive guide for ax^2 + bx + c = 0 solving methods.", 450, (int)(separationLineY + 230.0f), 22, RAYWHITE);
            DrawText("Tab 4: Homogeneous", 100, (int)(separationLineY + 270.0f), 25, eduOrange);
            DrawText("- Deep dive into advanced same-degree polynomial equations.", 450, (int)(separationLineY + 270.0f), 22, RAYWHITE);
            DrawText("Tab 5: Quick Summary", 100, (int)(separationLineY + 310.0f), 25, eduOrange);
            DrawText("- Formulas, cheat sheets, and essential math properties.", 450, (int)(separationLineY + 310.0f), 22, RAYWHITE);
            DrawText("Tip: Review each section carefully before starting your homework!", 50, (int)(separationLineY + 380.0f), 20, eduTurquoise);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, resursesColorP1);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, resursesColorP2);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, resursesColorP3);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, resursesColorP4);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, resursesColorP5);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);
            break;

        case resursesTab1:
            DrawText("(ax+b)(cx+d)=0 ", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("TOPIC: Zero-Product Property", 70, (int)separationLineY + 60, 35, eduBlue);
            DrawText("Concept: If the product of two factors is 0, at least one must be 0.", 70, (int)separationLineY + 110, 22, eduTurquoise);
            DrawText("Formula: (ax + b) = 0  OR  (cx + d) = 0", 70, (int)separationLineY + 140, 24, RAYWHITE);
            DrawText("Example 1: (x - 5)(x + 3) = 0", 70, (int)separationLineY + 200, 24, RAYWHITE);
            DrawText("Solution: x1 = 5, x2 = -3", 450, (int)separationLineY + 200, 24, eduOrange);
            DrawText("Example 2: (2x - 8)(5x + 10) = 0", 70, (int)separationLineY + 240, 24, RAYWHITE);
            DrawText("Solution: x1 = 4, x2 = -2", 450, (int)separationLineY + 240, 24, eduOrange);
            DrawText("Example 3: (4x - 1)(x - 0.5) = 0", 70, (int)separationLineY + 280, 24, RAYWHITE);
            DrawText("Solution: x1 = 0.25, x2 = 0.5", 450, (int)separationLineY + 280, 24, eduOrange);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, eduTurquoise);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, resursesColorP2);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, resursesColorP3);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, resursesColorP4);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, resursesColorP5);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);

            break;


        case resursesTab2:
            DrawText("LINEAR EQUATIONS", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("TOPIC: Solving First-Degree Equations", 70, (int)separationLineY + 60, 35, eduBlue);
            DrawText("Concept: Move variables to one side and constants to the other.", 70, (int)separationLineY + 110, 22, RAYWHITE);
            DrawText("General Form: ax + b = 0  =>  x = -b / a", 70, (int)separationLineY + 140, 24, eduTurquoise);
            DrawText("Example 1: 3x - 12 = 0", 70, (int)separationLineY + 200, 25, RAYWHITE);
            DrawText("Solution: 3x = 12  =>  x = 4", 450, (int)separationLineY + 200, 25, eduOrange);
            DrawText("Example 2: 5x + 10 = 2x + 25", 70, (int)separationLineY + 245, 25, RAYWHITE);
            DrawText("Solution: 3x = 15  =>  x = 5", 450, (int)separationLineY + 245, 25, eduOrange);
            DrawText("Example 3: 2(x - 3) = 10", 70, (int)separationLineY + 290, 25, RAYWHITE);
            DrawText("Solution: 2x - 6 = 10 => 2x = 16 => x = 8", 450, (int)separationLineY + 290, 25, eduOrange);
            DrawText("Remember: Change the sign (+ or -) when moving terms across the '=' sign!", 70, (int)separationLineY + 360, 20, eduTurquoise);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, resursesColorP1);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, eduTurquoise);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, resursesColorP3);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, resursesColorP4);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, resursesColorP5);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);

            break;


        case resursesTab3:
            DrawText("QUADRATIC EQUATIONS", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("TOPIC: Solving ax^2 + bx + c = 0", 70, (int)separationLineY + 60, 35, eduBlue);
            DrawText("Concept: Use the Discriminant (D) to find the number of real roots.", 70, (int)separationLineY + 110, 22, RAYWHITE);
            DrawText("Formula: D = b^2 - 4ac", 70, (int)separationLineY + 145, 26, eduTurquoise);
            DrawText("Roots: x = (-b +/- sqrt(D)) / 2a", 450, (int)separationLineY + 145, 26, eduTurquoise);
            DrawText("Example 1: x^2 - 5x + 6 = 0", 70, (int)separationLineY + 210, 25, RAYWHITE);
            DrawText("D = 1  =>  x1 = 3, x2 = 2", 500, (int)separationLineY + 210, 25, eduOrange);
            DrawText("Example 2: x^2 - 4x + 4 = 0", 70, (int)separationLineY + 255, 25, RAYWHITE);
            DrawText("D = 0  =>  x = 2 (Double root)", 500, (int)separationLineY + 255, 25, eduOrange);
            DrawText("Example 3: x^2 + 2x + 5 = 0", 70, (int)separationLineY + 300, 25, RAYWHITE);
            DrawText("D = -16 => No real solutions", 500, (int)separationLineY + 300, 25, eduOrange);
            DrawText("Tip: If D > 0 (2 roots), If D = 0 (1 root), If D < 0 (No real roots).", 70, (int)separationLineY + 370, 22, eduTurquoise);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, resursesColorP1);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, resursesColorP2);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, eduTurquoise);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, resursesColorP4);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, resursesColorP5);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);

			break;

        case resursesTab4: 
            DrawText("HOMOGENEOUS EQUATIONS", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("TOPIC: Equations with Constant Degree", 70, (int)separationLineY + 60, 35, eduBlue);
            DrawText("Concept: Every term has the same total power. Solve by substitution.", 70, (int)separationLineY + 110, 22, RAYWHITE);
            DrawText("Standard Form: ax^2 + bxy + cy^2 = 0", 70, (int)separationLineY + 145, 26, eduTurquoise);
            DrawText("Method: Divide by y^2 and let u = x/y", 550, (int)separationLineY + 145, 26, eduTurquoise);
            DrawText("Example 1: x^2 - 3xy + 2y^2 = 0", 70, (int)separationLineY + 210, 25, RAYWHITE);
            DrawText("Divide by y^2 => u^2 - 3u + 2 = 0", 500, (int)separationLineY + 210, 25, eduOrange);
            DrawText("Example 2: Solve for u (u = x/y)", 70, (int)separationLineY + 255, 25, RAYWHITE);
            DrawText("u1 = 1, u2 = 2  =>  x = y, x = 2y", 500, (int)separationLineY + 255, 25, eduOrange);
            DrawText("Example 3: 4x - 5y = 0", 70, (int)separationLineY + 300, 25, RAYWHITE);
            DrawText("x/y = 5/4  =>  Linear Homogeneous", 500, (int)separationLineY + 300, 25, eduOrange);
            DrawText("Tip: These equations describe lines passing through the origin (0,0).", 70, (int)separationLineY + 370, 22, eduTurquoise);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, resursesColorP1);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, resursesColorP2);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, resursesColorP3);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, eduTurquoise);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, resursesColorP5);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);

            break;

        case resursesTab5: 
            DrawText("MATH QUICK SUMMARY", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);
            DrawText("CHEAT SHEET: Essential Formulas", 70, (int)separationLineY + 60, 35, eduBlue);
            DrawText("1. Linear & Product Type:", 70, (int)separationLineY + 120, 26, eduTurquoise);
            DrawText("- ax + b = 0  =>  x = -b / a", 100, (int)separationLineY + 155, 24, RAYWHITE);
            DrawText("- (ax+b)(cx+d) = 0  =>  Solve each factor for 0.", 100, (int)separationLineY + 185, 24, RAYWHITE);
            DrawText("2. Quadratic Equations (ax^2 + bx + c = 0):", 70, (int)separationLineY + 230, 26, eduTurquoise);
            DrawText("- Discriminant: D = b^2 - 4ac", 100, (int)separationLineY + 265, 24, RAYWHITE);
            DrawText("- If D > 0: 2 Roots | If D = 0: 1 Root | If D < 0: No Real Roots", 100, (int)separationLineY + 295, 22, eduOrange);
            DrawText("3. Homogeneous Type:", 70, (int)separationLineY + 340, 26, eduTurquoise);
            DrawText("- ax^2 + bxy + cy^2 = 0  =>  Divide by y^2, substitute u = x/y.", 100, (int)separationLineY + 375, 24, RAYWHITE);
            DrawText("Use these rules as a guide for your Practice and Homework sections!", 70, (int)separationLineY + 430, 20, eduTurquoise);
            DrawRectangleRounded({ resusrsesP1 }, 0.1f, 10, resursesColorP1);
            DrawText("1", (int)resusrsesP1.x + 20, (int)resusrsesP1.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP2 }, 0.1f, 10, resursesColorP2);
            DrawText("2", (int)resusrsesP2.x + 20, (int)resusrsesP2.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP3 }, 0.1f, 10, resursesColorP3);
            DrawText("3", (int)resusrsesP3.x + 20, (int)resusrsesP3.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP4 }, 0.1f, 10, resursesColorP4);
            DrawText("4", (int)resusrsesP4.x + 20, (int)resusrsesP4.y + 10, 25, RAYWHITE);
            DrawRectangleRounded({ resusrsesP5 }, 0.1f, 10, eduTurquoise);
            DrawText("5", (int)resusrsesP5.x + 20, (int)resusrsesP5.y + 10, 25, RAYWHITE);
            break;

        case exercises:
            DrawText("Maths Homework and Practice", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(hwPracticeRect, 0.5f, 10, hwPracticeRectColor);
            DrawText("Homework", (int)(hwPracticeRect.x + 40.0f), (int)(hwPracticeRect.y + 10.0f), 25, RAYWHITE);
            DrawRectangleRounded(exPracticeRect, 0.5f, 10, exPracticeRectColor);
            DrawText("Practice", (int)(exPracticeRect.x + 50.0f), (int)(exPracticeRect.y + 10.0f), 25, RAYWHITE);

            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);


            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);

            DrawText("1. Linear Equations", 50, (int)(separationLineY + 50.0f), 30, eduBlue);
            DrawText("Problem 1: 4x - 12 = 2x + 6", 50, (int)(separationLineY + 90.0f), 25, RAYWHITE);
            DrawText("Answer: x = 9", 50, (int)(separationLineY + 120), 20, eduOrange);

            DrawText("Problem 2: 5(x - 2) = 3x + 4", 550, (int)(separationLineY + 90.0f), 25, RAYWHITE);
            DrawText("Answer: x = 7", 550, (int)(separationLineY + 120), 20, eduOrange);

            DrawText("2. Product of Linear Factors: (ax+b)*(cx+d)=0", 50, (int)(separationLineY + 160.0f), 30, eduBlue);
            DrawText("Problem 1: (x - 5)*(2x + 8) = 0", 50, (int)(separationLineY + 200.0f), 25, RAYWHITE);
            DrawText("Answer: x_1 = 5;  x_2 = -4", 50, (int)(separationLineY + 230), 20, eduOrange);

            DrawText("Problem 2: (3x - 9)*(x + 7) = 0", 550, (int)(separationLineY + 200.0f), 25, RAYWHITE);
            DrawText("Answer: x_1 = 3;  x_2 = -7", 550, (int)(separationLineY + 230), 20, eduOrange);

            DrawText("3. Quadratic Equations", 50, (int)(separationLineY + 270.0f), 30, eduBlue);
            DrawText("Problem 1: x^2 - 5x + 6 = 0", 50, (int)(separationLineY + 310.0f), 25, RAYWHITE);
            DrawText("Answer: x_1 = 2, x_2 = 3", 50, (int)(separationLineY + 340), 20, eduOrange);

            DrawText("Problem 2: x^2 + 2x - 8 = 0", 550, (int)(separationLineY + 310.0f), 25, RAYWHITE);
            DrawText("Answer: x_1 = 2, x_2 = -4", 550, (int)(separationLineY + 340), 20, eduOrange);

            DrawText("4. Homogeneous Equations", 50, (int)(separationLineY + 380.0f), 30, eduBlue);
            DrawText("Problem 1: 2x^2 - 5xy + 2y^2 = 0", 50, (int)(separationLineY + 420.0f), 25, RAYWHITE);
            DrawText("Answer: x = 2y or x = 0.5y", 50, (int)(separationLineY + 450), 20, eduOrange);

            DrawText("Problem 2: x^2 + xy - 6y^2 = 0", 550, (int)(separationLineY + 420.0f), 25, RAYWHITE);
            DrawText("Answer: x = 2y or x = -3y", 550, (int)(separationLineY + 450), 20, eduOrange);
            break;

        case exPractice:
            DrawText("Maths Homework and Practice", 20, 70, 70, eduTurquoise);
            DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);

            DrawRectangleRounded(hwPracticeRect, 0.5f, 10, hwPracticeRectColor);
            DrawText("Homework", (int)(hwPracticeRect.x + 40.0f), (int)(hwPracticeRect.y + 10.0f), 25, RAYWHITE);
            DrawRectangleRounded(exPracticeRect, 0.5f, 10, exPracticeRectColor);
            DrawText("Practice", (int)(exPracticeRect.x + 50.0f), (int)(exPracticeRect.y + 10.0f), 25, RAYWHITE);

            DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
            DrawTexture(texture, 1150, 10, WHITE);
            DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);


            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            // Главният контейнер за теста
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f , mainSectionHeight }, 0.1f, 10, subSectionsBg);

            // --- ЛОГИКА ЗА ТЕСТА (ВЪТРЕ В КОНТЕЙНЕРА) ---
            float testStartY = separationLineY + 60.0f; // Малко разстояние от горния ръб на кутията

            // 1. Изписване на въпроса
            DrawText(TextFormat("Question %d/10", currentQ + 1), 70, (int)testStartY, 25, eduOrange);
            DrawText(practiceQuiz[currentQ].text, 70, (int)(testStartY + 40), 35, RAYWHITE);

            // 2. Бутони за отговори (А, B, C)
            for (int i = 0; i < 3; i++) {
                // Позиционираме ги един под друг
                Rectangle ansRect = { 70.0f, testStartY + 120.0f + (i * 70.0f), 500.0f, 55.0f };
                Color boxColor = ColorAlpha(eduBlue, 0.2f); // По-тъмен фон за бутоните по подразбиране

                if (selectedAns != -1) {
                    // Вече е кликнато - показваме резултат
                    if (i == practiceQuiz[currentQ].correct) boxColor = eduGreen;
                    else if (i == selectedAns) boxColor = eduRed;
                }
                else if (CheckCollisionPointRec(mousePoint, ansRect)) {
                    boxColor = eduTurquoise; // Свети при ховър
                    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) selectedAns = i;
                }

                DrawRectangleRounded(ansRect, 0.2f, 10, boxColor);
                DrawRectangleRoundedLines(ansRect, 0.2f, 10, sectionOutlines);

                // Префикс A), B), C)
                const char* prefix = (i == 0) ? "A) " : (i == 1) ? "B) " : "C) ";
                DrawText(TextFormat("%s %s", prefix, practiceQuiz[currentQ].answers[i]),
                    (int)ansRect.x + 20, (int)ansRect.y + 15, 22, RAYWHITE);
            }

            // 3. Бутон за следващ въпрос
            if (selectedAns != -1) {
                Rectangle nextBtn = { 1100, separationLineY + 450, 200, 50 };
                bool hoverNext = CheckCollisionPointRec(mousePoint, nextBtn);

                DrawRectangleRounded(nextBtn, 0.2f, 10, hoverNext ? eduOrange : DARKGRAY);
                DrawText(currentQ < 9 ? "Next Question >" : "Finish Test", (int)nextBtn.x + 25, (int)nextBtn.y + 15, 20, RAYWHITE);

                if (hoverNext && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    if (currentQ < 9) {
                        currentQ++;
                        selectedAns = -1;
                    }
                    else {
                        currentPage = exercises; // Връщаме го в главното меню след края
                        currentQ = 0; // Рестартираме за следващия път
                        selectedAns = -1;
                    }
                }
            }
            break;
        }

        EndDrawing();
    }
    UnloadTexture(texture);
    CloseWindow();
    return 0;
}