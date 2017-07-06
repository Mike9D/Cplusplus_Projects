//
//  main.cpp
//  LENGTH OF LINE PROGRAM

//  Inputs: The user inputs numeric values for the X1, Y1, X2, and Y2 values. Each number that is inputted must be separated by spaces.

//  Output: The program will output the length of the line based on the values given.
//  Created by Ryan Munguia on 7/5/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>     //used by cin and cout
#include <cmath>       //used by sqrt
#include <iomanip>
using namespace std;
double LengthOfLine (double X1, double Y1, double X2, double Y2);

int main(int argc, const char * argv[])
{
    double X1, Y1, X2, Y2, length;     //declare the variables
    cout << "Enter  X1, Y1, X2, Y2 separated by spaces: ";
    cin >> X1 >> Y1 >> X2 >> Y2;
    length = LengthOfLine(X1, Y1, X2, Y2);
    cout << "The length of the line is " << setprecision(4) << length << endl;
    
    return 0;
}
double LengthOfLine (double X1, double Y1, double X2, double Y2)
{           //code for length of LengthOfLine function
    double a, b, c;     //c is the computed length of line
    a = X2 - X1;
    b = Y2 - Y1;
    c = sqrt(a*a + b*b);
    return c;
}
