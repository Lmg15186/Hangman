#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <string>
#include <vector>

// Provides static validation methods for player input.
// Centralises all input checks to enforce the error handling rules.
class InputValidator {
public:
    // Returns true if the input contains exactly one character
    static bool isSingleCharacter(const std::string& input);

    // Returns true if the character is an alphabetic letter
    static bool isAlphabetic(char c);

    // Returns true if the letter has already been guessed in this session
    static bool hasAlreadyBeenUsed(char c, const std::vector<char>& guessedLetters);
};

#endif
