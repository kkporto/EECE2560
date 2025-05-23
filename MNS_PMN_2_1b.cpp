// Niki Manolis, Sophia Nguyen, Maria Clara Porto
// Project 1b
// 
// Mastermind_hw1_b.cpp : This file contains the 'main' function to run 
// the mastermind game, create a secret code, and test guesses.
//
// The extra credit has also been completed! Its implementation can be seen throughout
// the playGuess() and humanGuess() functions



#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "code.h"
#include "response.h"
#include "mastermind.h"



using namespace std;


int main()
{



    Mastermind round1;
    round1.playGame();


    return 0;
    cout << "Press Enter to exit";
    cin.ignore();
    cin.get();



}

