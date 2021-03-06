//
//  main.cpp
//  Vector Simulator
//  CIS-55 C/C++ Programming

//  Inputs: The prgram begins and the user is asked to choose betweem 1-4 options. Depending on the selection, the user can Display the list of names in the Array(1),add names to the array(2), delete names in the array(3), or quit the program(4).

//  Outputs: Depending on the selection made, the program will display the list of names in the Array(1),add names to the array(2), delete names in the array(3), or quit the program when asked to.
//
//  Created by Ryan Munguia on 7/15/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include<iostream>
#include<string>

using namespace std;
/*
 This function should create a new dynamic array one element larger than
 dynamicArray, copy all elements from dynamicArray into the new array, add the
 new entry onto the end of the new array, increment size, delete dynamicArray,
 and return the new dynamic array.
 */
string* addEntry(string *dynamicArray, int &size, string newEntry);
/*
 This function should search dynamicArray for entryToDelete. If not found, the
 request should be ignored and the unmodified dynamicArray returned. If found,
 create a new dynamic array one element smaller than dynamicArray. Copy all
 elements except entryToDelete into the new array, delete dynamicArray,
 decrement size, and return the new dynamic array.
 */
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete);
// Displays the list of names in the array list
void displayArray(string *dynamicArray, int &size);
int main()
{
    int myarraysize = 5;
    int nm=0;
    int number = 0;
    int option = 0;
    string firstname = "";
    string *names;
    names = new string[myarraysize];
    names[nm++] = "Ryan";
    
    names[nm++] = "Charlie";
    
    names[nm++] = "Kelsey";
    
    names[nm++] = "Bernie";
    
    names[nm++] = "Moo";
    cout << endl;
    // Menu with option to operate on Arraylist
    cout << "1.Display names in the array  " << endl;
    cout << "2.Add names into the array    " << endl;
    cout << "3.Delete name in the array    " << endl;
    cout << "4.To quit the program         " << endl;
    cin >> option;
    while (option != 4) {
        
        switch (option)
        {
            case 1:
            {
                cout << "******************************************************" << endl;
                cout << "Initial List:" << endl;
                displayArray(names, myarraysize);
                cout << "******************************************************" << endl;
                cout << endl;
                system("pause");
                break;
            }
            case 2:
            {
                //Prompt user to enter the name they want to add to list
                cout <<" Enter the name to  add to list" << endl;
                cin.ignore();
                getline(cin, firstname);
                if (firstname == "")
                {
                    cout << " Since you did not enter a name you will be returnng to the main menu" << endl;
                }
                else
                {
                    cout << "******************************************************" << endl;
                    cout << " The array list after entering the name :" <<firstname<< endl;
                    names = addEntry(names, myarraysize, firstname);
                    displayArray(names, myarraysize);
                    cout << "******************************************************" << endl;
                }
                system("pause");
                break;
            }
            case 3:
            {
                cout << endl;
                cout << "******************************************************" << endl;
                cout <<  "Original list" << endl;
                displayArray(names, myarraysize);
                cout << "******************************************************" << endl;
                //Prompt user to enter the number element or position of the name to delete
                cout << "Select the name you want to delete by entering its number" << endl;
                cin >> number;
                if (number >= myarraysize || number < 0)
                {
                    cout << "******************************************************" << endl;
                    cout << "The number you selected does not exist for the name in arraylist" << endl;
                }
                else
                {
                    cout << "******************************************************" << endl;
                    cout << "The array list after deleting data:" << names[number] << endl;
                    names = deleteEntry(names, myarraysize, names[number]);
                    displayArray(names, myarraysize);
                    cout << "******************************************************" << endl;
                }
                system("pause");
                break;
            }
            default:
            {
                cout << "invalid selection";
                cout << endl;
                system("pause");
            }
        }
        system("cls");
        
        cout << "******************************************************" << endl;
        cout << "1.Display names in the array  "<< endl;
        cout << "2.Add names into the array    "<< endl;
        cout << "3.Delete name in the array    "<< endl;
        cout << "4.To quit the program         "<< endl;
        cin >> option;
    }
    
    
    system("pause");
    return 0;
}
string* addEntry(string *dynamicArray, int &size, string newEntry){
    // create a new dynamic array one element larger than	dynamicArray,
    string *newArrayEntry = new string[size + 1];
    
    // copy all elements from dynamicArray into the new array, add the 	new entry onto the end of the new array, increment size, delete dynamicArray,
    //	and return the new dynamic array
    for (int i = 0; i < size; i++)
    {
        newArrayEntry[i] = dynamicArray[i];
    }
    
    // add the new entry onto the end of the new array
    newArrayEntry[size] = newEntry;
    
    // increment size
    size++;
    
    // delete the old dynamicArray
    delete[] dynamicArray;
    
    // and return the new array
    return newArrayEntry;
}
string* deleteEntry(string *dynamicArray, int &size, string entryToDelete){
    // conditional vale to stop when match is found
    int breakout = 0;
    // create a new dynamic array 1 element smaller than dynamicArray
    string *newArrayAfterDelete = new string[size - 1];
    
    // copy all elements from dynamicArray into new array
    for (int i = 0; i < size - 1; i++)
    {
        if (dynamicArray[i] != entryToDelete)
            newArrayAfterDelete[i] = dynamicArray[i];
        else
        {
            breakout = i;
            for (int i = breakout; i < size - 1; i++)
                newArrayAfterDelete[i] = dynamicArray[i + 1];
        }
    }
    
    size--;
    
    // delete the old dynamicArray
    delete[] dynamicArray;
    
    // and return the new array
    return newArrayAfterDelete;
}
void displayArray(string *dynamicArray, int &size){
    int j = 0;
    // Display the contents of the current dynamicArray at runtime
    for (j = 0; j < size; j++)
        cout << j << ": " << dynamicArray[j] << endl;
}
