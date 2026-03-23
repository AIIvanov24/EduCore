#include "header.h"

int main() {
    InitWindow(1400, 800, "EduCore Education");
    SetTargetFPS(60);
    srand((unsigned int)time(nullptr));
    mainSectionHeight = (float)GetScreenHeight() - separationLineY - spacing * 2.0f;
    mainSectionY = separationLineY + spacing;

    int subjectTextWidth = MeasureText("Please choose a subject", 30);
    centerX = 40.0f + (1320.0f / 2.0f) - (subjectTextWidth / 2.0f);


    subMathSection = { 74.0f, mainSectionY + 5.0f * spacing, 390.0f, 290.0f };
    subMathSectionHw = { subMathSection.x + 390.0f + spacing * 2.0f, subMathSection.y, subMathSection.width, subMathSection.height };
    subMathSectionTest = { subMathSection.x + 390.0f * 2.0f + spacing * 4.0f, subMathSection.y, subMathSection.width, subMathSection.height };
    subMathSectionLabel = { subMathSection.x - 2.0f, subMathSection.y - 1.0f, subMathSection.width + 3.0f, 40.0f };

    mathSection = { 80.0f, mainSectionY + 5.0f * spacing, 1320.0f - 80.0f, 200.0f };
    labelRect = { mathSection.x - 2.0f, mathSection.y - 1.0f, mathSection.width + 3.0f, labelHeight };
    gradebookBtn = { 80.0f, mainSectionY + 5.0f * spacing + 200.0f + 20.0f, 400.0f, 55.0f };

    Image logoImg = LoadImage("eduCoreLogo.png");
    if (logoImg.data != nullptr) {
        ImageResize(&logoImg, 200, 200);
        texture = LoadTextureFromImage(logoImg);
        UnloadImage(logoImg);
    }



    shuffleTest();

    //  MAIN LOOP
    while (!WindowShouldClose()) {
        Vector2 mousePoint = GetMousePosition();
        // ── Exit button — works on every page ────
        if (CheckCollisionPointRec(mousePoint, exitButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
            break; // exits the while loop >> closes app
        }

        // ── INPUT ────────────────────────────────
        handleInput(mousePoint);

        // ── HOVER / COLOUR HELPERS ───────────────
        computeHover(mousePoint);

        // ── DRAW ─────────────────────────────────
        BeginDrawing();
        ClearBackground(mainBackground);

        switch (currentPage) {

        case homePage:
			drawHomePage(mousePoint);
            break;

        case mathPage:
			drawMathPage(mousePoint);
            break;

        case test: {
            drawTestPage(mousePoint);
        } break;

        case testResults: {
			drawTestResultsPage(mousePoint);
        } break;

        case materials:
			drawMaterialsPage(mousePoint);
            break;

        case resursesTab1:
			drawResursesTab1(mousePoint);
            break;

        case resursesTab2:
            drawResursesTab2(mousePoint);
            break;

        case resursesTab3:
            drawResursesTab3(mousePoint);
            break;

        case resursesTab4:
            drawResursesTab4(mousePoint);
            break;

        case resursesTab5:
            drawResursesTab5(mousePoint);
            break;

        case exercises:
            drawExercisesPage(mousePoint);
            break;

        case exPractice:
            drawExPractice(mousePoint);
            break;

        case gradebookPage: {
            drawGradebookPage(mousePoint);
        } break;

        }

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}