//
//  main.cpp
//  StudentClass
//  CIS-55 C/C++ Programming

//  Inputs: The program takes in an array of students. This array includes the student's name, their ID number, their GPA, as well as their major.

//  Outputs: Given the array of students, the program will calculate the average GPA of all the students.

//  Created by Ryan Munguia on 7/16/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

// Student_Class.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "Student.h"
#include<iomanip>
using namespace std;

// define an array of students
Student CIS054[] = {
    Student ("Joe Williams", 44536, 3.4, "CIS "),
    Student ("Sally Washin", 55458, 3.7, "Math"),
    Student ("Fred MacInto", 66587, 2.9, "Engl"),
    Student ("Ned Martinez", 67892, 3.5, "Biol"),
    Student ("Dan  McElroy", 77777, 3.0, "Busn"),
    Student ("Thinh Nguyen", 73657, 3.6, "MIS ")
};


int main(int argc, char* argv[])
{
    int NumberOfStudents = sizeof(CIS054)/sizeof(Student);
    cout << "      ID #         NAME       MAJOR" << endl;
    cout << "==================================================" << endl;
    // Display the header line
    // List all the students in the course
    for (int i=0; i<NumberOfStudents; i++)
        cout << setw(5) << "  " << CIS054[i].getIdNumber() << setw(5) << "  " << CIS054[i].getName() << setw(5) << "  " << CIS054[i].getMajor()<< endl;
    cout << endl;   // blank line after displaying the student names
    
    // compute the average gpa of all the students
    double total=0;
    for (int i=0; i<NumberOfStudents; i++)
        if (CIS054[i].getGpa() == 0)
        {
            cout << "***************************************************************" << endl;
            cout << "There was an illegal GPA detected. GPA must be from 0.0 to 4.0. As a result, the incorrect GPA was set to zero and it brought down the average. Please correct."  << endl;
        }
        else
            total += CIS054[i].getGpa();
    double average = total / NumberOfStudents;
    cout << "***************************************************************" << endl;
    cout << "The average GPA of all the students is " << average << endl << endl;
    return 0;
}

