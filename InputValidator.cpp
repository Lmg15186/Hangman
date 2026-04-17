#include "InputValidator.h"
#include <cctype>
#include <algorithm>

// Rejects empty strings and anything longer than one character
bool InputValidator::isSingleCharacter(const std::string& input) {
    return input.length() == 1;
}

// Rejects digits, symbols, and whitespace
bool InputValidator::isAlphabetic(char c) {
    return std::isalpha(static_cast<unsigned char>(c));
}

// Checks the guessed letters history to detect repeated input
bool InputValidator::hasAlreadyBeenUsed(char c, const std::vector<char>& guessedLetters) {
    return std::find(guessedLetters.begin(), guessedLetters.end(), c) != guessedLetters.end();
}
