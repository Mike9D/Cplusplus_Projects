//
//  main.cpp
//  rock_paper_Scissors
//  CIS-55 C/C++ Programming

//  Inputs: User inputs their choice of R for rock, P for Paper, or S for Scissors (is not case sensitive)
//  Outputs: The winner or status of the match. Option to continue playing is prompted after each game

//  Created by Ryan Munguia on 6/29/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.

#include <iostream>
#include <cctype>

using namespace std;

int main()
{
    char playerOne;
    char playerTwo;

    char playAgain = 'y';  // loop control
    do
    {
        //player One
        cout << "**** Welcome to the Rock, paper, Scissors Game!! ****" << endl;
        cout << "player #1 - Your move, enter R P or S: " << endl;
        cin >> playerOne;
        playerOne = toupper(playerOne);
    
        cout << "***********************************************" << endl;
        cout << "player #2 - Your move, enter R P or S: " << endl;
        cin >> playerTwo;
        playerTwo = toupper(playerTwo);
    
     // the logic for the game goes here
        if (playerOne == playerTwo)
        {
            cout << "There is a tie! "<< endl;
        }
        else if (playerOne == 'R' && playerTwo == 'P')
        {
            cout << "Paper covers rock, player 2 wins!" << endl;
            cout << "*********************************" << endl;
        }
        else if (playerOne == 'R' && playerTwo == 'S')
        {
            cout << "Rock smashes scissors, player 1 wins!";
            cout << "*********************************" << endl;
        }
        else if (playerOne == 'P' && playerTwo == 'R')
        {
            cout << "Paper covers rock, player 1 wins!";
            cout << "*********************************" << endl;
        }
        else if ( playerOne == 'P' && playerTwo == 'S')
        {
            cout << "Scissors cuts paper, player 2 wins!";
            cout << "*********************************" << endl;
        }
        else if ( playerOne == 'S' && playerTwo == 'R')
        {
            cout << "Rock Breaks Scissors, player 2 wins!";
            cout << "*********************************" << endl;
        }
        else if ( playerOne == 'S' && playerTwo == 'P')
        {
            cout << "Scissors cuts paper, player 1 wins!";
            cout << "*********************************" << endl;
        }
        else{
            cout << "Incorrect letter, please enter a R, P, or S. Try again" << endl;
        }
        cout << "Do you want to play again? " << endl;
        cin >> playAgain;
            
    } while(playAgain=='Y' || playAgain=='y');
    
    return 0;
}

