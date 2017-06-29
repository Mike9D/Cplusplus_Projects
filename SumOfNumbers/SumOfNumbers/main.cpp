//
//  main.cpp
//  SumOfNumbers
//
//  Created by Ryan Munguia on 6/27/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//
//  Inputs: Enter 10 numbers
//  Outputs: sum of odd numbers, even numbers and all numbers
//  CIS054 C/C++ Programming
//  Ryan Munguia
//  June 27th, 2017

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    int sumOfOddNumbers = 0;
    int sumOfEvenNumbers = 0;
    int sumOfAllNumbers = 0;
    double averageOfAllNumbers = 0.0;
    
    int number;
    int inputCounter = 0;
    while (inputCounter < 10) //count from 0-9
    {
        cout << "Enter a number: ";
        cin >> number;
        
        if(number % 2 == 1) //odd number
            sumOfOddNumbers += number;
        else //even number
            sumOfEvenNumbers += number;
        
        // also add the total of all numbers
        sumOfAllNumbers += number;
        averageOfAllNumbers = sumOfAllNumbers/10.0;
        
        //keep count of how many numbers were entered
        inputCounter++;
        //end of while loop
    }
    
    // display the results
    cout << "Sum of Odd Numbers: " << sumOfOddNumbers << endl;
    cout << "Sum of Even Numbers: " << sumOfEvenNumbers << endl;
    cout << "Sum of All Numbers: " << sumOfAllNumbers << endl;
    cout << "The average of ALL Numbers: " <<averageOfAllNumbers << endl;
    
    cout << endl;
    
    
    return 0;
}
