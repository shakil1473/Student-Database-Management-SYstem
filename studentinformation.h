#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H
#include<iostream>
#include<string>
#include "studentDatabase.h"

using namespace std;

class StudentInformation
{
public:
    int position = (-1)*static_cast<int>(sizeof(StudentDatabase));
    int dataFound = 0;
    StudentInformation();
    void addNewStudent();
    void showAllStudents();
    void showStudentInformation();
    void editStudenetInformation();
    void removeStudentInformation();

};

#endif // STUDENTINFORMATION_H
