#include "StudentDatabase.h"
#include <fstream>


StudentDatabase::StudentDatabase()
{

}
void StudentDatabase::newStudentInformation(string firstName,string lastName,string studNo,string bloodGroup,string address,string contactNo){
    studentFirstName = firstName;
    studentLastName = lastName;
    studentNumber = studNo;
    studentBlooadGRoup = bloodGroup;
    studentAddress = address;
    studentContactNo = contactNo;
}

string StudentDatabase::getStudentFirstName(){
    string fristName = studentFirstName;
    return fristName;
}
string StudentDatabase::getStudentLastName(){
    string lastName = studentLastName;
    return lastName;
}
string StudentDatabase::getStudentID(){
    string studentId = studentNumber;
    return studentId;

}
string StudentDatabase::getStudentBlooadGRoup(){
    string bloodGroup = studentBlooadGRoup;
    return bloodGroup;
}
string StudentDatabase::getStudentAddress(){
    string address = studentAddress;
    return address;
}
string StudentDatabase::getStudentContactInfo(){
    string contactInfo = studentContactNo;
    return contactInfo;
}

