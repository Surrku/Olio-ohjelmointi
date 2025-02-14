#include "student.h"
#include <iostream>

using namespace std;

student::student(string name, int age) : name(name), age(age) {}

void student::setAge(int age)
{
    this->age=age;
}

void student::setName(string name)
{
    this->name=name;
}

string student::getName() const
{
    return name;
}

int student::getAge() const
{
    return age;
}

void student::printStudentInfo() const
{
    cout << "Name: " << name << ", age: " << age << endl;
}
