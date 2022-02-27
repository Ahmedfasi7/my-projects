/* This program is small hospital system(mini project).
 * The hospital has 20 specializations.
 * If the status of patient is regular , he/she will be
 * at the end of the queue. If it is urgent, she/he will be
 * at the front of the queue.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 20 ;

vector<vector<string>>names(MAX+1);
vector<vector<int>>status(MAX+1);

int menu(){
    cout << "\nEnter your choice.\n";
    cout << "1) Add new patient.\n";
    cout << "2) Print all patients.\n";
    cout << "3) Get next patient.\n";
    cout << "4) Exit.\n";

    int choice = -1 ;
    while(choice == -1){
        cin >> choice;
        if(!(choice >= 1 && choice <= 4)){
            cout << "Invalid choice, Try again\n";
            choice = -1;
        }
    }

    return choice;

}

void addPatient(){
    int spec , st ;
    string name;
    cout << "Enter specialization: ";
    cin >> spec;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter status: ";
    cin >> st;

    if(names[spec].size() == 5)
        cout << "Sorry, There is no place in this specialization\n";
    else{
        if(st == 1 && names[spec].size() != 0 ){
            int len = names[spec].size() ,
                cnt=0;  // to count how many urgent patients came before the next urgent
            for(int k = 0 ; k < len ; k++){
                cnt += (status[spec][k] == 1);
            }

            names[spec].push_back(names[spec][len-1]);
            status[spec].push_back(status[spec][len-1]);

            for(int i = len-1 ; i > cnt ; i--){ // shift right
                names[spec][i] = names[spec][i-1];
                status[spec][i] = status[spec][i-1];
            }

            names[spec][cnt] = name;
            status[spec][cnt] = 1;

        }

        else if(st == 1 && names[spec].size() == 0){
            names[spec].push_back(name);
            status[spec].push_back(1);
        }

        else{
            names[spec].push_back(name);
            status[spec].push_back(0);
        }
    }
}

void printPatients(){
    bool noPatient = true;
    for(int i = 1 ; i <= 20 ; i++){
        int len = names[i].size();

        if(len > 0)
            noPatient = false;

        for(int j = 0 ; j < len ; j++){
            if(j == 0)
                cout << "There is/are "<<len<<" patient(s) in specialization "<< i<<endl;

            cout << names[i][j] << " ";
            cout << ((status[i][j]) ? "urgent" : "regular" )<<endl;
            if(j == len-1)
                cout << endl;
        }
    }
    if(noPatient)
        cout << "There are no patients in the hospital\n";
}

void getNextPatient(){
    cout << "Enter specialization\n";
    int spec;
    cin >> spec;

    if(names[spec].size() == 0)
        cout << "No patients in this specialization, have a rest Dr\n";

    else{
        cout << names[spec][0] << ", go with the Dr.\n";

        int len = names[spec].size();
        for(int i = 0 ; i < (len-1) ; i++){  // shift left
            names[spec][i] = names[spec][i+1];
            status[spec][i] = status[spec][i+1];
        }

        names[spec].pop_back();
        status[spec].pop_back();
    }
}

void exit(){
    cout << "Thank you for using\n";
}


void hospitalSystem(){
    while(true){
        int choice = menu();

        if(choice == 1)
            addPatient();

        else if(choice == 2)
            printPatients();

        else if(choice == 3)
            getNextPatient();

        else if (choice == 4){
            exit();
            break ;
        }

    }
}
int main()
{
    hospitalSystem();

    return 0;

}
