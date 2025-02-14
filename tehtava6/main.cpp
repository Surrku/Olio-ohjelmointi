#include <iostream>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;


int main()
{
    int selection = 0;
    vector<student> studentList;

    do
    {
        cout << endl;
        cout << "Select" << endl;
        cout << "Add students = 0" << endl;
        cout << "Print all students = 1" << endl;
        cout << "Sort and print students according to Name = 2" << endl;
        cout << "Sort and print students according to Age = 3" << endl;
        cout << "Find and print student = 4" << endl;
        cin >> selection;

        switch (selection)
        {
        case 0:
        {
            string name;
            int age;
            cout << "Student's name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Student's age: ";
            cin >> age;

            student newStudent(name, age);
            studentList.emplace_back(newStudent);
            break;
        }

        case 1:
        {
            for (const auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        }

        case 2:
        {
            sort(studentList.begin(), studentList.end(), [](const student& a, const student& b) {
                return a.getName() < b.getName();
            });
            for (const auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        }

        case 3:
        {
            sort(studentList.begin(), studentList.end(), [](const student& a, const student& b) {
                return a.getAge() < b.getAge();
            });
            for (const auto& student : studentList)
            {
                student.printStudentInfo();
            }
            break;
        }

        case 4:
        {
            string searchStudent;
            cout << "Enter student name to search: ";
            cin.ignore();
            getline(cin, searchStudent);

            auto it = find_if(studentList.begin(), studentList.end(), [&](const student& s) {
                return s.getName() == searchStudent;
            });

            if (it != studentList.end())
            {
                it->printStudentInfo();
            }
            else
            {
                cout << "Couldn't find a student with that name" << endl;
            }
            break;
        }

        default:
            cout << "Wrong selection, stopping..." << endl;
            break;
        }
    } while (selection < 5);

    return 0;
}

