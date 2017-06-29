//  main.cpp
//  Compute Pi Assignment
//  CIS-55 C/C++ Programming

//  Enter the amount of terms that you want to compute for PI
//  Inputs: User inputs amount of terms to compute
//  Outputs: The computed and difference of PI.
//
//
//  Created by Ryan Munguia on 6/28/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream> //for cin and cout
#include <iomanip>  //digits past decimal
#define _USE_MATH_DEFINES   //may help get M_PI
#include <cmath>
#include <math.h>    //math functions and constants
using namespace std;

int main(int argc, const char * argv[])
{
    double numerator= 4.0;
    double denominator = 1.0;
    double fraction = 1.0;
    double pi = 0.0;
    int terms;          //read from user
    
    cout << "How many terms do you want to compute PI? ";
    cin >> terms;
    
    for (int i =1; i<= terms; i++)
    {
        fraction = numerator/denominator;
        if (i % 2)      //determine if loop count is odd or even
            pi += fraction; //add fraction to pi if loop count is ODD
        else
            pi -= fraction; //subtract from pi if loop count is EVEN
        denominator += 2;   //denominator will be 1,3,4,7,9, etc.
    
    }
    // Set flags to display a set number of digits past the decimal
    cout << setiosflags(ios::fixed) << setiosflags(ios::showpoint);
    cout << "PI = " << pi << endl;
    cout << "Computed PI = " << setprecision(10) << pi << endl;
    cout << "M_PI = " << M_PI << endl;
    cout << "Difference = " << setprecision(10) << fabs(pi - M_PI) << endl;
    system("PAUSE");    //stop the screen from disappearing
    return 0;
}
