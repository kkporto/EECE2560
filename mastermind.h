// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1b
// 
// mastermind.h
// Declaration of the Mastermind class which controls game flow and state

#ifndef MASTERMIND_H
#define MASTERMIND_H

#include "code.h"
#include "response.h"
#include <vector>

class Mastermind
{
public:
    // Default constructor: initializes game with default code length and range
    Mastermind();

    // Parameterized constructor: initializes game with given code length and range
    Mastermind(int n, int m);

    // Prints the secret code (for testing/debugging)
    void printSecretCode();

    // Prompts user for a guess and returns it as a Code object
    // does error handling in case user has given any inputs that are not an integer within range
    Code humanGuess();

    // Takes a guess and returns a Response object indicating correct and incorrect digits from it
    Response getResponse(const Code& guess);

    // Returns true if the game has been solved (response matches correctResponse)
    bool isSolved(const Response& responseGuess) const;

    // Main game loop: handles gameplay until solved or guesses run out
    void playGame();

private:
    // Secret code randomized that is the key to the game
    Code secretCode;

    // Response representing the correct solution (all digits correct (=length) and none are incorrect)
    Response correctResponse;

    // Count of guesses made so far, keeps track of it for playGame()
    int guessesCounted = 0;

    // Signal to invalid guess many times; triggered after 10 invalid inputs in a row
    int codeExit = false;
};

#endif // MASTERMIND_H


