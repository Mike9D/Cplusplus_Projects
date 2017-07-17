//
//  Student.h
//  StudentClass
//  CIS-55 C/C++ Programming
//
//  Created by Ryan Munguia on 7/16/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#ifndef Student_h
#define Student_h

// Student.h
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int IdNumber;
    double gpa;
    string major;
public:
    // constructors
    Student();  // default constructor
    Student(string n, int id, double g, string m);
    
    //mutators and accessors
    void setName(string n);
    string getName();
    void setIdNumber(int id);
    int  getIdNumber();
    void setGpa(double g);
    double getGpa();
    void setMajor(string m);
    string getMajor();
};



#endif /* Student_h */


