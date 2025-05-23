// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1b
// 
// mastermind.cpp
// Implementation of the Mastermind class that manages game logic
// Includes constructors, input/output handling, and game flow control

#include "mastermind.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>


#include <limits> // for numeric_limits

using namespace std;

Mastermind::Mastermind() :
    secretCode(5, 10),
    correctResponse(5)
{
    // Generate a random secret code with default length 5 and range 10, 
    // uses n and m as length and range respectively if specified.
    secretCode.generateRandom();

    // Initialize correctResponse with length number of correct and 0 incorrect digits
    correctResponse.setResponse(5, 0);
}

Mastermind::Mastermind(int n, int m) :
    secretCode(n, m),
    correctResponse(n)
{
    // Generate a random secret code with length n and range m specified by user
    secretCode.generateRandom();

    // Initialize correctResponse with length number of correct digits and 0 incorrect digits
    correctResponse.setResponse(n, 0);
}

void Mastermind::printSecretCode()
{
    // Print the secret code to the console, optional for testing or 
    // revealing code when losing game
    cout << "\nThis is the secret code:   ";
    secretCode.printCode();
}

Code Mastermind::humanGuess()
{
    // Prompt user to enter their guess code digit by digit
    // Creates vector object to hold each digit and return it as Code type 
    // if all digits from input were valid


    vector<int> humanGuessVector(secretCode.length);

    cout << "\n\nEnter your next guess:\n";
    
    int guessDigit, attempts = 0;

    for (int i = 0; i < secretCode.length; i++)
    {

        while (true)
        {
            cout << "Enter the digit of index " << i << ": ";
            cin >> guessDigit;

            // When not input is a proper integer and within range [0, length-1]
            if (!cin.fail() && guessDigit >= 0 && guessDigit < secretCode.range)
            {
                humanGuessVector[i] = guessDigit;
                break;
            }
            else
            {
                cin.clear(); // clear error flags and discard an invalid input
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

                cout << "Invalid input. Please enter an integer between 0 and " << secretCode.range - 1 << ".\n";
                attempts++;

                // Determines a maximum number of attempts that is allowed to stop code from running forever
                if (attempts >= 10)
                {
                    codeExit = true;
                    break;
                }
            }
        }

        if (codeExit)
            break;
    }

    // Create a Code object from the guess vector that has been 
    // approved by error handling above
    Code humanCode(humanGuessVector);

    return humanCode;
}

Response Mastermind::getResponse(const Code& guessCode)
{
    // Increment guess counter each time this function is called
    guessesCounted++;

    // Check amount of correct and incorrect digits by comparing secret and guess code
    int correctDigits = secretCode.checkCorrect(guessCode);
    int incorrectDigits = secretCode.checkIncorrect(guessCode);

    // Create a Response object to store the results
    Response guessResponse;
    guessResponse.setResponse(correctDigits, incorrectDigits);

    return guessResponse;
}

bool Mastermind::isSolved(const Response& responseGuess) const
{
    // Returns true if the passed response matches the correctResponse
    return (correctResponse == responseGuess);
}

void Mastermind::playGame()
{
    cout << "A new Mastermind game has begun! \nYou have 10 attempts to guess a secret code... \n";

    // Start the game by generating a new secret code from default settings and 
    // printing it to the screen, as well as initializing a response to keep track of 
    // the user's progress while playing

    secretCode.generateRandom();
    printSecretCode();

    bool isCodeSolved = false;
    Response secretResponse;

    Code gameGuess;

    // Loop until the code is solved or maximum allowed guesses has been reached
    while (!isCodeSolved && (guessesCounted < 10))
    {
        gameGuess = humanGuess();

        if (codeExit == true) {

            // Case where over 10 invalid inputs have been attempted finishes the game round
            // This case gets flagged by the internal codeExit bool
            cout << "Invalid guess was attempted too many times. The game is exiting. \n";
            printSecretCode();

            return;

        }

        secretResponse = getResponse(gameGuess);

        // Message to show code input and the response it received
        // when compared to secret code. This feedback is shown even if code has been cracked

        cout << "\nWith attempt number " << guessesCounted << " you have loaded the code \n";
        gameGuess.printCode();
        cout << "\nIts response is: ";
        cout << secretResponse;

        isCodeSolved = isSolved(secretResponse);
    }

    if (isCodeSolved)
    {
        cout << "\n\nYou have solved the code in " << guessesCounted << " attempts!\n";
    }
    
    else {
        cout << "\n\nYou have used all your 10 attempts and not solved the code ...\n";
        cout << "Better luck next time! Here is the secret code! \n";
        printSecretCode();

    }

    return;

}

