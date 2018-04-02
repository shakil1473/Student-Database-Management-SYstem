#include <iostream>
#include <string>
#include<ctime>
#include "StudentDatabase.h"
#include "Studentinformation.h"

using namespace std;
int logIn();
void pause(int dur);
void logInFailed();
int logInFail = 0;
int logInCheck = 0;
int main(){

    int logInSuccessfull =0;
    logInSuccessfull=logIn();
    system("cls");

    StudentInformation studentInformation;
    
    int chooseOption;
    
    if(logInSuccessfull == 1){
        
        do{
            //cout<<"\t\t\t\t\t Plz Press enter"<<endl;

            system("cls");
            cout<<endl<<endl;
            cout<<"\t\t\tStudent's Information"<<endl;
            cout<<endl<<endl;
            cout<<"\t\t\t 1. New Student"<<endl;
            cout<<"\t\t\t 2. Student's List"<<endl;
            cout<<"\t\t\t 3. Student's Information"<<endl;
            cout<<"\t\t\t 4. Edit Information"<<endl;
            cout<<"\t\t\t 5. Delete Information"<<endl;
            cout<<"\t\t\t 6. Log Out"<<endl;
            cout<<"\t\t\t Choose a option :";
            cin>>chooseOption;

            switch (chooseOption) {
            case 1:
                studentInformation.addNewStudent();
                cin.ignore();
                break;
            case 2:
                studentInformation.showStudentsList();
                break;
            case 3:
                studentInformation.showStudentInformation();
                cin.ignore();
                cin.ignore();
                break;
            case 4:
                studentInformation.editStudenetInformation();
                break;
            case 5:
                studentInformation.deleteStudentInformation();
                break;
            default:
                break;
            }
        }while(chooseOption!=6);

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
