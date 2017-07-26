//
//  main.cpp
//  ADTdigitalTime
//
//  Created by Ryan Munguia on 7/24/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//
//
// C++ADTclassDigitalTime.cpp : Defines the entry point for the console application.

#include "dtime.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    // create a DigitalTime object and name it time1
    DigitalTime time1(14,22);       // initialize time to 14:22 (2:44pm)
    cout << "This is an example of a DigitalTime object. The starting time should be 14:22:" << endl;
    cout << time1 << endl << endl;  // display the time
    
    cout << "Advance by 32 minutes. The result should be 14:54" << endl;
    time1.advance(32);              // add 32 minutes. Should be 14:54
    cout << time1 << endl << endl;  // display the time
    
    cout << "Advance by 1 hour, 20 minutes. The result should be 16:14" << endl;
    time1.advance(1,20);            // add 1 hour, 30 minutes. Should be 16:14
    cout << time1 << endl << endl;  // display the time
    
    cout << "Now it's your turn. Input a new time in military 24-hour notation, dont forget the colon( : ): ";
    cin  >> time1;
    cout << time1 << endl << endl;  // display the time
    
    cout << "Advance by 5 minutes" << endl;
    time1.advance(5);                // advance 5 minutes
    cout << time1 << endl << endl;  // display the time
    
    cout << "Advance the above time by 1 hour and 20 minutes" << endl;
    time1.advance(1,20);            // add 1 hour, 30 minutes. Should be 16:14
    cout << time1 << endl << endl;  // display the time
    
    cout << "Advance the time above by 32 minutes." << endl;
    time1.advance(32);              // add 32 minutes. Should be 14:54
    cout << time1 << endl << endl;  // display the time
    
    //
    //  You need to complete the member function  interval_since  before the project is finished
    //
    cout << "The code below displays elapsed time" << endl;
    cout << "**************************************" << endl;
    int hours, minutes;
    DigitalTime time2(8, 25);
    DigitalTime time3(14, 0);
    DigitalTime time4(22, 0);
    DigitalTime time5(15, 0);
    DigitalTime time6(5, 30);
    
    //  the time difference between 8:25 and 14:00 (2:00pm) should be 5 hours, 35 minutes
    time3.interval_since(time2, hours, minutes);
    cout << "The time difference between " << time2 << " and " << time3 << " is "
    << hours << " hours and " << minutes << " minutes" << endl;
    
    //  the time difference between 22:00(10pm) and 8:25 is 10 hours 25 minutes
    time2.interval_since(time4, hours, minutes);
    cout << "The time difference between " << time4 << " and " << time2 << " is "
    << hours << " hours and " << minutes << " minutes" << endl;
    
    cout << "**************************************" << endl;
    
    //  the time difference between 5:30 and 15:00 (3:00pm) should be 9 hours, 30 minutes
    time5.interval_since(time6, hours, minutes);
    cout << "The time difference between " << time6 << " and " << time5 << " is "
    << hours << " hours and " << minutes << " minutes" << endl;
    
    //  the time difference between 15:00 and 5:30 (5:30Am) should be 14 hours, 30 minutes
    time6.interval_since(time5, hours, minutes);
    cout << "The time difference between " << time5<< " and " << time6 << " is "
    << hours << " hours and " << minutes << " minutes" << endl;
}

