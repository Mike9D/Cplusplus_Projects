//
//  main.cpp
//  playersOnTeam
//
//  Created by Ryan Munguia on 6/27/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//  MaxPlayers - determine if there are not enough, too many, or just right for the number of players on a team
//  CISS054 C/C++ Programming

#include <iostream>
using namespace std;

int main(int argc, const char * argv[])
{
    int teamSize;
    int playersOnTeam;
    int morePlayersNeeded;
    int extraPlayers;
    
    //Input the data
    cout << "How many players should be on the team?  ";
    cin >> teamSize;
    if (cin.fail() || teamSize < 1)
    {
        cout << "Illegal entry for team size, please try again" << endl;
        return 1; //indicates an error
    }
    cout << "How many players are on the team? ";
    cin >> playersOnTeam;
    if (cin.fail() || playersOnTeam < 1)
    {
        cout << "Illegal entry for players on the team? " << endl;
        return 1; //Indicated error
    }
    
    //Process the output
    if (playersOnTeam < teamSize)
    {
        cout << "There are not enough players" << endl;
        morePlayersNeeded = teamSize - playersOnTeam;
        cout << morePlayersNeeded << " more players are needed" << endl << endl;
    }
    else if (playersOnTeam > teamSize)
    {
        cout << "There are too many players on your team" << endl;
        extraPlayers = playersOnTeam - teamSize;
        cout << extraPlayers << " players need to be taken off the roster" << endl << endl;
    }
    else
    {
        cout << "You have the correct number of players. Go play!" << endl << endl;
    }
    return 0;
}
