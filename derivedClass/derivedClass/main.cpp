//
//  main.cpp
//  derivedClass

//  Inputs: The following program shows an example of one main class (Person) and three derived classes(sub-classes) (Student, Teacher, and Employee).

//  Outputs: If the derived class is a teacher, the program will output the name of the teacher, the numbers of students he/she has, as well as the number of classes he/she instructs If the derived class is a student, the program will display the student’s name. as well as the number of units they are taking.
// If the derived class is an employee, the program will display the employee name, their employee ID, the amount of hours they work, their pay rate, as well as compute what they make given the amount of hours

//  Created by Ryan Munguia on 7/19/17.
//  Copyright © 2017 Ryan Munguia. All rights reserved.
//

#include <iostream>
#include <cstring>
using namespace std;

////////////// Person class Definition /////////////////
class Person {
protected:  // A derived class can access protected data
    char Name[20];
public:
    Person (char* n)
    {
        strcpy(Name, n);
    }
    virtual void print() const
    {
        cout << "Person:  " << Name << endl;
    }
};


///////////// Student class Definition //////////////
class Student : public Person  {   // access all data and functions from Person
private:
    int    units;
public:
    // Student constructor gets name from Person class
    Student (char* n, int u) : Person ( n)
    {
        units = u;
    }
    virtual void print() const
    {
        cout << "Student: " << Name << "  Units: " << units << endl;
    }
};
//////////// Teacher class Definition /////////////////
class Teacher : public Person  { // access all data and functions from Person
private:
    int    numberOfStudents;
    int	numberOfClasses;
public:
    // Teacher constructor gets 'name' from the Person class
    Teacher (char* n, int s, int c) : Person ( n)
    {
        numberOfStudents = s;
        numberOfClasses = c;
    }
    virtual void print() const
    {
        cout << "Teacher: " << Name
        << "  Students: " << numberOfStudents
        << "  Classes: " << numberOfClasses << endl;
    }
};

class Employee : public Person  { // access all data and functions from Person
private:
    int EmpID;
    double	Hours;
    double PayRate;
public:
    // Teacher constructor gets 'name' from the Person class
    Employee (char* n, int e, double h, int p) : Person ( n)
    {
        EmpID = e;
        Hours = h;
        PayRate = p;
    }
    virtual void print() const
    {
        cout << "*****************************************************" << endl;
        cout << "Employee: " << Name
        << "  Employee ID: " << EmpID
        << "  Hours: " << Hours
        << "  Pay Rate: " << PayRate << " an hour" << endl
        << Name << "gets paid $" << Hours*PayRate << " a week" << endl;
    }
};



/////////// main program ///////////////////////
int main(int argc, char* argv[])
{
    // create objects from several different types of classes
    Student s1("Joe Williams", 12);
    Student s2("Mary Smith  ", 9);
    Student s3("Tam  Nguyen ", 10);
    Student s4("Jose Chavez ", 11);
    Teacher t1("Dan McElroy ", 28, 3);
    Teacher t3("Fred Jones  ", 18, 2);
    Employee e1("Ryan Munguia ", 646464, 40, 24);
    Employee e2("Charlie Foo ", 246810, 20, 24);    // Create an array of pointers to different people
    Person *List[] = { &t1, &s2, &s3, &s4, &s2, &t3, &e1, &e2 };
    int SizeOfList = sizeof(List)/sizeof(Person*);
    
    for (int i=0; i<SizeOfList; i++)
    {
        // call the appropriate virtual print routine based
        // on the type of object being pointed to
        List[i]->print();
    }
    return 0;
}


