//
//  Student.cpp
//  StudentClass
//  CIS-55 C/C++ Programming
//
//  Created by Ryan Munguia on 7/16/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//// Student.cpp - contains the code for the Student class member methods

#include "Student.hpp"
#include "Student.h"
#include <cctype>       // used by isalpha (test for a character)
using namespace std;

// default Student constructor
Student::Student()
{
    name = "";  // set name to an empty string
    IdNumber = 0;
    gpa = 0.0;
    major = "";  // set name to an empty string
}
// Fully qualified Student constructor
Student::Student(string n, int id, double g, string m)
{
    setName(n);         // use setName to validate data
    setIdNumber(id);    // use setIdNumber to validate data
    setGpa(g);          // use setGpa to validate data
    setMajor(m);        // use setMajor to validate data
}

//mutators and accessors
void Student::setName(string n)
{
    if ( isupper(n[0]) )   // 1st character of name must be A-Z
        name = n;
    else
        name = "***INVALID NAME ENTERED***";
}
string Student::getName()
{
    return name;
}
void Student::setIdNumber(int id)
{
    if ( id>1  && id<100000)   // must be from 0 to 100000
        IdNumber = id;
    else
        IdNumber = 0;          // indicate an illegal selection
}
int  Student::getIdNumber()
{
    return IdNumber;
}
void Student::setGpa(double g)
{
    if (g>=0.0 && g<=4.0)         // gpa must be from 0.0 to 4.0
        gpa = g;
    else
        gpa = 0;

}
double Student::getGpa()
{
    return gpa;
}
void Student::setMajor(string m)
{
    if ( isupper(m[0]) )   // 1st character of name must be A-Z
        major = m;
    else
        major = "--Bad major entered";
}
string Student::getMajor()
{
    return major;
}
