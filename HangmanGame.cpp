#include "HangmanGame.h"
#include "InputValidator.h"
#include <iostream>
#include <cctype>
#include <algorithm>

// ---- Constructor ----

HangmanGame::HangmanGame(const std::string& word)
    : secretWord(word), attemptsLeft(6), gameWon(false) {}

// ---- Private helpers ----

// Builds the display string: guessed letters are shown, others replaced by '_'
std::string HangmanGame::getMaskedWord() const {
    std::string masked = "";
    for (char c : secretWord) {
        if (InputValidator::hasAlreadyBeenUsed(c, guessedLetters)) {
            masked += c;
        } else {
            masked += '_';
        }
        masked += ' ';
    }
    return masked;
}

// Iterates through the secret word checking every letter has been guessed
bool HangmanGame::checkWin() const {
    for (char c : secretWord) {
        if (!InputValidator::hasAlreadyBeenUsed(c, guessedLetters)) {
            return false;
        }
    }
    return true;
}

// ---- GameBase overrides ----

// Resets all state so the same object can play a fresh round
void HangmanGame::start() {
    guessedLetters.clear();
    attemptsLeft = 6;
    gameWon = false;
}

// Shows the masked word, the letters already tried, and remaining attempts
void HangmanGame::displayStatus() const {
    std::cout << "\nWord:     " << getMaskedWord() << "\n";

    if (!guessedLetters.empty()) {
        std::cout << "Tried:    ";
        for (char c : guessedLetters) std::cout << c << " ";
        std::cout << "\n";
    }

    std::cout << "Attempts: " << attemptsLeft << " remaining\n";
}

// Handles one full turn: read input, validate, process result
void HangmanGame::playTurn() {
    std::string input;
    std::cout << "\nEnter a letter: ";
    std::cin >> input;

    // Convert to lowercase for uniform comparison
    for (char& c : input) c = std::tolower(static_cast<unsigned char>(c));

    // Validation: must be a single character
    if (!InputValidator::isSingleCharacter(input)) {
        std::cout << "  Please enter exactly one letter.\n";
        return;
    }

    char guess = input[0];

    // Validation: must be alphabetic
    if (!InputValidator::isAlphabetic(guess)) {
        std::cout << "  Only letters are accepted. Numbers and symbols are not valid.\n";
        return;
    }

    // Validation: must not be a repeated guess
    if (InputValidator::hasAlreadyBeenUsed(guess, guessedLetters)) {
        std::cout << "  You already tried '" << guess << "'. No attempt deducted.\n";
        return;
    }

    // Record the letter regardless of outcome
    guessedLetters.push_back(guess);

    // Check if the letter appears in the secret word
    if (secretWord.find(guess) != std::string::npos) {
        std::cout << "  Correct!\n";
        if (checkWin()) gameWon = true;
    } else {
        attemptsLeft--;
        std::cout << "  Wrong. " << attemptsLeft << " attempt(s) left.\n";
    }
}

// Game ends when the player wins or exhausts all attempts
bool HangmanGame::isGameOver() const {
    return gameWon || attemptsLeft <= 0;
}

// Exposes the win condition without revealing internal state
bool HangmanGame::isWon() const {
    return gameWon;
}
