#include "GameBase.h"
#include "HangmanGame.h"
#include "WordManager.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    WordManager wordManager;
    char playAgain = 'y';

    std::cout << "=== Hangman ===\n";

    // Outer loop: keeps running until the player chooses to quit
    do {
        std::string word = wordManager.getRandomWord();

        // Polymorphism: HangmanGame object is handled via GameBase pointer
        GameBase* game = new HangmanGame(word);
        game->start();

        // Inner loop: continues until win or lose condition is met
        while (!game->isGameOver()) {
            game->displayStatus();
            game->playTurn();
        }

        // Show the final board state
        game->displayStatus();

        // Cast to HangmanGame to access isWon() and print the appropriate outcome
        HangmanGame* hg = dynamic_cast<HangmanGame*>(game);
        if (hg && hg->isWon()) {
            std::cout << "\nYou won! The word was: " << word << "\n";
        } else {
            std::cout << "\nGame over. The word was: " << word << "\n";
        }

        delete game;

        std::cout << "\nPlay again? (y/n): ";
        std::cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thanks for playing!\n";
    return 0;
}
