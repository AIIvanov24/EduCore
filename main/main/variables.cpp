#include "header.h"

// 1. Състояние на приложението
appState currentPage = homePage;

// 2. Цветове (вече дефинирани)
Color eduBlue = { 0, 160, 233, 255 };
Color eduOrange = { 252, 176, 33, 255 };
Color mainBackground = { 10, 14, 20, 255 };
Color subSectionsBg = { 20, 30, 45, 255 };
Color sectionOutlines = { 7, 112, 182, 255 };
Color eduTurquoise = { 0, 120, 130, 255 };
Color eduGreen = { 46, 204, 113, 255 };
Color eduRed = { 231, 76, 60, 255 };

// 3. Дизайн и размери
float spacing = 20.0f;
float separationLineY = 220.0f;
float mainSectionHeight = 0.0f; // Ще се сметне в main
float mainSectionY = 0.0f;      // Ще се сметне в main
float centerX = 0.0f;           // Ще се сметне в main
float labelHeight = 40.0f;

// 4. Правоъгълници (Rectangles)
Rectangle backButtonRect = { 20.0f, 10.0f, 120.0f, 50.0f };
Rectangle exitButtonRect = { 1260.0f, 10.0f, 120.0f, 50.0f };
Rectangle subMathSection = { 74.0f, 0, 390.0f, 290.0f }; // Y ще се сметне спрямо mainSectionY
Rectangle subMathSectionHw = { 0, 0, 0, 0 };
Rectangle subMathSectionTest = { 0, 0, 0, 0 };
Rectangle subMathSectionLabel = { 0, 0, 0, 0 };
Rectangle mathSection = { 80.0f, 0, 1240.0f, 200.0f };
Rectangle resusrsesP1 = { 480.0f, 160.0f, 50.0f, 45.0f };
Rectangle resusrsesP2 = { 540.0f, 160.0f, 50.0f, 45.0f };
Rectangle resusrsesP3 = { 600.0f, 160.0f, 50.0f, 45.0f };
Rectangle resusrsesP4 = { 660.0f, 160.0f, 50.0f, 45.0f };
Rectangle resusrsesP5 = { 720.0f, 160.0f, 50.0f, 45.0f };
Rectangle hwPracticeRect = { 70.0f, 160.0f, 200.0f, 45.0f };
Rectangle exPracticeRect = { 280.0f, 160.0f, 200.0f, 45.0f };
Rectangle labelRect = { 0, 0, 0, 0 };
Rectangle gradebookBtn = { 0, 0, 0, 0 };

// 5. Данни за оценки и въпроси
TestResult gradebook[MAX_RESULTS];
int gradebookCount = 0;

Question practiceQuiz[10] = {
    {"Solve: (x - 3)(x + 2) = 0", {"x=3, x=-2", "x=-3, x=2", "x=1"}, 0},
    // ... добави останалите тук
};

Question testBank[BANK_SIZE] = {
    {"Solve: 3x - 9 = 0", {"x=3", "x=-3", "x=9"}, 0},
    // ... добави останалите тук
};

// 6. Променливи за състоянието на теста
int currentQ = 0;
int selectedAns = -1;
int testOrder[TEST_SIZE];
int testCurrentQ = 0;
int testSelectedAns = -1;
int testScore = 0;
bool testAnswered = false;
int answerOrder[TEST_SIZE][3];
int shuffledCorrect[TEST_SIZE];

// 7. Текстура
Texture2D texture;
void getDateStr(char* buf) {
    time_t now = time(nullptr);
    struct tm t;
#ifdef _WIN32
    localtime_s(&t, &now);
#else
    localtime_r(&now, &t);
#endif
    snprintf(buf, 16, "%02d/%02d/%04d", t.tm_mday, t.tm_mon + 1, t.tm_year + 1900);
}