# Masyu Puzzle – Coursework Project

## 📘 Overview

This project is part of the second semester coursework for the C & C++ Basic Programming course at Kyiv University. It involves implementing a solution for the Masyu puzzle—a logic puzzle that requires drawing a continuous loop through a grid of black and white circles, adhering to specific rules.

## 🔍 Puzzle Rules

Masyu puzzles are played on a rectangular grid containing black and white circles. The objective is to draw a single continuous loop that passes through all the circles, following these rules:

* **White Circles**: The loop must pass straight through these circles but must turn at least once in the adjacent cells.
* **Black Circles**: The loop must turn at these circles but must travel straight through the adjacent cells.

The loop must not intersect itself or branch off, and it must form a single continuous path. ([Википедия][1])

## 🛠️ Features

* **Grid Representation**: The puzzle grid is represented using a 2D array, with each cell indicating the presence of a circle and its type (black or white).
* **Input Parsing**: The program accepts puzzle configurations from a text file, where each line represents a row of the grid.
* **Solver Algorithm**: A backtracking algorithm is implemented to explore potential solutions, ensuring all rules are satisfied.
* **Output**: The solution, if found, is displayed in the console, showing the path of the loop through the grid.

## 🧪 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/RoMmMaNnN/Kyiv_University.git
   ```

2. Navigate to the project directory:

   ```bash
   cd Kyiv_University/C\&C++\ Basic\ Programing/Sem2/Masyu\ Puzzle\ -\ CourseWork
   ```

3. Build the project using the provided Makefile:

   ```bash
   make
   ```

4. Run the program:

   ```bash
   ./task30
   ```

Got it! Here's a clear English usage guide for your menu system, including the step-by-step instructions for points 2 and 3.

---

# Users Menu – Instructions

This program uses a **numeric menu system**. Each menu option and parameter must be entered as **numbers**, sometimes separated by **spaces**. Follow the steps below to use the menu properly.

## Menu Overview

```
╔════════════════════════════════════════════════════════╗
║                       USERS MENU                       ║
║                                                        ║
║                1. Display all fields                   ║
║              2. Display field by number                ║
║               3. Create a custom field                 ║
║                     4. Show rules                      ║
║                 5. Exit the program                    ║
║                                                        ║
║             By default there are 5 fields              ║
╚════════════════════════════════════════════════════════╝
```

## How to Use Each Option

### **1. Display all fields**

* Enter **1** and press **Enter**.
* The program will display all available fields.

### **2. Display field by number**

* Enter **2** and press **Enter**.
* The program will ask you for the **field number**.
* Enter a **single positive number** corresponding to the field (starting from 0) and press **Enter**.
* The program will display the selected field.

### **3. Create a custom field**

* Enter **3** and press **Enter**.
* You will be asked for the **field dimensions**:

    * Enter **two positive numbers** separated by a space: `<rows> <columns>`.
* Next, you will be asked for the **number of pearls for each color**:

    * Enter the count for each color as requested (numbers only).
* Then, for each pearl, enter its **coordinates**:

    * Coordinates must be **two non-negative numbers** separated by a space: `<row> <column>`.
* Follow the prompts for each pearl until all are placed.

### **4. Show rules**

* Enter **4** and press **Enter**.
* The program will display the rules for using the fields and pearls.

### **5. Exit the program**

* Enter **5** and press **Enter** to exit the program.

---

**Important Notes:**

* Always use **numbers only** for selections, counts, and coordinates.
* When multiple numbers are requested, separate them with a **single space**.
* All coordinates and counts must be **non-negative integers**.


## 🧠 Learning Objectives

* Implementing algorithms to solve constraint satisfaction problems.
* Enhancing problem-solving skills through logical reasoning.
* Improving proficiency in C++ programming, including file handling and algorithm design.