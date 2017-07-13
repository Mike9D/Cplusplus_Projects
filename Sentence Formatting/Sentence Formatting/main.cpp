//
//  main.cpp
//  Sentence Formatting
//  CIS-55 C/C++ Programming

//  Inputs: The program prompts the user to sentence.
//  This program is designed to look for four things:
//  1) Change all whitespace characters to a space
//  2) Remove multiple spaces
//  3) Capitalize the first character of the sentence
//  4) Make all other characters lower-case
//  Output: The program will output a sentence. If the program catches any of the 4 errors in your sentence, it will correct it and output appropriately.
//
//  Created by Ryan Munguia on 7/11/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cctype>
using namespace std;

int main(int argc, const char * argv[]) {
    char sentence[200];
    int i;
    
    cout << "Enter a sentence:" << endl;
    cin.getline(sentence, 200);
    
    //change all whitespace characters to a space
    for (i=0; sentence[i]; i++)
    {
        if(isspace(sentence[i]))
            sentence[i] = ' ';
    }
    
    //remove multiple spaces
    i = 0;
    while (sentence[i]!='\0')
    {
        //look for two consecutive spaces
        if (sentence[i]==' ' && sentence[i+1] ==' ')
        for (int j=i; sentence[j]; j++)
        {
            sentence[j] = sentence[j+1];
        }
        else
            i++;
    }
    
    //capitalize the first character of the sentence
    sentence[0] = toupper(sentence[0]);
    
    //make all other characters lower-case
    // to start with the 2nd character, set i=1
    for (i = 1; sentence[i]; i++)
    {
        sentence[i] = tolower(sentence[i]);
    }
    
    //display the output
    cout << "Your new sentence is: " << endl;
    cout << sentence << endl;
    return 0;
}
