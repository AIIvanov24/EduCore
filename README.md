# EduCore — Електронно Училище

![EduCore Logo](main/main/eduCoreLogo.png)

**EduCore** is a desktop educational application built with C++ and raylib. It provides students with structured learning materials, practice exercises, and timed tests — with results tracked in a built-in gradebook.

---

## Features

- **Materials & Lessons** — Browse structured lessons covering Algebra, Geometry, and Fractions & Percentages, with tab navigation between topics.
- **Exercises** — Practice problems with typed answers, hints, and instant feedback. Progress is tracked with visual dots.
- **Timed Tests** — 10 multiple-choice questions with a 30-second timer per question. Correct answers are highlighted in green, wrong ones in red.
- **Gradebook** — All test results are saved and displayed in a table with your score, percentage, numeric grade (2–6 scale), and date. An overall average is calculated automatically.
- **Grade Scale** — Grades are calculated using the formula: `grade = percentage × 0.06`, clamped between **2.00** and **6.00**.

---

## Screenshots

> _Add screenshots here after building the project._

---

## Requirements

| Tool | Version |
|------|---------|
| Visual Studio | 2022 (or later) |
| C++ Standard | C++11 or later |
| raylib | via NuGet |

---

## Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/your-username/educore.git
cd educore
```

### 2. Open in Visual Studio

Open `main.slnx` (or `main.sln`) in Visual Studio.

### 3. Restore NuGet packages

Visual Studio should restore raylib automatically via NuGet on first build. If it doesn't:

- Right-click the solution in Solution Explorer
- Select **Restore NuGet Packages**

### 4. Build and run

Press **F5** or click **Run** to build and launch the app.

> ⚠️ Make sure `eduCoreLogo.png` is in the same directory as the executable (or in the project root when running from Visual Studio).

---

## Project Structure

```
educore/
├── main.cpp              # All application source code
├── main.slnx             # Visual Studio solution file
├── main.vcxproj          # Project file
├── main.vcxproj.filters  # Source file filters for VS
├── eduCoreLogo.png       # App logo (required at runtime)
└── README.md
```

---

## How to Use

### Home Page
- Click the **MATHS** card to enter the Mathematics section.
- Click **GRADEBOOK** to view your past test results.
- The **Exit** button (top-right, red) closes the application from any page.

### Maths Page
Choose one of three sections:
- **Materials & Lessons** — Read through the lesson content. Use the tab buttons to switch topics and the Prev/Next buttons to navigate.
- **HW & Practice** — Type your answer into the input box and press **Check Answer**. A hint is provided for each question.
- **Tests** — Answer 10 multiple choice questions. You have 30 seconds per question. Your grade is saved to the Gradebook automatically when you finish.

### Gradebook
Displays all completed tests with:
- Score (e.g. `7 / 10`)
- Percentage (e.g. `70%`)
- Numeric grade on the 2–6 scale (e.g. `4.20`)
- Date of the test

---

## Grade Scale

| Percentage | Grade |
|-----------|-------|
| 100% | 6.00 |
| 83% | 4.98 |
| 67% | 4.02 |
| 50% | 3.00 |
| 33% | 1.98 → clamped to **2.00** |
| 0% | 0.00 → clamped to **2.00** |

Formula: `grade = percentage × 0.06` (min: 2.00, max: 6.00)

---

## .gitignore Recommendations

Add the following to your `.gitignore` to keep the repo clean:

```
# Build output
Debug/
Release/
x64/
x86/

# Visual Studio
.vs/
*.user
*.suo

# NuGet (restored automatically)
packages/
```

---

## Built With

- [raylib](https://www.raylib.com/) — Simple and easy-to-use game/graphics library for C/C++
- C++11
- Visual Studio 2022

---

## License

This project was created for educational purposes. Feel free to use and modify it.