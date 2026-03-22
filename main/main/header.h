#pragma once

#include "raylib.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>

// State enumeration for the different pages of the application
enum appState {
    homePage, mathPage, exercises, test, testResults, materials,
    resursesTab1, resursesTab2, resursesTab3, resursesTab4, resursesTab5, exPractice,
    gradebookPage
};

struct TestResult {
    int score;
    int total;
    float grade;
    float pct;
    char date[16];
};

struct Question {
    const char* text;
    const char* answers[3];
    int correct;
};

// Global constants
const int MAX_RESULTS = 20;
const int BANK_SIZE = 30;
const int TEST_SIZE = 20;

// Declarations of global variables (defined in variables.cpp)
extern appState currentPage;
extern Color eduBlue, eduOrange, mainBackground, subSectionsBg, sectionOutlines, eduTurquoise, eduGreen, eduRed;
extern float spacing, separationLineY, mainSectionHeight, mainSectionY, centerX, labelHeight;
extern Rectangle backButtonRect, exitButtonRect, subMathSection, subMathSectionHw, subMathSectionTest;
extern Rectangle subMathSectionLabel, mathSection, resusrsesP1, resusrsesP2, resusrsesP3, resusrsesP4, resusrsesP5;
extern Rectangle hwPracticeRect, exPracticeRect, labelRect, gradebookBtn;

extern TestResult gradebook[MAX_RESULTS];
extern int gradebookCount;
extern Question practiceQuiz[10];
extern Question testBank[BANK_SIZE];

extern int currentQ, selectedAns;
extern int testOrder[TEST_SIZE], testCurrentQ, testSelectedAns, testScore;
extern bool testAnswered;
extern int answerOrder[TEST_SIZE][3], shuffledCorrect[TEST_SIZE];
extern Texture2D texture;

extern bool hoverGradebookBtn, hoverBack, hoverExit;
extern bool hoverResursesP1, hoverResursesP2, hoverResursesP3, hoverResursesP4, hoverResursesP5;
extern bool hoverSubMathText, hoverSubMathTextHw, hoverSubMathTextTest;
extern bool hoverHwPracticeRect, hoverExPracticeRect;

extern Color hwPracticeRectColor, exPracticeRectColor;
extern Color hoverSubTextColor, hoverSubTextColorHw, hoverSubTextColorTest;
extern Color backBtnColor;
extern Color resursesColorP1, resursesColorP2, resursesColorP3, resursesColorP4, resursesColorP5;
extern Color exitBg;

// Functions
void getDateStr(char* buf);

void shuffleTest();
void handleInput(Vector2 mousePoint);

void computeHover(Vector2 mousePoint);
void drawExPractice(Vector2 mousePoint);
void drawHomePage(Vector2 mousePoint);
void drawMathPage(Vector2 mousePoint);
void drawMaterialsPage(Vector2 mousePoint);
void drawResursesTab1(Vector2 mousePoint);
void drawResursesTab2(Vector2 mousePoint);
void drawResursesTab3(Vector2 mousePoint);
void drawResursesTab4(Vector2 mousePoint);
void drawResursesTab5(Vector2 mousePoint);
void drawExercisesPage(Vector2 mousePoint);
void drawGradebookPage(Vector2 mousePoint);
void drawTestPage(Vector2 mousePoint);
void drawExitBtn(Vector2 mousePoint);
void drawTestResultsPage(Vector2 mousePoint);   