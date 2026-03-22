#include "header.h"


appState currentPage = homePage;


Color eduBlue = { 0, 160, 233, 255 };
Color eduOrange = { 252, 176, 33, 255 };
Color mainBackground = { 10, 14, 20, 255 };
Color subSectionsBg = { 20, 30, 45, 255 };
Color sectionOutlines = { 7, 112, 182, 255 };
Color eduTurquoise = { 0, 120, 130, 255 };
Color eduGreen = { 46, 204, 113, 255 };
Color eduRed = { 231, 76, 60, 255 };


float spacing = 20.0f;
float separationLineY = 220.0f;
float mainSectionHeight = 0.0f; 
float mainSectionY = 0.0f;      
float centerX = 0.0f;           
float labelHeight = 40.0f;

// (Rectangles)
Rectangle backButtonRect = { 20.0f, 10.0f, 120.0f, 50.0f };
Rectangle exitButtonRect = { 1260.0f, 10.0f, 120.0f, 50.0f };
Rectangle subMathSection = { 74.0f, 0, 390.0f, 290.0f }; 
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

// Data structures for tests and questions
TestResult gradebook[MAX_RESULTS];
int gradebookCount = 0;

Question practiceQuiz[10] = {
    {"Solve: (x - 3)(x + 2) = 0",          {"x=3, x=-2",    "x=-3, x=2",   "x=1"       }, 0},
    {"Solve: 2x + 10 = 3x - 5",             {"x=5",          "x=15",        "x=-15"     }, 1},
    {"Roots of: x^2 - 7x + 10 = 0",        {"x=2, x=5",     "x=-2, x=-5",  "x=3, x=4" }, 0},
    {"Solve: 3(x - 4) = 0",                 {"x=0",          "x=-4",        "x=4"       }, 2},
    {"Solve: x^2 - 9 = 0",                  {"x=3",          "x=+-3",       "x=9"       }, 1},
    {"Solve: x^2 - 4xy + 4y^2 = 0",        {"x=2y",         "x=y",         "x=4y"      }, 0},
    {"Solve: 4x - 12 = 2x + 6",             {"x=6",          "x=12",        "x=9"       }, 2},
    {"Discriminant of: x^2 + 4x + 4 = 0",  {"D=16",         "D=0",         "D=8"       }, 1},
    {"Solve: x^2 + xy - 6y^2 = 0",         {"x=2y, x=-3y",  "x=y, x=6y",   "x=3y, x=-2y"}, 0},
    {"Solve: x^2 - xy = 0",                 {"x=1",          "x=0, y",      "x=0, x=y" }, 2}

};

Question testBank[BANK_SIZE] = {
    // Linear equations (0-7)
    {"Solve: 3x - 9 = 0",                       {"x=3",          "x=-3",        "x=9"        }, 0},
    {"Solve: 2x + 10 = 3x - 5",                  {"x=5",          "x=15",        "x=-5"       }, 1},
    {"Solve: 7x - 14 = 0",                       {"x=14",         "x=2",         "x=-2"       }, 1},
    {"Solve: 4(x - 3) = 8",                      {"x=5",          "x=3",         "x=2"        }, 0},
    {"Solve: 5x + 15 = 0",                       {"x=3",          "x=-3",        "x=5"        }, 1},
    {"Solve: 6x + 3 = 3x + 12",                  {"x=2",          "x=3",         "x=5"        }, 1},
    {"Solve: 2(x + 5) = 3x - 1",                 {"x=11",         "x=-11",       "x=9"        }, 0},
    {"Solve: 10x - 20 = 5x + 5",                 {"x=5",          "x=3",         "x=1"        }, 0},
    // Product of linear factors (8-13)
    {"Solve: (x - 5)(x + 3) = 0",                {"x=5, x=-3",    "x=-5, x=3",   "x=5, x=3"  }, 0},
    {"Solve: (2x - 8)(x + 7) = 0",               {"x=4, x=-7",    "x=-4, x=7",   "x=8, x=-7" }, 0},
    {"Solve: (3x - 9)(x - 4) = 0",               {"x=3, x=4",     "x=-3, x=4",   "x=9, x=4"  }, 0},
    {"Solve: (x + 6)(x - 6) = 0",                {"x=6",          "x=+-6",       "x=-6"       }, 1},
    {"Solve: (x - 1)(x - 2)(x - 3) = 0",        {"x=1, 2, 3",    "x=-1,-2,-3",  "x=0, 1, 2" }, 0},
    {"Solve: (4x + 8)(x - 0.5) = 0",             {"x=-2, x=0.5",  "x=2, x=-0.5", "x=-8, x=2" }, 0},
    // Quadratic equations (14-21)
    {"Roots of: x^2 - 5x + 6 = 0",              {"x=2, x=3",     "x=-2, x=-3",  "x=1, x=6"  }, 0},
    {"Roots of: x^2 + 2x - 8 = 0",              {"x=2, x=-4",    "x=-2, x=4",   "x=4, x=-2" }, 0},
    {"Discriminant of: x^2 - 4x + 4 = 0",       {"D=8",          "D=0",         "D=4"        }, 1},
    {"Discriminant of: x^2 + x + 1 = 0",        {"D=-3",         "D=3",         "D=5"        }, 0},
    {"Roots of: x^2 - 9 = 0",                   {"x=3",          "x=+-3",       "x=9"        }, 1},
    {"Roots of: 2x^2 - 8x + 6 = 0",             {"x=1, x=3",     "x=-1, x=-3",  "x=2, x=4"  }, 0},
    {"How many real roots: x^2 + 4x + 5 = 0?",  {"0 roots",      "1 root",      "2 roots"    }, 0},
    {"Roots of: x^2 - 7x + 10 = 0",             {"x=2, x=5",     "x=-2, x=-5",  "x=3, x=4"  }, 0},
    // Homogeneous equations (22-29)
    {"Solve: x^2 - 4xy + 4y^2 = 0",             {"x=2y",         "x=4y",        "x=y"        }, 0},
    {"Solve: x^2 + xy - 6y^2 = 0",              {"x=2y, x=-3y",  "x=3y, x=-2y", "x=y, x=6y" }, 0},
    {"Solve: x^2 - xy = 0",                      {"x=0, x=y",     "x=0",         "x=y"        }, 0},
    {"Solve: 2x^2 - 5xy + 2y^2 = 0",            {"x=2y, x=0.5y", "x=y, x=2y",   "x=5y, x=2y"}, 0},
    {"Solve: x^2 - 3xy + 2y^2 = 0",             {"x=y, x=2y",    "x=-y, x=-2y", "x=3y, x=y" }, 0},
    {"Solve: x^2 + 2xy + y^2 = 0",              {"x=-y",         "x=y",         "x=2y"       }, 0},
    {"Solve: 3x^2 - 4xy + y^2 = 0",             {"x=y, x=y/3",   "x=4y, x=y",   "x=y, x=3y" }, 0},
    {"Solve: x^2 - 2xy + y^2 = 0",              {"x=y",          "x=-y",        "x=2y"       }, 0},
};

// variables for test state management
int currentQ = 0;
int selectedAns = -1;
int testOrder[TEST_SIZE];
int testCurrentQ = 0;
int testSelectedAns = -1;
int testScore = 0;
bool testAnswered = false;
int answerOrder[TEST_SIZE][3];
int shuffledCorrect[TEST_SIZE];

Texture2D texture;

// finction for the current date as string (for test results)
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

// HOVER COLOR HELPERS