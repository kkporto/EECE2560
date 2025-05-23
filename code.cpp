// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1a
// 
// code.cpp : This file contains the implementation of the code class
// and its member functions.


#include "code.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>



Code::Code(int n, int m)
// Constructor for the Code object. 
// Has 2 parameters n and m, for the length and range of a code, respectively.
// The code vector is resized to length n
{
	length = n;
	range = m;
	code.resize(n);
}


Code::Code(const vector<int>& vectorGuess)
// Constructor that initializes the code directly from a given vector
// Parameter vectorGuess is a const reference to a integer vector 
// containing the guessed code.
{
	//cout << "entered code generating mode from human guess\n";
	length = vectorGuess.size();
	range = 10;					       // sets fixed value of 10
	code = vectorGuess;

	//cout << "finished code generating mode from human guess\n";
}


void Code::generateRandom()
// Generates random code for a game by assigning a random value to each digit.
// Takes in no arguments and does not return anything.
{
	for (int i = 0; i < length; i++)
	{
		code[i] = rand() % range;	   // sets random digits to be in range
	}
}


int Code::checkCorrect(const Code& guess) const
// Counts how many digits in guess match the secret code in the exact position. 
// Takes in the users guess as a parameter.
// Returns an integer representing the number of digits in correct postition.
{
	int correctDigits = 0;

	for (int i = 0; i < length; i++)
	{
		if (code[i] == guess.code[i])  // if corresponding digits match
		{
			correctDigits++;		   // adds 1 to the count
		}
	}
	return correctDigits;
} // end checkCorrect



int Code::checkIncorrect(const Code& guess) const
// Counts digits that are correct but are in the wrong location.
// Takes in the users guess as a parameter.
// Returns an integer value representing the number of correct digits 
// in the wrong location.
{
	int incorrectDigits = 0;

	vector <int> unmatchedCode;
	vector <int> unmatchedGuess;

	// Group the unmatched digits from both the secret code and the guess

	for (int i = 0; i < length; i++)
	{
		if (code[i] != guess.code[i])
		{
			unmatchedCode.push_back(code[i]);
			unmatchedGuess.push_back(guess.code[i]);
		}
	}

	// In the unmatched guesses, check if it matches an unmatched code digit

	for (int i = 0; i < unmatchedGuess.size(); i++)
	{
		for (int j = 0; j < unmatchedCode.size(); j++)
		{
			if (unmatchedGuess[i] == unmatchedCode[j])
			{
				incorrectDigits++;

				// Remove matched digit to avoid recounting
				unmatchedCode.erase(unmatchedCode.begin() + j);

				break;
			}
		} // end for
	} // end for
	return incorrectDigits;
} // end checkIncorrect


void Code::printCode()  const
// Prints the code digits on a single line followed by a newline.
// No parameters, returns void.
{
	for (int i = 0; i < length; i++)
	{
		cout << code[i] << "  ";

	}
	cout << endl;
}

