#include "header.h"

void shuffleTest() {
    int pool[BANK_SIZE];
    for (int i = 0; i < BANK_SIZE; i++) pool[i] = i;
    for (int i = BANK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int tmp = pool[i]; pool[i] = pool[j]; pool[j] = tmp;
    }
    for (int i = 0; i < TEST_SIZE; i++) testOrder[i] = pool[i];

    for (int i = 0; i < TEST_SIZE; i++) {
        int orig = testBank[testOrder[i]].correct;
        answerOrder[i][0] = 0; answerOrder[i][1] = 1; answerOrder[i][2] = 2;
        for (int k = 2; k > 0; k--) {
            int r = rand() % (k + 1);
            int tmp2 = answerOrder[i][k];
            answerOrder[i][k] = answerOrder[i][r];
            answerOrder[i][r] = tmp2;
        }
        for (int k = 0; k < 3; k++) {
            if (answerOrder[i][k] == orig) { shuffledCorrect[i] = k; break; }
        }
    }
    testCurrentQ = 0;
    testSelectedAns = -1;
    testScore = 0;
    testAnswered = false;
}

void handleInput(Vector2 mousePoint) {
    switch (currentPage) {

    case homePage:
        if (CheckCollisionPointRec(mousePoint, mathSection) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            currentPage = mathPage;
        if (CheckCollisionPointRec(mousePoint, gradebookBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            currentPage = gradebookPage;
        break;

    case mathPage:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = homePage;
        if (CheckCollisionPointRec(mousePoint, subMathSectionTest) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { shuffleTest(); currentPage = test; }
        if (CheckCollisionPointRec(mousePoint, subMathSection) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, subMathSectionHw) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = exercises;
        break;

    case test: {
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { currentPage = mathPage; break; }
        Question& q = testBank[testOrder[testCurrentQ]];
        float testStartY = separationLineY + 60.0f;
        if (!testAnswered) {
            for (int i = 0; i < 3; i++) {
                Rectangle ansRect = { 70.0f, testStartY + 125.0f + (i * 72.0f), 700.0f, 58.0f };
                if (CheckCollisionPointRec(mousePoint, ansRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                    testSelectedAns = i;
                    testAnswered = true;
                    if (i == shuffledCorrect[testCurrentQ]) testScore++;
                }
            }
        }
        else {
            Rectangle nextBtn = { 1100, separationLineY + 450, 200, 50 };
            if (CheckCollisionPointRec(mousePoint, nextBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (testCurrentQ < TEST_SIZE - 1) {
                    testCurrentQ++;
                    testSelectedAns = -1;
                    testAnswered = false;
                }
                else {
                    if (gradebookCount < MAX_RESULTS) {
                        float p = (float)testScore / TEST_SIZE * 100.0f;
                        float g = p * 0.06f;
                        if (g < 2.0f) g = 2.0f;
                        if (g > 6.0f) g = 6.0f;
                        gradebook[gradebookCount].score = testScore;
                        gradebook[gradebookCount].total = TEST_SIZE;
                        gradebook[gradebookCount].pct = p;
                        gradebook[gradebookCount].grade = g;
                        getDateStr(gradebook[gradebookCount].date);
                        gradebookCount++;
                    }
                    currentPage = testResults;
                }
            }
        }
    } break;

    case testResults: {
        Rectangle retryBtn = { 500, separationLineY + 320, 200, 55 };
        Rectangle backBtn2 = { 720, separationLineY + 320, 200, 55 };
        if (CheckCollisionPointRec(mousePoint, retryBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { shuffleTest(); currentPage = test; }
        if (CheckCollisionPointRec(mousePoint, backBtn2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = mathPage;
    } break;

    case materials:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = mathPage;
        if (CheckCollisionPointRec(mousePoint, resusrsesP1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab1;
        if (CheckCollisionPointRec(mousePoint, resusrsesP2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab2;
        if (CheckCollisionPointRec(mousePoint, resusrsesP3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab3;
        if (CheckCollisionPointRec(mousePoint, resusrsesP4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab4;
        if (CheckCollisionPointRec(mousePoint, resusrsesP5) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab5;
        break;

    case resursesTab1:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, resusrsesP2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab2;
        if (CheckCollisionPointRec(mousePoint, resusrsesP3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab3;
        if (CheckCollisionPointRec(mousePoint, resusrsesP4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab4;
        if (CheckCollisionPointRec(mousePoint, resusrsesP5) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab5;
        break;

    case resursesTab2:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, resusrsesP1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab1;
        if (CheckCollisionPointRec(mousePoint, resusrsesP3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab3;
        if (CheckCollisionPointRec(mousePoint, resusrsesP4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab4;
        if (CheckCollisionPointRec(mousePoint, resusrsesP5) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab5;
        break;

    case resursesTab3:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, resusrsesP1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab1;
        if (CheckCollisionPointRec(mousePoint, resusrsesP2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab2;
        if (CheckCollisionPointRec(mousePoint, resusrsesP4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab4;
        if (CheckCollisionPointRec(mousePoint, resusrsesP5) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab5;
        break;

    case resursesTab4:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, resusrsesP1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab1;
        if (CheckCollisionPointRec(mousePoint, resusrsesP2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab2;
        if (CheckCollisionPointRec(mousePoint, resusrsesP3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab3;
        if (CheckCollisionPointRec(mousePoint, resusrsesP5) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab5;
        break;

    case resursesTab5:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = materials;
        if (CheckCollisionPointRec(mousePoint, resusrsesP1) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab1;
        if (CheckCollisionPointRec(mousePoint, resusrsesP2) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab2;
        if (CheckCollisionPointRec(mousePoint, resusrsesP3) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab3;
        if (CheckCollisionPointRec(mousePoint, resusrsesP4) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = resursesTab4;
        break;

    case exercises:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = mathPage;
        if (CheckCollisionPointRec(mousePoint, exPracticeRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) currentPage = exPractice;
        break;

    case exPractice: {
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { currentPage = mathPage; break; }
        if (CheckCollisionPointRec(mousePoint, hwPracticeRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) { currentPage = exercises; break; }
        if (selectedAns == -1) {
            float testStartY = separationLineY + 60.0f;
            for (int i = 0; i < 3; i++) {
                Rectangle ansRect = { 70.0f, testStartY + 120.0f + (i * 70.0f), 500.0f, 55.0f };
                if (CheckCollisionPointRec(mousePoint, ansRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                    selectedAns = i;
            }
        }
        else {
            Rectangle nextBtn = { 1100, separationLineY + 450, 200, 50 };
            if (CheckCollisionPointRec(mousePoint, nextBtn) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                if (currentQ < 9) { currentQ++; selectedAns = -1; }
                else { currentPage = exercises; currentQ = 0; selectedAns = -1; }
            }
        }
    } break;

    case gradebookPage:
        if (CheckCollisionPointRec(mousePoint, backButtonRect) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            currentPage = homePage;
        break;
    }
}