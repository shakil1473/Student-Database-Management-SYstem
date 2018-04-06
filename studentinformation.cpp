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

    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;

    StudentDatabase studentDatabase;
    ofstream saveInfo;
    saveInfo.open("studentInformation.dat",ios::binary | ios::app);


    studentDatabase.newStudentInformation();

    saveInfo.write(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase));
    saveInfo.close();

    cout<<"Information has been successfully"<<endl;
}

void StudentInformation::showAllStudents(){

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
    fstream showInfo;
    cout<<"Enter student No : ";
    int studNo;
    cin>>studNo;
    cin.ignore();
    showInfo.open("studentInformation.dat",ios::binary | ios::in | ios::out);
    if (!showInfo) {
            cout << "error occurred" << endl << "Press any key..." << endl;
            return;
        }


    while (showInfo.read(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase))) {



        if(studNo == studentDatabase.getStudentNumber()){

            cout<<"First Name "<<"\t"<<"Last Name "<<"\t"<<"Student Number "<<"\t"<<"Blood Group "<<"\t"<<"Address  "<<"\t\t"<<"Contact No"<<endl;
            cout<<"-----------"<<"\t"<<"----------"<<"\t"<<"---------------"<<"\t"<<"------------"<<"\t"<<"---------"<<"\t\t"<<"------------"<<endl;
            studentDatabase.getStudentInformation();

            dataFound =1;
        }

    }
    if(!dataFound)
        cout<<"no student with the given student ID"<<endl;
    showInfo.close();

    dataFound = 0;

}

void StudentInformation::editStudenetInformation(){
    system("cls");
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl<<endl;
    cout<<"\t\t\t Edit Student Information"<<endl;
    cout<<"\t\t\t----------------------------"<<endl;

    StudentDatabase studentDatabase;
    fstream editInfo;


    cout<<"Enter student No : ";

    int studNo;
    cin>>studNo;
    cin.ignore();

    editInfo.open("studentInformation.dat",ios::binary | ios::in | ios::out);
    if (!editInfo) {
            cout << "error occurred" << endl << "Press any key..." << endl;
            return;
        }

    while (editInfo.read(reinterpret_cast<char *> (&studentDatabase),sizeof(StudentDatabase))) {

        if(studNo == studentDatabase.getStudentNumber()){

            cout<<"First Name "<<"\t"<<"Last Name "<<"\t"<<"Student Number "<<"\t"<<"Blood Group "<<"\t"<<"Address  "<<"\t\t"<<"Contact No"<<endl;
            cout<<"-----------"<<"\t"<<"----------"<<"\t"<<"---------------"<<"\t"<<"------------"<<"\t"<<"---------"<<"\t\t"<<"------------"<<endl;


            studentDatabase.getStudentInformation();

            cout<<"\t\t\t Enter new Information"<<endl;
            cout<<"\t\t\t-----------------------"<<endl;


            studentDatabase.modifyStudentInformation(studNo);


            editInfo.seekg(position,ios::cur);
            editInfo.write(reinterpret_cast<char *>(&studentDatabase),sizeof(StudentDatabase));

            cout<<"Information updated"<<endl;

            dataFound = 1;
        }

    }

    if(!dataFound)
        cout<<"no student with the given student ID"<<endl;
    editInfo.close();

    dataFound = 0;
}

void StudentInformation::removeStudentInformation(){
    system("cls");
      cout<<endl<<endl;
      cout<<"\t\t\tStudent's Information"<<endl<<endl<<endl;
      cout<<"\t\t\t Remove Student Information"<<endl;
      cout<<"\t\t\t----------------------------"<<endl;

      int studentNum;


      cout<<"Enter Student Number : ";
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
          else {
              dataFound = 1;
          }
      }

      if(dataFound ==0){
          cout<<"no student with the given student ID"<<endl;
      }
      else if(dataFound ==1)
          cout<<"Data has been deleted"<<endl;

      saveInfo.close();
      showInfo.close();

      remove("studentInformation.dat");
      rename("tempInfo.dat","studentInformation.dat");

      dataFound = 0;

}
