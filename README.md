# Hangman — C++ OOP

A text-based Hangman game built in C++, designed as a hands-on exercise in 
applying core Object-Oriented Programming principles: **encapsulation**, 
**inheritance**, **polymorphism** and **abstract classes**.

## 🎯 Project Overview

The player tries to guess a hidden word one letter at a time, with a limit 
of six incorrect guesses before losing. The program continues offering new 
rounds until the user chooses to quit.

Each OOP principle is intentionally applied and traceable in the code — the 
goal wasn't just to build a working game, but to demonstrate clean OOP design.

## 🏗️ Architecture

The application is built around **four classes with clearly separated 
responsibilities**:

| Class | Responsibility |
|---|---|
| `GameBase` | Abstract class defining the shared interface used across the program |
| `WordManager` | Selects a random word from a word pool |
| `HangmanGame` | Manages round logic, game state and display |
| `InputValidator` | Enforces rules for valid user input |

## 🔧 OOP Principles Applied

- **🔒 Encapsulation** — internal state (current word, guesses, lives) is kept 
  private and accessed only through controlled methods.
- **🧬 Inheritance** — concrete classes derive from `GameBase`, reusing and 
  extending the shared contract.
- **🎭 Polymorphism** — derived classes override base methods to provide 
  game-specific behaviour through a common interface.
- **🎨 Abstract Classes** — `GameBase` defines the abstract interface that 
  any game built on top of this framework must implement.

## 💡 Features

- 🎮 Classic Hangman gameplay loop
- 🎲 Random word selection from an internal word pool
- 🛡️ Robust input validation (rejects invalid characters, repeated guesses, etc.)
- 💔 Six-life limit with progressive feedback
- 🔁 Replay loop until the player chooses to quit
- 🧱 Clean separation of concerns across four cooperating classes

## 🚀 How to Run

1. Make sure you have a C++ compiler installed (g++ or clang)
2. Clone or download this repository
3. Compile the source files:
```bash
   g++ -std=c++17 *.cpp -o hangman
```
4. Run the game:
```bash
   ./hangman
```

## 📚 What I Learned

- Designing a class hierarchy around an abstract interface (`GameBase`)
- Applying the **single responsibility principle** — each class does one job well
- Practising the four core OOP pillars in a real, traceable way
- Separating game logic, input handling, data management and presentation
- Writing maintainable C++ code that's easy to extend with new game modes

---

📂 Part of my IT learning journey at the Academy of Interactive Technology (AIT) — 
see more projects at [github.com/Lmg15186](https://github.com/Lmg15186)
