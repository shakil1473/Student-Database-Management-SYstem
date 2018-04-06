#include "StudentDatabase.h"
#include <fstream>
#include<string>


StudentDatabase::StudentDatabase()
{

}
void StudentDatabase::newStudentInformation(){


    cout<<"\t\t\t enter first name     :";
    getline(cin,studentFirstName);

    cout<<"\t\t\t enter last name      :";
    getline(cin,studentLastName);


    cout<<"\t\t\t enter student id     :";
    cin>>studentNumber;
    cin.ignore();

    cout<<"\t\t\t enter blood group    :";
    getline(cin,studentBlooadGRoup);

    cout<<"\t\t\t enter address        :";
    getline(cin,studentAddress);

    cout<<"\t\t\t enter contact no     :";
    getline(cin,studentContactNo);
}
void StudentDatabase::getStudentList(){


    if(studentFirstName.length()<=5)
        cout<<"\t\t"<<studentFirstName<<" "<<studentLastName<<"        "<<"    \t\t"<<studentNumber<<endl;
    else
        cout<<"\t\t"<<studentFirstName<<" "<<studentLastName<<"    \t\t"<<studentNumber<<endl;



}
void StudentDatabase::getStudentInformation(){
    if(studentFirstName.length()<5){
        cout<<studentFirstName<<"       \t"<<studentLastName<<"    \t"<<studentNumber<<"\t\t"<<studentBlooadGRoup<<"\t\t"<<studentAddress<<"   \t\t"<<studentContactNo<<endl;
    }
    else
        cout<<studentFirstName<<"   \t"<<studentLastName<<"    \t"<<studentNumber<<"\t\t"<<studentBlooadGRoup<<"\t\t"<<studentAddress<<"   \t\t"<<studentContactNo<<endl;
}
void StudentDatabase::modifyStudentInformation(int studNumber){

    cout<<"\t\t\t Student Number       :"<<studNumber<<endl;

    cout<<"\t\t\t enter first name     :";
    getline(cin,studentFirstName);

    cout<<"\t\t\t enter last name      :";
    getline(cin,studentLastName);


    cout<<"\t\t\t enter blood group    :";
    getline(cin,studentBlooadGRoup);

    cout<<"\t\t\t enter address        :";
    getline(cin,studentAddress);

    cout<<"\t\t\t enter contact no     :";
    getline(cin,studentContactNo);
}

int StudentDatabase::getStudentNumber(){
    return studentNumber;
}
