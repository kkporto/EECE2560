// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1b
// 
// response.h : This file contains the declaration of the response class to hold
// the data from correct and secret codes while playing the mastermind game.

#ifndef RESPONSE_H
#define RESPONSE_H

#include <vector>
#include <iostream>
#include "code.h"

class Response
{
public:
    // Constructor initializing with a given code length (default 5)
    Response(int length = 5);

    // Constructor that computes response based on correct and guessed Code objects
    Response(const Code& correctCode, const Code& guessedCode);

    // Set the number of correct and incorrect digits
    void setResponse(int correct, int incorrect);

    // Get a vector containing correct and incorrect digits counts
    vector<int> getValues() const;

    // Equality operator comparing two Response objects, self and other
    bool operator==(const Response& rhs) const;

    // Output stream operator to print response details
    friend std::ostream& operator<<(std::ostream& ostr, const Response& r);

private:
    int correctDigits;    // Number of digits correct and in the right position
    int incorrectDigits;  // Number of digits correct but in the wrong position
};

#endif // RESPONSE_H

