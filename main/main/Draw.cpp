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

void drawHomePage() {
    DrawText("Welcome to ", 20, 70, 70, eduBlue);
    DrawText("EduCore Online School !", 20, 140, 70, eduOrange);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
    DrawRectangleRounded(gradebookBtn, 0.3f, 10, hoverGradebookBtn ? eduOrange : subSectionsBg);
    DrawRectangleRoundedLines(gradebookBtn, 0.3f, 10, eduOrange);
    DrawText(" Gradebook  [ View Results ]", (int)(gradebookBtn.x + 20), (int)(gradebookBtn.y + 15), 24, RAYWHITE);
    DrawText("Discover more subjects with EduCorePlus", 90, (int)(mainSectionY + 10.0f * spacing + 200.0f + 90.0f), 25, sectionOutlines);
}

void drawMathPage() {
    DrawText("Welcome to ", 20, 70, 70, eduBlue);
    DrawText("Maths", 20, 140, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
    DrawRectangleRounded(subMathSection, 0.2f, 10, mainBackground);
    DrawRectangleRounded(subMathSectionLabel, 1.0f, 10, eduTurquoise);
    DrawRectangle((int)subMathSectionLabel.x, (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)subMathSectionLabel.width, (int)labelHeight, eduTurquoise);
    DrawText("Materials & Lessons", (int)(subMathSection.x + spacing), (int)(subMathSection.y + spacing - 5.0f), 30, RAYWHITE);
    DrawText("Access comprehensive study guides", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 85.0f), 18, hoverSubTextColor);
    DrawText("and step-by-step explanations to master", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 110.0f), 18, hoverSubTextColor);
    DrawText("new mathematical concepts.", (int)(subMathSection.x + 20.0f), (int)(subMathSection.y + 135.0f), 18, hoverSubTextColor);
    DrawRectangleRounded({ subMathSectionLabel.x + 42.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
    DrawText("View", (int)(subMathSection.x + spacing + 140.0f), (int)(subMathSection.y + spacing + 205.0f), 30, RAYWHITE);
    DrawRectangleRounded(subMathSectionHw, 0.2f, 10, mainBackground);
    DrawRectangleRounded({ subMathSectionHw.x, subMathSectionHw.y, subMathSectionHw.width, labelHeight }, 1.0f, 10, eduTurquoise);
    DrawRectangle((int)(subMathSectionLabel.x + 391.0f + spacing * 2.0f), (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)(subMathSectionLabel.width - 1.0f), (int)labelHeight, eduTurquoise);
    DrawText("HW and practice", (int)(subMathSectionHw.x + spacing), (int)(subMathSectionHw.y + spacing - 5.0f), 30, RAYWHITE);
    DrawText("Sharpen your skills with interactive", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 85.0f), 18, hoverSubTextColorHw);
    DrawText("problem sets and exercises designed to", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 110.0f), 18, hoverSubTextColorHw);
    DrawText("reinforce what you've learned in class.", (int)(subMathSectionHw.x + 20.0f), (int)(subMathSectionHw.y + 135.0f), 18, hoverSubTextColorHw);
    DrawRectangleRounded({ subMathSectionLabel.x + 472.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
    DrawText("Practise", (int)(subMathSectionHw.x + spacing + 110.0f), (int)(subMathSectionHw.y + spacing + 205.0f), 30, RAYWHITE);
    DrawRectangleRounded(subMathSectionTest, 0.2f, 10, mainBackground);
    DrawRectangleRounded({ subMathSectionTest.x, subMathSectionTest.y, subMathSectionTest.width, labelHeight }, 1.0f, 10, eduTurquoise);
    DrawRectangle((int)(subMathSectionLabel.x + 391.0f * 2.0f + spacing * 4.0f), (int)(subMathSectionLabel.y + labelHeight / 2.0f), (int)(subMathSectionLabel.width - 2.0f), (int)labelHeight, eduTurquoise);
    DrawText("Tests", (int)(subMathSectionTest.x + spacing), (int)(subMathSectionTest.y + spacing - 5.0f), 30, RAYWHITE);
    DrawText("Evaluate your progress and prepare for", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 85.0f), 18, hoverSubTextColorTest);
    DrawText("exams with timed quizzes and mock tests", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 110.0f), 18, hoverSubTextColorTest);
    DrawText("covering all key curriculum topics.", (int)(subMathSectionTest.x + 20.0f), (int)(subMathSectionTest.y + 135.0f), 18, hoverSubTextColorTest);
    DrawRectangleRounded({ subMathSectionLabel.x + 902.0f, subMathSectionLabel.y + labelHeight / 2.0f + 200.0f, subMathSectionLabel.width - 88.0f, labelHeight }, 0.3f, 9, eduTurquoise);
    DrawText("Start Test", (int)(subMathSectionTest.x + spacing + 90.0f), (int)(subMathSectionTest.y + spacing + 205.0f), 30, RAYWHITE);
}

