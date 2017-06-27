//  C++PaycheckV1.0.cpp
//  main.cpp
//  paycheck_Assignment
//  CIS-55 C/C++ Programming
//  Enter two input numbers and we will print out the total paycheck you will recieve
//  Inputs: Hours, Payrate
//  Outputs: Paycheck
//
//  Created by Ryan Munguia on 6/26/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]){
    
    //Declare the variables
    double hours;
    double payRate;
    double regHours;
    double overtimeHours;
    double regPay;
    double overtimePay;
    double paycheck;
    
    //INPUT the hours and payrate
    cout << "Enter the hours worked: ";     //prompt
    cin  >> hours;
    cout << "Enter the pay rate: ";
    cin  >> payRate;
    
    //PROCESS the date and compute the paycheck
    if (hours <= 40)
    {
        regHours = hours;
        overtimeHours = 0.0;
    }
    else
    {
        regHours = 40.0;
        overtimeHours = hours - 40; //anything over 40
    }
    regPay = regHours * payRate;
    overtimePay = overtimeHours * payRate * 1.5;
    paycheck = regPay + overtimePay;
    
    //OUTPUT the paycheck with two digits past the decimal
    cout << setiosflags(ios::fixed);
    cout << setiosflags(ios::showpoint);
    cout << "Your pay is $" << setprecision(2) << paycheck << endl;
    
    return 0;
}
