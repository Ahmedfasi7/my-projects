#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string>userName;
vector<string>password;

void AskFMApp();
int firstMenu();
void login();
void signup();
int secondMenu();
void printQuestionsToMe();

int main()
{
    AskFMApp();

    return 0;
}
void AskFMApp(){
    int choice = firstMenu();
    if(choice == 1)
         login();
    else if(choice == 2)
        signup();

    choice = secondMenu();

    /*if(choice == 1)

    else if (choice == 2)
    else if (choice == 3)
    else if (choice == 4)
    else if (choice == 5)
    else if (choice == 6)
    else if (choice == 7)
    else if (choice == 8)*/


}
/****************************/
int firstMenu(){
    cout<<"Menu:"<<endl<<endl;
    cout<<"      "<<"1: Login:"<<endl;
    cout<<"      "<<"2: Sign up:"<<endl;
    cout<<"Enter a number in range 1-2: ";
    int choice = -1;
    while(choice == -1){
        cin>>choice;
        if(!(choice>=1 && choice<=2)){
            cout<<"invalid choice, Try again: ";
            choice = -1;
        }
    }
    return choice;
}
/*****************************/
void login(){
    //system("cls");
    string user , pass;
    cout<<"Enter the user name: ";
    cin>>user;
    cout<<"Enter the password: ";
    cin>>pass;
    int len = userName.size();
    bool flag = false;
    for(int i = 0 ; i < len ; i++){
        if(userName[i] == user && password[i] == pass){
            flag = true;
            break;
        }
    }
    if(flag)
        cout<<"hello "<<user<<endl;
    else{
        cout<<"wrong user name or password, Try again"<<endl;
        login();
    }
}
/******************************/
void signup(){
    string newUser = "#$**$#";
    cout<<"Write a user name: ";
    while(newUser == "#$**$#"){
        cin>>newUser;
        int len = userName.size();
        for(int i = 0 ; i < len ; i++){
            if(userName[i] == newUser){
                cout<<"This name has been used by another user. try another one";
                newUser = "#$**$#";
                break;
            }
        }
    }
    userName.push_back(newUser);
    cout<<"Enter your password: ";
    string newPass;
    cin>>newPass;
    password.push_back(newPass);
    cout<<endl<<"Hello "<<newUser<<endl<<endl;

}
int secondMenu(){
    cout<<"Enter your choice: "<<endl<<endl;
    cout<<"1) Print questions to me"<<endl;
    cout<<"2) Print questions from me"<<endl;
    cout<<"3) Answer question"<<endl;
    cout<<"4) Delete question"<<endl;
    cout<<"5) Ask questoin"<<endl;
    cout<<"6) List system users"<<endl;
    cout<<"7) Feed"<<endl;
    cout<<"8) logout"<<endl;
    int choice = -1;
    while(choice == -1){
        cin>>choice;
        if(!(choice>=1 && choice<=8)){
            cout<<"Invalid choice, try again: ";
            choice = -1;
        }
    }
    return choice;
}
