#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H
#include<iostream>
#include<string>
using namespace std;

class StudentDatabase
{
    string studentFirstName;
    string studentLastName;
    int studentNumber;
    string studentBlooadGRoup;
    string studentAddress;
    string studentContactNo;

public:

    StudentDatabase();
    void newStudentInformation();
    void getStudentList();
    void getStudentInformation();

    int getStudentNumber();
};

#endif // STUDENTDATABASE_H
