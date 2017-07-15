//
//  main.cpp
//  String Reversal
//
//  Created by Ryan Munguia on 7/12/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

string reverse(char word[20]);

int main(int argc, char* argv[])
{
    char Cstring[20];
    cout<<"enter a word: ";
    cin>>Cstring;
    string results = reverse(Cstring);
    cout <<results << endl;
}

string reverse(char word[20])
{
    char a='a';
    char b='b';
    char *front=&a;
    char *rear=&b;
    for (int i=0;i< (strlen(word)/2);i++)
    {
        front[0]=word[i];
        rear[0]=word[strlen(word)-1-i];
        word[i]=*rear;
        word[strlen(word)-1-i]=*front;
    }
    return word;
}
