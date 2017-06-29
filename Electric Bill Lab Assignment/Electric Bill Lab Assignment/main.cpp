//  main.cpp
//  Electric Bill Lab Assignment
//  CIS-55 C/C++ Programming
//  Enter one number, kWh consumed, and we will print out the total amount of your electric bill
//  Inputs: User inputs kWh
//  Outputs: Electric Bill
//
//  Created by Ryan Munguia on 6/28/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[]){
    
    //Declare the variables
    double kWh;
    double base_kWh = 0.0;    //(up to 500)
    double extra_kWh;   //(over 500)
    double base_Bill;   //base_kWh * 0.27
    double extra_Bill;  //extra_kWh * 0.55
    double electric_Bill;   //base_Bill + extra_Bil
    

    //User Input
    cout << "Enter the amount of kWh used: ";
    cin  >> kWh;
    
    //Exception Handling
    try
    {
        if (!cin) // Was cin able to store into a double?
            throw 0;  // Throw the error ID
        if (kWh < 0)
            throw 0;  // Throw the error ID
        
        // Calculate and display the bill while in the Try block
        // ...
        
    } //End of the try block
    
    catch (int errID)
    {
        cout << "Error: " << errID << endl;
        cout << "kWh must be in numeric form and a positive number" << endl;
    } //End of the catch block
    
    //PROCESS the date and compute the paycheck
    if (kWh <= 500)
    {
        base_kWh = kWh;
        extra_kWh = 0.0;
    }
    else
    {
        base_kWh = 500;
        extra_kWh = kWh - 500; //anything over 500
        
    }
    base_Bill = base_kWh * 0.27;
    extra_Bill = extra_kWh * 0.55;
    electric_Bill = base_Bill + extra_Bill;
    
    //OUTPUT the paycheck with two digits past the decimal
    cout << setiosflags(ios::fixed);
    cout << setiosflags(ios::showpoint);
    cout << "Your electric bill is $" << setprecision(2) << electric_Bill << endl;
    cout << "Your amount in extra fees is $" << setprecision(2) << extra_Bill << endl;
    
    return 0;
}