void drawMaterialsPage() {
    DrawText("LEARNING RESOURCES", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
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
}

void drawResursesTab1(){
     DrawText("(ax+b)(cx+d)=0 ", 20, 70, 70, eduTurquoise);
     DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
     DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
     DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
     DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
     DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
     DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawResursesTab2(){
    DrawText("LINEAR EQUATIONS", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawResursesTab3() {
    DrawText("QUADRATIC EQUATIONS", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawResursesTab4() {
    DrawText("HOMOGENEOUS EQUATIONS", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawResursesTab5() {
    DrawText("MATH QUICK SUMMARY", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawExercisesPage() {
    DrawText("Maths Homework and Practice", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(hwPracticeRect, 0.5f, 10, hwPracticeRectColor);
    DrawText("Homework", (int)(hwPracticeRect.x + 40.0f), (int)(hwPracticeRect.y + 10.0f), 25, RAYWHITE);
    DrawRectangleRounded(exPracticeRect, 0.5f, 10, exPracticeRectColor);
    DrawText("Practice", (int)(exPracticeRect.x + 50.0f), (int)(exPracticeRect.y + 10.0f), 25, RAYWHITE);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);
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
}

void drawGradebookPage() {
    DrawText("Gradebook", 20, 70, 70, eduOrange);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawRectangleRounded(backButtonRect, 0.3f, 10, hoverBack ? eduBlue : subSectionsBg);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduOrange);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);

    if (gradebookCount == 0) {
        // Empty state
        int tw = MeasureText("No tests completed yet.", 30);
        DrawText("No tests completed yet.", (GetScreenWidth() - tw) / 2, (int)(separationLineY + 130), 30, GRAY);
        int tw2 = MeasureText("Complete a Maths Test to see your results here.", 22);
        DrawText("Complete a Maths Test to see your results here.", (GetScreenWidth() - tw2) / 2, (int)(separationLineY + 180), 22, DARKGRAY);
    }
    else {
        // ── Table header ──
        float tableX = 60.0f;
        float tableY = separationLineY + 50.0f;
        float rowH = 48.0f;

        DrawRectangle((int)tableX, (int)tableY, 1280, 38, ColorBrightness(eduOrange, -0.35f));
        DrawText("#", (int)(tableX + 15), (int)(tableY + 8), 20, RAYWHITE);
        DrawText("Score", (int)(tableX + 70), (int)(tableY + 8), 20, RAYWHITE);
        DrawText("Percent", (int)(tableX + 270), (int)(tableY + 8), 20, RAYWHITE);
        DrawText("Grade", (int)(tableX + 530), (int)(tableY + 8), 20, RAYWHITE);
        DrawText("Date", (int)(tableX + 830), (int)(tableY + 8), 20, RAYWHITE);
        DrawText("Result", (int)(tableX + 1070), (int)(tableY + 8), 20, RAYWHITE);

        // ── Rows (newest first, max 9 visible) ──
        int shown = gradebookCount < 9 ? gradebookCount : 9;
        for (int i = 0; i < shown; i++) {
            // newest first
            TestResult& r = gradebook[gradebookCount - 1 - i];
            float ry = tableY + 38.0f + i * rowH;
            Color rowBg = (i % 2 == 0) ? mainBackground : ColorBrightness(subSectionsBg, 0.15f);
            DrawRectangle((int)tableX, (int)ry, 1280, (int)(rowH - 2), rowBg);

            Color gc = r.grade >= 4.8f ? eduGreen : r.grade >= 3.6f ? eduOrange : eduRed;

            // Row number
            DrawText(TextFormat("%d", gradebookCount - i), (int)(tableX + 15), (int)(ry + 12), 20, GRAY);
            // Score
            DrawText(TextFormat("%d / %d", r.score, r.total), (int)(tableX + 70), (int)(ry + 12), 20, RAYWHITE);
            // Percent
            DrawText(TextFormat("%.0f%%", r.pct), (int)(tableX + 270), (int)(ry + 12), 20, gc);
            // Grade
            char gbuf[16]; snprintf(gbuf, sizeof(gbuf), "%.2f / 6.00", r.grade);
            DrawText(gbuf, (int)(tableX + 530), (int)(ry + 12), 20, gc);
            // Date
            DrawText(r.date, (int)(tableX + 830), (int)(ry + 12), 20, LIGHTGRAY);
            // Result label
            const char* label = r.grade >= 4.8f ? "Excellent" : r.grade >= 3.6f ? "Good" : r.grade >= 2.4f ? "Average" : "Poor";
            DrawText(label, (int)(tableX + 1070), (int)(ry + 12), 20, gc);
        }

        // ── Average row ──
        float avgY = tableY + 38.0f + shown * rowH + 10.0f;
        DrawRectangle((int)tableX, (int)avgY, 1280, 40, ColorBrightness(eduOrange, -0.3f));
        float totalGrade = 0;
        for (int i = 0; i < gradebookCount; i++) totalGrade += gradebook[i].grade;
        float avgGrade = totalGrade / gradebookCount;
        char avgBuf[64];
        snprintf(avgBuf, sizeof(avgBuf), "Average Grade:  %.2f / 6.00   (%d tests total)", avgGrade, gradebookCount);
        DrawText(avgBuf, (int)(tableX + 15), (int)(avgY + 10), 22,
            avgGrade >= 4.8f ? eduGreen : avgGrade >= 3.6f ? eduOrange : eduRed);
    }
}

void drawTestPage() {
	Vector2 mousePoint = GetMousePosition();
    DrawText("Maths Test", 20, 70, 70, eduTurquoise);
    DrawRectangleRounded(backButtonRect, 0.3f, 10, backBtnColor);
    DrawRectangleRoundedLines(backButtonRect, 0.3f, 10, sectionOutlines);
    DrawTexture(texture, 1050, 10, WHITE); drawExitBtn();
    DrawText(" << Back", (int)(backButtonRect.x + 6.0f), (int)(backButtonRect.y + 13.0f), 25, RAYWHITE);
    DrawRectangle(40, (int)separationLineY, GetScreenWidth() - 80, 2, eduBlue);
    DrawRectangleRounded({ 40.0f, separationLineY + 30.0f, 1320.0f, mainSectionHeight }, 0.1f, 10, subSectionsBg);

    Question& q = testBank[testOrder[testCurrentQ]];
    float testStartY = separationLineY + 60.0f;

    // Progress bar
    DrawRectangle(70, (int)(testStartY - 15), 1260, 10, subSectionsBg);
    DrawRectangle(70, (int)(testStartY - 15), (int)(1260.0f * testCurrentQ / TEST_SIZE), 10, eduTurquoise);

    // Question counter + live score
    DrawText(TextFormat("Question %d / %d", testCurrentQ + 1, TEST_SIZE), 70, (int)testStartY, 25, eduOrange);
    DrawText(TextFormat("Score: %d", testScore), 1200, (int)testStartY, 22, eduTurquoise);

    // Question text
    DrawText(q.text, 70, (int)(testStartY + 45), 33, RAYWHITE);

    // Answer options A / B / C  (displayed in shuffled order)
    const char* prefixes[3] = { "A)  ", "B)  ", "C)  " };
    for (int i = 0; i < 3; i++) {
        Rectangle ansRect = { 70.0f, testStartY + 125.0f + (i * 72.0f), 700.0f, 58.0f };
        Color boxColor = ColorAlpha(eduBlue, 0.2f);
        if (testAnswered) {
            if (i == shuffledCorrect[testCurrentQ]) boxColor = eduGreen;
            else if (i == testSelectedAns)          boxColor = eduRed;
        }
        else if (CheckCollisionPointRec(mousePoint, ansRect)) {
            boxColor = eduTurquoise;
        }
        DrawRectangleRounded(ansRect, 0.2f, 10, boxColor);
        DrawRectangleRoundedLines(ansRect, 0.2f, 10, sectionOutlines);
        // Show the answer text at the shuffled position
        int origIdx = answerOrder[testCurrentQ][i];
        DrawText(TextFormat("%s%s", prefixes[i], q.answers[origIdx]),
            (int)ansRect.x + 20, (int)ansRect.y + 16, 22, RAYWHITE);
    }

    // Next / Finish button (shown after answering)
    if (testAnswered) {
        Rectangle nextBtn = { 1100, separationLineY + 450, 200, 50 };
        bool hoverNext = CheckCollisionPointRec(mousePoint, nextBtn);
        DrawRectangleRounded(nextBtn, 0.2f, 10, hoverNext ? eduOrange : DARKGRAY);
        DrawRectangleRoundedLines(nextBtn, 0.2f, 10, sectionOutlines);
        DrawText(testCurrentQ < TEST_SIZE - 1 ? "Next >" : "See Results",
            (int)nextBtn.x + 25, (int)nextBtn.y + 15, 20, RAYWHITE);
    }
}