#include <iostream>

using namespace std;
char matrix[3][3]={'1','2','3','4','5','6','7','8','9'};
char player = 'x';
void board(); // to show the board
void player_input(); // to take input from players
char who_win(); // to check who is the winner

int main()
{
    while(who_win()=='c'){
        board();
        player_input();
    }
    board();
    if(who_win()=='d')
        cout<<"the game is draw"<<endl;
    else
        cout<<"the winner is player "<<who_win()<<endl;
    return 0;
}
void board(){
    system("cls");
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            cout<<matrix[i][j]<<"   ";
        }
        cout<<endl;
    }
}
void player_input(){
    char pos;
    cout<<"Choose your position, player " << player<< "   ";
    cin>>pos;
    if(pos<1 || pos>9)
        cout<<"invalid position, try again"<<endl;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(pos==matrix[i][j])
                matrix[i][j]=player;
        }
    }
    if(player=='x')
        player='o';
    else
        player='x';
}
char who_win(){
    int Xc=0,Oc=0;
    int counter =0;
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if( matrix[i][j]!='x' && matrix[i][j]!='o')counter++;
            if(matrix[i][j]=='x')Xc++;
            else if(matrix[i][j]=='o')Oc++;
            if(Xc==3 || Oc==3)
                return Xc>Oc?'x':'o';
        }
        Xc=0;
        Oc=0;
    }
    for(int i=0;i<=2;i++){
        for(int j=0;j<=2;j++){
            if(matrix[j][i]=='x')Xc++;
            else if(matrix[j][i]=='o')Oc++;
            if(Xc==3 || Oc==3)
                return Xc>Oc?'x':'o';
        }
        Xc=0;
        Oc=0;
    }
    if(matrix[0][0]=='x' && matrix[1][1]=='x' && matrix[2][2]=='x')return 'x';
    if(matrix[0][2]=='x' && matrix[1][1]=='x' && matrix[2][0]=='x')return 'x';
    if(matrix[0][0]=='o' && matrix[1][1]=='o' && matrix[2][2]=='o')return 'o';
    if(matrix[0][2]=='o' && matrix[1][1]=='o' && matrix[2][0]=='o')return 'o';
    if(counter==0) return 'd'; // draw
    return 'c'; // the game is continuous
}
