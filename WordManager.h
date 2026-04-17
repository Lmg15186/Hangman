#ifndef WORDMANAGER_H
#define WORDMANAGER_H

#include <string>
#include <vector>

// Manages the word list and randomly selects a word for each game session.
// Encapsulates the word source so it can be extended later (e.g. file loading).
class WordManager {
private:
    std::vector<std::string> words;

public:
    // Populates the internal word list
    WordManager();

    // Returns a randomly selected word from the list
    std::string getRandomWord() const;
};

#endif
