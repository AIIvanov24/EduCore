#include "header.h"

auto drawExitBtn = [&]() {

    DrawRectangleRounded(exitButtonRect, 0.3f, 10, exitBg);
    DrawRectangleRoundedLines(exitButtonRect, 0.3f, 10, { 220, 50, 50, 255 });
    DrawText("   Exit", (int)(exitButtonRect.x + 12), (int)(exitButtonRect.y + 13), 24, RAYWHITE);
    };

void drawExPractice(Vector2 mousePoint) {
    DrawText("Maths Homework and Practice", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRounded(hwPracticeRect, 0.5f, 10, hwPracticeRectColor);
    DrawText("Homework", (int)(hwPracticeRect.x + 40.0f), (int)(hwPracticeRect.y + 10.0f), 25, RAYWHITE);
    DrawRectangleRounded(exPracticeRect, 0.5f, 10, exPracticeRectColor);
    DrawText("Practice", (int)(exPracticeRect.x + 50.0f), (int)(exPracticeRect.y + 10.0f), 25, RAYWHITE);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);

    float testStartY = separationLineY + 60.0f;
    DrawText(TextFormat("Question %d/10", currentQ + 1), 70, (int)testStartY, 25, eduOrange);
    DrawText(practiceQuiz[currentQ].text, 70, (int)(testStartY + 40), 35, RAYWHITE);

    for (int i = 0; i < 3; i++) {
        Rectangle ansRect = { 70.0f, testStartY + 120.0f + (i * 70.0f), 500.0f, 55.0f };
        Color boxColor = ColorAlpha(eduBlue, 0.2f);
        if (selectedAns != -1) {
            if (i == practiceQuiz[currentQ].correct) boxColor = eduGreen;
            else if (i == selectedAns)               boxColor = eduRed;
        }
        else if (CheckCollisionPointRec(mousePoint, ansRect)) {
            boxColor = eduTurquoise;
        }
        DrawRectangleRounded(ansRect, 0.2f, 10, boxColor);
        DrawRectangleRoundedLines(ansRect, 0.2f, 10, sectionOutlines);
        const char* prefix = (i == 0) ? "A)  " : (i == 1) ? "B)  " : "C)  ";
        DrawText(TextFormat("%s %s", prefix, practiceQuiz[currentQ].answers[i]),
            (int)ansRect.x + 20, (int)ansRect.y + 15, 22, RAYWHITE);
    }

    if (selectedAns != -1) {
        Rectangle nextBtn = { 1100, separationLineY + 450, 200, 50 };
        bool hoverNext = CheckCollisionPointRec(mousePoint, nextBtn);
        DrawRectangleRounded(nextBtn, 0.2f, 10, hoverNext ? eduOrange : DARKGRAY);
        DrawText(currentQ < 9 ? "Next Question >" : "Finish Practice",
            (int)nextBtn.x + 15, (int)nextBtn.y + 15, 20, RAYWHITE);
    }
}