//
//  main.cpp
//  Fast Food Restaurant Lab Assignment

//  Inputs: User enters a falafel food truck and is prompted to enter a 'F', 'S', 'X' or a 'T' to create their order (there are only 3 different options on the menu, Falafel, Soda, and Extras).
//  Outputs: After the user clicks 'T' for total, the program will calculate the total price of the person's order and will show you the price before and after tax is applied.
//
//  Created by Ryan Munguia on 7/4/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cctype>
#include <iomanip>
void DisplayMenu();     //Display the menu
using namespace std;


int main(int argc, const char * argv[])
{
    double total = 0.0;
    double total_wTax = 0.0;
    double price;
    char selection;
    const double TAX_RATE = 0.087;
    int falafel = 0;
    int soda = 0;
    int extras = 0;
    
    do
    {
        DisplayMenu();
        price = 0;
        cout << "Make your selection (FSXT): ";
        cin >> selection;
        switch ( toupper(selection))
        {
             case 'F':
                price = 5.15;
                falafel += 1;
                break;
            case 'S':
                price = 2.24;
                soda += 1;
                break;
            case 'X':
                price = 1.57;
                extras += 1;
                break;
            case 'T':
                break;
            default:
                cout << "Illegal selection, please try again."  << endl;
        }
        total += price;
        total_wTax = total + (total * TAX_RATE);
    } while (selection != 'T' && selection != 't');
    
    cout << "The total is $" << total << endl;
    cout << "The total with tax is $" << setprecision(2) << total_wTax << endl;
    cout << "You ordered: " << falafel << " falafel(s), " << soda << " soda(s), " << extras << " extra(s)." << endl;
    return 0;
}

void DisplayMenu()
{
    cout << endl;   //blank line before the start of menu
    cout << "F = falafel $5.15" << endl;
    cout << "S = soda $2.24" << endl;
    cout << "X = extras $1.57" << endl;
    cout << "T = total" << endl;
}
