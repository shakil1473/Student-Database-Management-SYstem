#include <iostream>
#include <string>
#include<ctime>
#include<conio.h>
#include "StudentDatabase.h"
#include "Studentinformation.h"

using namespace std;
int logIn();
void pause(int dur);
void logInFailed();
int logInFail = 0;
int logInCheck = 0;
int main(){

    int logInSuccessfull =1;//make it 0
    //string studentNumber;
    //logInSuccessfull=logIn();
    system("cls");

    StudentInformation studentInformation;
    
    char chooseOption;
    
    if(logInSuccessfull == 1){
        
        do{

            system("cls");
            cout<<endl<<endl;
            cout<<"\t\t\tStudent's Information"<<endl;
            cout<<endl<<endl;
            cout<<"\t\t\t 1. New Student"<<endl;
            cout<<"\t\t\t 2. All Students"<<endl;
            cout<<"\t\t\t 3. Student Information"<<endl;
            cout<<"\t\t\t 4. Edit Information"<<endl;
            cout<<"\t\t\t 5. Delete Information"<<endl;
            cout<<"\t\t\t 6. Log Out"<<endl;
            cout<<"\t\t\t Choose a option :";
//            chooseOption = getche();
            cin>>chooseOption;

            switch (chooseOption) {
            case '1':
                cin.ignore();
                studentInformation.addNewStudent();
                cin.ignore();
                break;

            case '2':
                cin.ignore();
                studentInformation.showAllStudents();
                cin.ignore();
                break;

            case '3':
                cin.ignore();
                studentInformation.showStudentInformation();
                cin.ignore();
                break;

            case '4':
                cin.ignore();
                cout<<chooseOption;
                studentInformation.editStudenetInformation();
                cin.ignore();

                break;

            case '5':
                cin.ignore();
                studentInformation.removeStudentInformation();
                cin.ignore();
                break;

            default:
                break;
            }
        }while(chooseOption!='6');

    }
    else if(logInSuccessfull == 2){
        cout<<"come later and try again.thanks."<<endl<<endl;
        cout<<"press any key to exit"<<endl;
    }
    return 0;
}
int logIn(){

    string userName;
    string password;
    cout<<endl<<endl;
    cout<<"\t\t\tStudent's Information"<<endl<<endl;
    cout<<"\t\t\t Username: ";
    getline(cin,userName);
    cout<<"\t\t\t Password: ";
    getline(cin,password);

   if(userName == "shakil" && password=="1473")
       logInCheck = 1;
   else
       logInFailed();
    return logInCheck;
}
void logInFailed(){
 logInFail++;
 if(logInFail<3){
     system("cls");
     cout<<"username or password is wrong.Try again please";
     pause(2);
     system("cls");
     logIn();
 }
 else{
     logInCheck = 2;
 }
}
void pause(int dur)
{
int temp = time(NULL) + dur;

while(temp > time(NULL));
}
