#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct book{
    int id = 0;
    string name = " ";
    int quantity = 0;
    int total_borrowed = 0;
};

struct user{
    string name = " ";
    int id = 0;
};

vector<book>shelf;
vector<user>users;
vector<vector<string>>borrowed_books(10);

bool is_prefix(string str , string prefix , int start_pos =0 ){
    if(start_pos == (int)prefix.size())
        return true;

    if(str[start_pos]!=prefix[start_pos])
        return false;

    return is_prefix(str , prefix , start_pos+1);
}

void add_book()
{
    book b;
    bool okay = true;
    cout<<"Enter book info: id & name & total quantity\n";
    cin>>b.id>>b.name>>b.quantity;

    for(int i = 0 ; i < (int)shelf.size() ; i++){
        if(shelf[i].name == b.name || shelf[i].id == b.id){
            cout<<"This book name or id is already existing, try again\n";
            okay = false;
            break;
        }
    }
    if(okay)
        shelf.push_back(b);
    else
        add_book();
}

void add_user()
{

    bool okay = true;
    user u;
    cout<<"Enter user name & id\n";
    cin>>u.name>>u.id;

    for(int i = 0 ; i < (int)users.size() ; i++){
        if(users[i].name == u.name || users[i].id == u.id){
            cout<<"The user name or id is used before, try again\n";
            okay = false;
        }
    }
    if(okay)
        users.push_back(u);
    else
        add_user();

}

void search_book_by_prefix()
{
    string prefix;
    cout<<"Enter the prefix: ";
    cin>>prefix;
    bool flag = true;

    for(int i = 0 ; i < (int)shelf.size() ; i++)
    {
        if(is_prefix(shelf[i].name , prefix)){
            cout<<shelf[i].name<<"    ";
            flag = false;
        }
    }
    cout<<endl;
    if(flag)
        cout<<"There are no books with the prefix: "<<prefix<<endl;

}

void user_borrow_book(){
    string username , bookname;
    int user_idx = -1 , book_idx = -1;
    cout<<"Enter user name and book name\n";
    cin>>username>>bookname;
    for(int i = 0 ; i < (int)shelf.size() ; i++){
        if(shelf[i].name == bookname && shelf[i].quantity>0){
            book_idx = i;
            break;
        }
    }

    for(int i = 0 ; i < (int)users.size() ; i++){
       if(users[i].name == username){
            user_idx = i;
            break;
       }
    }

    if(book_idx != -1 && user_idx != -1){
        shelf[book_idx].quantity--;
        shelf[book_idx].total_borrowed++;
        borrowed_books[user_idx].push_back(bookname);
        cout<<"Well done "<<users[user_idx].name<<endl;
    }
    else{
        cout<<"Invalid user name or book name, try again\n";
    }
}

void user_return_book(){
    string username , bookname;
    int user_idx = -1 , book_idx = -1;
    cout<<"Enter user name and book name\n";
    cin>>username>>bookname;
    for(int i = 0 ; i < (int)shelf.size() ; i++){
        if(shelf[i].name == bookname){
            book_idx = i;
            break;
        }
    }

    for(int i = 0 ; i < (int)users.size() ; i++){
       if(users[i].name == username){
            user_idx = i;
            break;
       }
    }

    if(book_idx != -1 && user_idx != -1){
        shelf[book_idx].quantity++;
        shelf[book_idx].total_borrowed--;
        for(auto it = borrowed_books[user_idx].begin() ; it != borrowed_books[user_idx].end() ; it++){
            if(*it == bookname){
                borrowed_books[user_idx].erase(it);
                break;
            }
        }

        cout<<"Well done "<<users[user_idx].name<<endl;
    }
    else{
        cout<<"Invalid user name or book name, try again\n";
    }
}

void print_users(){
    for(int i = 0 ; i < (int)users.size() ; i++){
        if((int)borrowed_books[i].size() == 0){
            cout<<"User "<<users[i].name<<" doesn't borrow any books\n\n";
            continue;
        }
        cout<<"User "<<users[i].name<<" borrowed book(s), namely"<<endl;
        for(int j = 0 ; j < (int)borrowed_books[i].size() ; j++){
            cout<<borrowed_books[i][j];
            if(j != (int)borrowed_books[i].size()-1)
                cout<<",";
        }
        cout<<endl<<endl;
    }
}
int menu()
{
    bool static first_time = true;
    if(first_time){
        cout<<"                   Welcome to our library \n\n";
        cout<<"Library menu:\n"<<"1) Add book\n"<<"2) Search book by prefix\n"
            <<"3) Print who borrowed book by name\n"<<"4) Print library by id\n"
            <<"5) Print library by name\n"<<"6) Add user\n"<<"7) User borrow book\n"
            <<"8) user return book\n"<<"9) Print users\n"<<"10) Exit\n";
    }
    cout<<"Enter your choice[1 : 10]: ";
    int choice;
    cin>>choice;
    while(choice < 1 || choice > 10)
    {
        cout<<"Invalid choice, try again\n"
            <<"Enter your choice[1 : 10]: ";
            cin>>choice;
    }
    first_time = false;
    return choice;
}

void library_system()
{
    while(true){
        int choice = menu();

        if(choice == 1)
            add_book();
        else if (choice == 2)
            search_book_by_prefix();
//        else if (choice == 3)
//            print_who_borrowed_book_by_name();
//        else if (choice == 4)
//            print_library_by_id();
//        else if (choice == 5)
//            print_library_by_name();
        else if (choice == 6)
            add_user();
        else if (choice ==7)
            user_borrow_book();
        else if (choice ==8)
            user_return_book();
        else if (choice ==9)
            print_users();
        else{
            cout<<"Thank you"<<endl;
            return;
        }
    }

}
int main()
{
    library_system();
    return 0;
}
