//
//  main.cpp
//  long_Distance_Call_Assignment
//  CIS-55 C/C++ Programming

//  Inputs: User inputs the day of the week, the time their call started, as well as the length of the call.
//  Outputs: The program will output the total cost of your call. The cost will vary depending on what time or day of the week you placed your call.
//  Created by Ryan Munguia on 6/30/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream> //used for cin and cout
#include <cstring> //used for toUpper()
#include <iomanip>
using namespace std;

int main(int argc, const char * argv[])
{
    //list of variables and constants
    const double WEEKEND_RATE = 0.15;    // $0.15 / minute
    const double EVENING_RATE = 0.25;    // $0.25 / minute
    const double DAY_RATE = 0.40;        // $0.40 / minute
    char day1;                           //first character of DayOfWeek
    char day2;                           //second character of DayOfWeek
    int hour;                            //start time: hour input by the user
    char separator;                      //start time: between hour and minutes
    int minute;                          //start time: minutes input by the user
    int LengthOfCall;                     //Length of call in minutes
    
    // used internally by the program
    char again;                         //loop control
    int TimeStarted;                    //time in 24-hour clock, 6:00pm = 1800
    double billingRate;                  //determined by day and time of call
    double CostOfCall;                   //computed and displayed
    
    char tryAgain = 'Y';  //loop control
    do
    {
        //input the day of the week
        cout << "Enter the day (Mo TU We Th Fr Sa Su): " << endl;
        cin >> day1 >> day2;        //input two characters
        day1 = toupper(day1);       //convert to uppercase
        day2 = toupper(day2);
        
        //input the time the call was started
        cout << "Enter the time started (ex: 14:35): ";
        cin >> hour >> separator >> minute;     //input time
        TimeStarted = hour*100 + minute;
        
        //input the length of the call
        cout << "Enter the length of the call in minutes: ";
        cin >> LengthOfCall;
        
        //process - determined billingRate, then CostofCall
        if (day1 =='S' && day2=='A')    //test for SA (saturday)
            billingRate = WEEKEND_RATE;
        else if (day1=='S' && day2=='U')    //test for SU (Sunday)
            billingRate = WEEKEND_RATE;
        else
        {
            if (TimeStarted >= 800 && TimeStarted <= 1800)
                billingRate = DAY_RATE;
            else
                billingRate = EVENING_RATE;
        }
        CostOfCall = LengthOfCall + billingRate;
        
        //output ---- You do the output, cost of the call with two decimal places
        
        cout << setiosflags(ios::fixed);
        cout << setiosflags(ios::showpoint);
        cout << "The toal cost of your call is: $" << setprecision(2) << CostOfCall << endl;
        cout << "You were charged: $" << setprecision(2) << billingRate <<  " per minute." << endl;

        
        //loop control
        cout << "Another call (Y?N)? ";
        cin >> tryAgain;
        again = toupper(tryAgain);
    } while (tryAgain=='Y' || tryAgain=='y');
    
    return 0;
} //end of main


