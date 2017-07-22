//
//  main.cpp
//  RationalTest.cpp
//
//  Created by Ryan Munguia on 7/17/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//
//  Inputs: The program takes in three rational numbers to be tested. They are placed in variables called num1, num2, and num 3. In this program, the numbers are preset under in the rationalTest.cpp under intitializeNumbers if you wish to edit.

//  Outputs: Given the inputted rational numbers for num1, num2, and num3, the program will output the code for addition, subtraction, multiplication and division.
//  The output will show a variety of outputs that include: the   –     –=    *    *=    /    /=

// Rational.cpp : Defines the entry point for the console application.
// Create a Rational class defination
//    Rational(numerator, denominator)
//
#include "Rational.h"   // double quotes = find file in project folder
#include <iostream>     // angle brackets = find file in compiler folder
using namespace std;

// function prototypes
void initializeNumbers (Rational &, Rational &, Rational &);
void displayNumbers (const char *, Rational, Rational, Rational);

int main(int argc, char* argv[])
{
    //  class    object
    //    |        |
    //    V        V
    Rational n1;
    Rational n2;
    Rational n3;
    
    cout << "Addition" << endl;
    cout << "================================================================================" << endl;
    cout << "**** n2 = n2.add(n3);  n2.display();  // n2 should become 17/12" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n2 = n2.add(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);
    cout << "n2.display() shows only n2  ";
    n2.display();           //   using the display( ) member function
    
    cout << endl << endl << "**** n1 = n2 + n3; // n1 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator+(n3);    // n2 + n3 = 3/4 + 2/3 = 9/12 + 8/12 = 17/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 += n3; // n1 and n2 should become 17/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 += n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "================================================================================" << endl;
    cout << endl;
    
    cout << "Subtraction" << endl;
    cout << "================================================================================" << endl;
    cout << "**** n1 = n2 - n3;  // n1 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 - n3;              	// n2 - n3 = 3/4 - 2/3 = 9/12 - 8/12 = 1/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 -= n3;  // n1 and n2 should be 1/12. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 -= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "================================================================================" << endl;
    cout << endl;
    
    
    cout << "Multiplication" << endl;
    cout << "================================================================================" << endl;
    cout << "**** n1 = n2 * n3; // n1 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator*(n3);    // n2 * n3 = 3/4 * 2/3 = 6/12
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 *= n3; // n1 and n2 should become 1/2. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 *= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "================================================================================" << endl;
    cout << endl;
    
    cout << "Division" << endl;
    cout << "================================================================================" << endl;
    cout << endl << "**** n1 = n2 / n3; // n1 should become 9/8. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2.operator/(n3);    // n2 / n3 = 3/4 / 2/3 = 9/8
    displayNumbers("After ", n1, n2, n3);
    
    cout << endl << "**** n1 = n2 /= n3; // n1 and n2 should become 9/8. Others unchanged" << endl;
    initializeNumbers (n1, n2, n3);
    displayNumbers("Before", n1, n2, n3);
    n1 = n2 /= n3;
    displayNumbers("After ", n1, n2, n3);
    cout << "================================================================================" << endl;
    
    cout << endl << "**** Rational number to double. 1/12 displays as 0.0833333" << endl;
    cout << "double(n2) = " << double(n2) << endl;
    cout << endl;
    return 0;
    
}

// Initialize each of the variables before testing each rational operator
void initializeNumbers (Rational &n1, Rational &n2, Rational &n3)
{
    n1 = Rational ();     //    0  no arguments
    n2 = Rational (3,4);  //   3/4
    n3 = Rational (2,3);  //   2/3
}

// Display each of the rational numbers using the friend function <<
void displayNumbers (const char *msg, Rational n1, Rational n2, Rational n3)
{
    cout << msg << " " << n1 << "\t" << n2 << "\t" << n3 << endl;
}
