#ifndef STUDENTDATABASE_H
#define STUDENTDATABASE_H
#include<iostream>
#include<string>
using namespace std;

class StudentDatabase
{
    string studentFirstName;
    string studentLastName;
    string studentNumber;
    string studentBlooadGRoup;
    string studentAddress;
    string studentContactNo;

public:
    StudentDatabase();
    void newStudentInformation(string firstName,string lastName,string studNo,string bloodGroup,string address,string contactNo);

    string getStudentFirstName();
    string getStudentLastName();
    string getStudentID();
    string getStudentBlooadGRoup();
    string getStudentAddress();
    string getStudentContactInfo();

};

#endif // STUDENTDATABASE_H
