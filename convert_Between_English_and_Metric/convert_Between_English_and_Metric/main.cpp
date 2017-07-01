//
//  main.cpp
//  convert_Between_English_and_Metric

//  Inputs: User is prompted to Enter E to convert English to Metric, or M to convert Metric to English or Q to quit. The user is than prompted to Enter the number of inches or number of centimeters depending on their initial selection.
//  Outputs: The program will output the conversion from inches to centimeters or vice versa. The program will continue to loop until the user inputs 'Q' to terminate the program.

//  Created by Ryan Munguia on 6/30/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cctype>       //used for the toupper function
char menuSelect();      //returns 'E' or 'M'
using namespace std;

int main(int argc, const char * argv[])
{
    double inches;
    double centimeters;
    char select;
    
    
    do {
        select = menuSelect();
        if (select == 'E')
        {
            cout << "Enter the number of inches ";
            cin >> inches;
            if (inches < 1)
            {
                cout << "Error: Number must be valid and/or a positive number. Try again" << endl;
            }
            else {
                centimeters = inches * 2.54;
                cout << inches << " inches is equal to " << centimeters << " centimers" << endl;
            }
        }
        else if (select == 'M')
        {
            cout << "Enter the number of Centimeters ";
            cin >> centimeters;
            
            inches = centimeters * 0.39;
            cout << centimeters << " centimeters is equal to " << inches << " inches" << endl;
        }
        else if (select == 'Q')
        {
            cout << "Thanks, see you later!" << endl;
        }
        else{
            cout << "Invalid Character. Only enter an 'E', 'M or 'Q'." << endl;
            
        }
    } while (select != 'Q');
    return 0;
}

char menuSelect()
{
    
    char selection;
    do {
        cout << endl; //blank line
        cout << "Enter E to convert English to Metric, or M to convert Metric to English or Q to quit: ";
        cin >> selection;
        selection = toupper(selection);     //convert to uppercase
        if (selection != 'E' && selection != 'M' && selection != 'Q')
        {
            cout << "Invalid Character. Only enter an 'E', 'M or 'Q'." << endl;

        }
    } while (selection != 'E' && selection != 'M' && selection != 'Q');     //verify legal selection
    return selection;
}
