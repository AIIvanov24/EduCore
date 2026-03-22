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



    shuffleTest(); // initialise on startup

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

        // Draw exit button on every page
        auto drawExitBtn = [&]() {

            DrawRectangleRounded(exitButtonRect, 0.3f, 10, exitBg);
            DrawRectangleRoundedLines(exitButtonRect, 0.3f, 10, { 220, 50, 50, 255 });
            DrawText("   Exit", (int)(exitButtonRect.x + 12), (int)(exitButtonRect.y + 13), 24, RAYWHITE);
            };

        switch (currentPage) {

        case homePage:
			drawHomePage();
            break;

        case mathPage:
			drawMathPage();
            break;

        case test: {
            drawTestPage();
        } break;

                 // ══════════════════════════════════════════
        case testResults: {
            DrawText("Maths Test", 20, 70, 70, eduTurquoise);
            DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
            DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
            DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);

            // Grade formula: grade = (score / total * 100) * 0.06, clamped [2, 6]
            float pct = (float)testScore / TEST_SIZE * 100.0f;
            float numGrade = pct * 0.06f;
            if (numGrade < 2.0f) numGrade = 2.0f;
            if (numGrade > 6.0f) numGrade = 6.0f;
            Color gradeColor = numGrade >= 4.8f ? eduGreen : numGrade >= 3.6f ? eduOrange : eduRed;

            // Results card
            Rectangle resCard = { 300.0f, separationLineY + 40.0f, 800.0f, 270.0f };
            DrawRectangleRounded(resCard, 0.1f, 10, mainBackground);
            DrawRectangleRoundedLines(resCard, 0.1f, 10, eduTurquoise);

            // Title
            int titleW = MeasureText("Test Complete!", 45);
            DrawText("Test Complete!", (int)(resCard.x + (resCard.width - titleW) / 2), (int)(resCard.y + 20), 45, RAYWHITE);

            // Score line
            char scoreBuf[64];
            snprintf(scoreBuf, sizeof(scoreBuf), "Score:  %d / %d   (%.0f%%)", testScore, TEST_SIZE, pct);
            int scoreW = MeasureText(scoreBuf, 28);
            DrawText(scoreBuf, (int)(resCard.x + (resCard.width - scoreW) / 2), (int)(resCard.y + 90), 28, LIGHTGRAY);

            // Grade (large, coloured)
            char gradeBuf[32];
            snprintf(gradeBuf, sizeof(gradeBuf), "Grade:  %.2f / 6.00", numGrade);
            int gradeW = MeasureText(gradeBuf, 50);
            DrawText(gradeBuf, (int)(resCard.x + (resCard.width - gradeW) / 2), (int)(resCard.y + 140), 50, gradeColor);

            // Motivational message
            const char* msg = numGrade >= 5.4f ? "Excellent! Outstanding performance!"
                : numGrade >= 4.2f ? "Good job! Keep practising!"
                : numGrade >= 3.0f ? "Not bad. Review the materials and try again."
                : "Keep going - practice makes perfect!";
            int msgW = MeasureText(msg, 22);
            DrawText(msg, (int)(resCard.x + (resCard.width - msgW) / 2), (int)(resCard.y + 220), 22, GRAY);

            // Retry / Back buttons
            Rectangle retryBtn = { 500, separationLineY + 320, 200, 55 };
            Rectangle backBtn2 = { 720, separationLineY + 320, 200, 55 };
            bool hoverRetry = CheckCollisionPointRec(mousePoint, retryBtn);
            bool hoverBack2 = CheckCollisionPointRec(mousePoint, backBtn2);
            DrawRectangleRounded(retryBtn, 0.3f, 10, hoverRetry ? eduTurquoise : subSectionsBg);
            DrawRectangleRoundedLines(retryBtn, 0.3f, 10, eduTurquoise);
            DrawText("Try Again", (int)(retryBtn.x + 35), (int)(retryBtn.y + 15), 24, RAYWHITE);
            DrawRectangleRounded(backBtn2, 0.3f, 10, hoverBack2 ? eduBlue : subSectionsBg);
            DrawRectangleRoundedLines(backBtn2, 0.3f, 10, sectionOutlines);
            DrawText("Back to Maths", (int)(backBtn2.x + 15), (int)(backBtn2.y + 15), 22, RAYWHITE);
        } break;

        case materials:
			drawMaterialsPage();
            break;

        case resursesTab1:
			drawResursesTab1();
            break;

        case resursesTab2:
            drawResursesTab2();
            break;

        case resursesTab3:
            drawResursesTab3();
            break;

        case resursesTab4:
            drawResursesTab4();
            break;

        case resursesTab5:
            drawResursesTab5();
            break;

        case exercises:
            drawExercisesPage();
            break;

        case exPractice:
            drawExPractice(mousePoint);
            break;

        case gradebookPage: {
            drawGradebookPage();
        } break;

        }

        EndDrawing();
    }

    UnloadTexture(texture);
    CloseWindow();
    return 0;
}