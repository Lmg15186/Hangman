#include "WordManager.h"
#include <cstdlib>

// Initialises the word pool used across game sessions
WordManager::WordManager() {
    words = {
        "planet", "jungle", "bridge", "castle", "flight",
        "mirror", "rocket", "garden", "candle", "fossil",
        "breeze", "ladder", "magnet", "pillow", "tunnel"
    };
}

// Returns a randomly chosen word from the pool
std::string WordManager::getRandomWord() const {
    int index = std::rand() % words.size();
    return words[index];
}
