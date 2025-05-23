// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1b
// 
// response.cpp
// Implementation of the Response class that stores the result of a guess
// Includes constructors, setters, getters, and overloaded operators

#include "response.h"
#include "code.h"
#include <iostream>
#include <vector>

using namespace std;

Response::Response(int length)
    : correctDigits(0),
    incorrectDigits(0)
{
    // Initialize a Response object with zero correct and incorrect digits
}

Response::Response(const Code& correctCode, const Code& guessedCode)
    : correctDigits(correctCode.checkCorrect(guessedCode)),
    incorrectDigits(correctCode.checkIncorrect(guessedCode))
{
    // Initialize Response based on comparing the correct code with a guess, 
    // Not necessary from the current Mastermind use cases but adds the possibility for a new feature
}

void Response::setResponse(int correct, int incorrect)
{
    // Set the number of correct and incorrect digits in the response from the inputs given
    correctDigits = correct;
    incorrectDigits = incorrect;
}

vector<int> Response::getValues() const
{
    // Return a vector containing correct and incorrect digit counts
    return { correctDigits, incorrectDigits };
}

bool Response::operator==(const Response& rhs) const
{
    // Compare two Response objects for equality based on correct and incorrect digits
    vector<int> self_values = getValues();
    vector<int> other_values = rhs.getValues();

    return (self_values[0] == other_values[0]) && (self_values[1] == other_values[1]);
}

ostream& operator<<(ostream& ostr, const Response& r)
{
    // Output the response details to the stream
    ostr << "\nCorrect digits: " << r.correctDigits << " ; Incorrect digits: " << r.incorrectDigits << "\n";
    return ostr;
}
