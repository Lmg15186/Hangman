#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include "GameBase.h"
#include <string>
#include <vector>

// Concrete implementation of a Hangman game.
// Inherits from GameBase and overrides all four virtual methods.
// All game state is private — external code interacts only through the base interface.
class HangmanGame : public GameBase {
private:
    std::string secretWord;           // The word the player must guess
    std::vector<char> guessedLetters; // History of all letters attempted
    int attemptsLeft;                 // Remaining incorrect guesses allowed
    bool gameWon;                     // True when the player has guessed the full word

    // Returns the masked word, replacing unguessed letters with underscores
    std::string getMaskedWord() const;

    // Returns true when every letter in secretWord has been guessed
    bool checkWin() const;

public:
    // Constructs the game with the given secret word
    HangmanGame(const std::string& word);

    // Resets game state so the object can be reused for a new round
    void start() override;

    // Reads and validates one guess, then updates game state
    void playTurn() override;

    // Returns true when the player has won or run out of attempts
    bool isGameOver() const override;

    // Prints the masked word, guessed letters, and remaining attempts
    void displayStatus() const override;

    // Returns true if the player guessed the word successfully
    bool isWon() const;
};

#endif
