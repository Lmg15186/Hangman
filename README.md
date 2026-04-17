# Hangman

The application is built around four classes with clearly separated responsibilities. 
A WordManager selects a random word from a poll. 
HangmanGame manages the round logic, state and display. 
InputValidator enforces the rules of valid input. 
GameBase is an abstract class that defines the shared interface used across the entire program.

The project was designed to demonstrate core Object-Oriented Programming principles encapsulation, inheritance, polymorphism and the use of abstract classes. Each principles is intentionally applied and traceable in the code.
This project implements a text-based Hangman game in C++. 
The player attempts to guess a hidden word one letter at a time, with a limit of six incorrect guesses before losing. 
The program continues offering new rounds until the user choose to quit.
