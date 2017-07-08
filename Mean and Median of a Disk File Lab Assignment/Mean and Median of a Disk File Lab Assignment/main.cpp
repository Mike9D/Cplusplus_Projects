//
//  main.cpp
//  Mean and Median of a Disk File Lab Assignment

//  Inputs: When the program starts, the user is prompted to enter the name of the data file that they would like to run. Pleaase provide file path (i.e /Users/RyanMunguia/Desktop/Balances-1.txt

//  Output: The program will analyze your file and output both the mean and median of the your provided numbers.
//
//  Created by Ryan Munguia on 7/6/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.

#include <iostream>
#include <fstream>
#include <cstdlib>  // used by the exit() functiona
using namespace std;

int main(int argc, char* argv[])
{
    // variables to control the disk file
    ifstream infile;
    char filename[200];
    // variables for fields of each record in the file
    int    acctNo = 0;
    char   acctName[100] = "";
    double acctBal = 0.0;
    // varible used to determine the median
    int recordCount = 0;
    int recordsToSkip = 0;
    double total = 0.0;
    double mean = 0.0;
    double median = 0.0;
    
    
    // ---- PART 1, Count the number of records in the file
    cout << "Enter the name of the data file: ";
    cin  >> filename;
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open --" << filename << "--, first pass" << endl;
        exit(1);
    }
    infile >> acctNo >> acctName >> acctBal;    //read first record
    while (!infile.eof())   // while not end of file
    {
        if (acctName[0] != 0)   //ignore empty records
        {
            total += acctBal;   //add up all balances
            recordCount++;
        }
        acctName[0] = 0;    //initialize to 0 to test for empty records
        infile >> acctNo >> acctName >> acctBal;
    }
    infile.close();
    cout << "**************************************************" << endl << endl;
    cout << "There are " << recordCount << " records in " << filename << endl;
    mean = total / recordCount;
    cout << "The mean value of the balance is: " << mean << endl;
    
    
    // ---- PART 2, Determine the number of records to skip
    if (recordCount %2 == 1)
        recordsToSkip = recordCount/2;      // Odd number of records
    else
        recordsToSkip = recordCount/2 - 1;  // Even number of records
    
    // ---- PART 3, open the file, skip leading records, determine the mean
    infile.open(filename);
    if (infile.fail())
    {
        cerr << "Unable to open " << filename << ", second pass" << endl;
        exit(1);
    }
    while (recordsToSkip != 0)
    {
        infile >> acctNo >> acctName >> acctBal;
        recordsToSkip--;        //count down to zero
    }
    
   // read a record from the disk
    infile >> acctNo >> acctName >> acctBal;
    if (recordCount %2 == 1)                    //Odd number of records
    {
        median = acctBal;                       //median is middle record
    }
    else
    {
        median = acctBal;                       //Even number of records
        //read the next record
        infile >> acctNo >> acctName >> acctBal;
        median = (median + acctBal) / 2;        //average of two middle values
    }
    infile.close();
    // Display the median
    cout << "The median of " << filename << " is " << median << endl << endl;
    cout << "**************************************************" << endl;
    
    return 0;
}
