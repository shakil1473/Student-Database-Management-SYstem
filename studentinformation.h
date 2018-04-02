#ifndef STUDENTINFORMATION_H
#define STUDENTINFORMATION_H
#include<iostream>
#include<string>
using namespace std;

class StudentInformation
{
public:
    StudentInformation();
    void addNewStudent();
    void showStudentsList();
    void showStudentInformation();
    void editStudenetInformation();
    void deleteStudentInformation();
};

#endif // STUDENTINFORMATION_H
