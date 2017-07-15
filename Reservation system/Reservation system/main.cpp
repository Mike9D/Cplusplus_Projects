//
//  main.cpp
//  Reservation system
//  CIS-55 C/C++ Programming

//  Inputs: The program starts and prompts the user to input an int for the number of rows and an int for the number of seats on each row. Once the array of seats is displayed, the program will prompt the user to select a seat to claim. After each seat selection the program will indicate it is now taken as well as ask the user if they want to select another seat.

//  Outputs: Depending on what the user selects for the amount of rows and seats, the program will output an array of seats. And if the user elects to claim more than seat, the program will continue to track and display the available seats in array format and in senetence format until there are none available left.

//  Created by Ryan Munguia on 7/13/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

// Function declarations (prototypes)
char ** CreateArrayOfSeats (int NumberOfRows, int seats);
void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int seats);
void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int seats);

int main(int argc, char* argv[])
{
    char **ArrayOfSeats;
    int NumberOfRows;
    int NumberOfSeats;
    char rowSelection;  // 1 to max NumberOfRows, input from the user
    char seatSelection; // 'A' to max seats, input from the user, convert to a number
    int row;    // index into ArrayOfSeats, 0 to NumberOfRows-1
    int seat;   // index into ArrayOfSeats, 0 to seats-1
    int totalSeats;  //this variable is used to keep count of the amount of seats available.
    char answer = 'Y';
    int seatsTaken = 0;
    
    // get the number of NumberOfRows and seats from the user
    cout << "Enter the number of NumberOfRows: ";
    cin  >> NumberOfRows;
    cout << "Enter the number of seats on each row: ";
    cin  >> NumberOfSeats;
    cout << "Number of rows: "<< NumberOfRows << endl;
    cout << "Number of seats: " << NumberOfSeats << endl;
    totalSeats = NumberOfSeats*NumberOfRows;
    cout << "The total number of seats available is: " << totalSeats << endl;
    cout << "******************************************************" << endl;
    
    
    ArrayOfSeats = CreateArrayOfSeats(NumberOfRows, NumberOfSeats);
    InitializeSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    DisplayArrayOfSeats  (ArrayOfSeats, NumberOfRows, NumberOfSeats);
    
    do
    {
        
        cout << endl << "Enter a seat selection" << endl << "  (example 5F -or- 00 to quit): ";
        cin  >> rowSelection;       // get row from the user
        cin  >> seatSelection;      // get the seat from the user
        seatSelection = toupper(seatSelection); // convert to upper case
        row = rowSelection - '1';     // count from zero to work with the array
        seat = seatSelection - 'A';   // convert 'A' to 0, 'B' to 1, 'C' to 2, etc.
        totalSeats = NumberOfRows*NumberOfSeats;
    
        if (rowSelection=='0')
        {
            cout << "******************************************************" << endl;
            cout << "Row number must be greater than 0, please try again." << endl;
            cout << "******************************************************" << endl;
            continue;                 // skip the rest of the loop
        }
        else if (row > NumberOfRows)
        {
            cout << "******************************************************" << endl;
            cout << "There are not that many rows, please try again." << endl;
            cout << "******************************************************" << endl;
            break;
        }
        else if (seat > NumberOfSeats)
        {
            cout << "******************************************************" << endl;
            cout << "There are not that many seats, please try again." << endl;
            cout << "******************************************************" << endl;
            break;
        }
        else if (ArrayOfSeats[row][seat] == '-')
        {
            cout << "******************************************************" << endl;
            cout << "The seat you selected has already been taken." << endl;
            cout << "******************************************************" << endl;
            break;
        }
        else if (seatsTaken == totalSeats)
        {
            cout << "********" << "There are " << totalSeats-seatsTaken << " left available. Sorry!" << "********"<< endl;
            break;
        }
        else
            ArrayOfSeats[row][seat] = '-';
            seatsTaken++ ;
            cout << "********" << "There are " << totalSeats-seatsTaken << " left available." << "********"<< endl;
        
        
        DisplayArrayOfSeats (ArrayOfSeats, NumberOfRows, NumberOfSeats);
        
        cout << "Do you want to select another seat (y/n)? ";
        cin >> answer;
        answer = toupper(answer);
    } while(seatsTaken != totalSeats && answer == 'Y');
    
    
    
    MemoryCleanup (ArrayOfSeats, NumberOfRows, NumberOfSeats);   // return the memory that was allocated
    
    if (seatsTaken == totalSeats)
    {
        cout << "******************************************************" << endl;
        cout << "No more seats, please try again another time. Bye!" << endl;
        cout << "******************************************************" << endl;
    }
    else
        cout << "******************************************************" << endl;
        cout << "Thanks for purchasing, goodbye!" << endl;
        cout << "******************************************************" << endl;
    
    char buff[100];
    cin.getline (buff, 100);
    return 0;
}

char **CreateArrayOfSeats (int NumberOfRows, int seats)    // ** means pointer to pointers
{
    char **ArrayOfSeats;
    ArrayOfSeats = new char*[NumberOfRows];          // create an array of pointers for the NumberOfRows
    for(int r = 0; r < NumberOfRows; r++)
        ArrayOfSeats[r] = new char[seats];   // create an array of seats for each row
    return ArrayOfSeats;                     // return pointer to the array back to the main program
}

void InitializeSeats (char **ArrayOfSeats, int NumberOfRows, int seats)
{
    for (int r=0; r<NumberOfRows; r++)          // initialize the data for each row
    {
        for (int s=0; s<seats; s++)
            ArrayOfSeats[r][s] = 'A' + s;    // put 'A' 'B' 'C' etc in each row
    }
}

void DisplayArrayOfSeats (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)              // for each row
    {
        cout.width(2);
        cout << r+1 << ' ';                 // Display row numbers starting from 1
        for (int s=0; s<NumberOfSeats; s++)
            cout << ArrayOfSeats[r][s] << ' ';   // Display info for each seat
        cout << endl;                       // new line after each row
    }
}

void MemoryCleanup (char **ArrayOfSeats, int NumberOfRows, int NumberOfSeats)
{
    for (int r=0; r<NumberOfRows; r++)
        delete [] ArrayOfSeats[r];   // delete each row of seats individually
    delete [] ArrayOfSeats;          // delete the row array
}
