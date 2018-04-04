#include "Studentinformation.h"
#include "StudentDatabase.h"

#include<iostream>
#include<string>
#include<fstream>
#include<conio.h>
#include<ctime>

using namespace std;

StudentInformation::StudentInformation()
{

}
void StudentInformation::addNewStudent(){

    StudentDatabase studentDatabase;
    ofstream saveInfo;
    saveInfo.open("studentInformation.dat",ios::binary | ios::app);


    studentDatabase.newStudentInformation();

    saveInfo.write(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase));
    saveInfo.close();

    cout<<"Information has been successfully"<<endl;
}

void StudentInformation::showStudentsList(){

    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;

    StudentDatabase studentDatabase;
    ifstream showInfo;
    showInfo.open("studentInformation.dat",ios::binary);
    if(!showInfo){
        cout<<"error occured.."<<endl;
        cout<<"Press any key......."<<endl;
        return;
    }

    cout<<"\t\tStudent Name   "<<"\t\t\t"<<"Student Number"<<endl;
    cout<<"\t\t---------------"<<"\t\t\t"<<"---------------"<<endl;
    while (showInfo.read(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase))) {

        studentDatabase.getStudentList();
    }
    showInfo.close();
}

void StudentInformation::showStudentInformation(){

    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;

    StudentDatabase studentDatabase;
    ifstream showInfo;
    showInfo.open("studentInformation.dat",ios::binary);
    if (!showInfo) {
            cout << "error occurred" << endl << "Press any key..." << endl;
            return;
        }
    cout<<"First Name "<<"\t"<<"Last Name "<<"\t"<<"Student Number "<<"\t"<<"Blood Group "<<"\t"<<"Address  "<<"\t\t"<<"Contact No"<<endl;
    cout<<"-----------"<<"\t"<<"----------"<<"\t"<<"---------------"<<"\t"<<"------------"<<"\t"<<"---------"<<"\t\t"<<"------------"<<endl;

    while (showInfo.read(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase))) {

        studentDatabase.getStudentInformation();

    }
    showInfo.close();

}

void StudentInformation::editStudenetInformation(){

    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;

}

void StudentInformation::removeStudentInformation(){
    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl<<endl;
    cout<<"\t\t\t Remove Student Information"<<endl;
    cout<<"\t\t\t----------------------------"<<endl;
    int studentNum;
    cout<<"Enter Student Number : "<<endl;
    cin>>studentNum;
    cin.ignore();

    StudentDatabase studentDatabase;

    ifstream showInfo;
    ofstream saveInfo;


    showInfo.open("studentInformation.dat",ios::binary);
    saveInfo.open("tempInfo.dat",ios::binary | ios::app);

    if(!showInfo || !saveInfo){
        cout<<"error occured.."<<endl;
        cout<<"Press any key......."<<endl;
        return;
    }

    while (showInfo.read(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase))) {
        if(studentDatabase.getStudentNumber()!=studentNum){
            saveInfo.write(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase));
        }
    }
    saveInfo.close();
    showInfo.close();

    remove("studentInformation.dat");
    rename("tempInfo.dat","studentInformation.dat");
}
