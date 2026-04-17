#ifndef GAMEBASE_H
#define GAMEBASE_H

// Abstract base class that defines the contract for all game types.
// Any class inheriting from GameBase must implement these four methods.
class GameBase {
public:
    // Initialises or resets the game state before each round
    virtual void start() = 0;

    // Handles one full turn: input, validation, and processing
    virtual void playTurn() = 0;

    // Returns true when the game has reached a win or lose condition
    virtual bool isGameOver() const = 0;

    // Displays the current game state to the user
    virtual void displayStatus() const = 0;

    // Virtual destructor ensures correct cleanup for derived classes
    virtual ~GameBase() {}
};

#endif
