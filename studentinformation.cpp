#include "Studentinformation.h"
#include "StudentDatabase.h"

#include<iostream>
#include<string>
using namespace std;

StudentInformation::StudentInformation()
{

}
void StudentInformation::addNewStudent(){

    string firstName,lastName,studentNo,bloodGroup,address,contactNo;
    StudentDatabase studentDatabase;

    cin.ignore();
    cout<<"enter first name     :";
    getline(cin,firstName);

    cout<<"enter last name      :";
    getline(cin,lastName);


    cout<<"enter student id     :";
    getline(cin,studentNo);

    cout<<"enter blood group    :";
    getline(cin,bloodGroup);

    cout<<"enter address        :";
    getline(cin,address);

    cout<<"enter contact no     :";
    getline(cin,contactNo);

    studentDatabase.newStudentInformation(firstName,lastName,studentNo,bloodGroup,address,contactNo);
}

void StudentInformation::showStudentsList(){

}

void StudentInformation::showStudentInformation(){
    StudentDatabase studentDatabase;

    cout<<"First Name   : "<<studentDatabase.getStudentFirstName()<<endl;
    cout<<"Last Name    : "<<studentDatabase.getStudentLastName()<<endl;
    cout<<"Student ID   : "<<studentDatabase.getStudentID()<<endl;
    cout<<"Blood Group  : "<<studentDatabase.getStudentBlooadGRoup()<<endl;
    cout<<"Address      : "<<studentDatabase.getStudentAddress()<<endl;
    cout<<"Contact No   : "<<studentDatabase.getStudentContactInfo()<<endl;
}

void StudentInformation::editStudenetInformation(){

}

void StudentInformation::deleteStudentInformation(){

}
