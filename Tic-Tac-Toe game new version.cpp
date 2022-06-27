#include <iostream>
using namespace std;
char matrix[10][10];
int player;
void fillMatrix(int n){
    for(int i = 0 ; i < n ; i++)
        for(int j = 0 ; j < n ; j++)
            matrix[i][j] = '.';
}

void updateAndPrintTheMatrix(int n , char z , int row , int col){
    system("cls");
    matrix[row][col] = z;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}
int main()
{
    int n;
    cout<<"               Welcome to Tic-Tac-Toe game"<<endl;
    cout<<"please enter the length or the width of the board(from 3 to 10): ";
    cin>>n;
    fillMatrix(n);

    char player ='m';
    while(player != 'x' && player != 'o'){
        cout<<"Please enter who will start x or o: ";
        cin>>player;
        if(player != 'x' && player != 'o')
            cout << "Wrong!"<<endl;
    }

    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<"."<<" ";
        }
        cout<<endl;
    }

    char target = 'c';
    for(int i = 0 ; i < n*n ; i++)
    {
        int row , col;

        cout<<"Choose your position player: "<<player<<endl;
        cin>>row>>col;
        row-- , col--;
        if(row>=0 && row<n && col>=0 && col<n && matrix[row][col] == '.')
            updateAndPrintTheMatrix(n , player , row , col);
        else{
            cout<<"Invalid position , try again"<<endl;
            i-- ;
            continue;
        }
        if(i < n*2-1){
            if(player == 'x')
                player = 'o';
            else
                player = 'x';
            continue;
        }

        for(int i = 0 ; i < n ; i++){//checking the rows if there is a winner
            int x_cnt = 0 , o_cnt = 0 ;
            for(int j = 0 ; j < n ; j++){
                x_cnt += (matrix[i][j] == 'x');
                o_cnt += (matrix[i][j] == 'o');
            }
            if(x_cnt == n)
            {
                target = 'x';
                break;
            }
            else if(o_cnt == n)
            {
                target = 'o';
                break;
            }
        }
        if(target == 'x' || target == 'o')
            break;

        for(int i = 0 ; i < n ; i++){//checking the columns if there is a winner
            int x_cnt = 0 , o_cnt = 0;
            for(int j = 0 ; j < n ; j++){
                x_cnt += (matrix[i][j] == 'x');
                o_cnt += (matrix[i][j] == 'o');
            }
            if(x_cnt == n)
            {
                target = 'x';
                break;
            }
            else if(o_cnt == n)
            {
                target = 'o';
                break;
            }

        }
        if(target == 'x' || target == 'o')
            break;

        int x_cnt = 0 , o_cnt = 0;
        for(int i = 0 ; i < n ; i++){ //checking the left diagonal
            x_cnt += (matrix[i][i] == 'x');
            o_cnt += (matrix[i][i] == 'o');
        }
        if(x_cnt == n)
        {
            target = 'x';
            break;
        }
        else if(o_cnt == n)
        {
            target = 'o';
            break;
        }

        x_cnt = 0 , o_cnt = 0;
        for(int i = 0 , j = n-1 ; i < n ; i++ , j--){ //checking the right diagonal
            x_cnt += (matrix[i][j] == 'x');
            o_cnt += (matrix[i][j] == 'o');
        }
        if(x_cnt == n)
        {
            target = 'x';
            break;
        }
        else if(o_cnt == n)
        {
            target = 'o';
            break;
        }

        if(player == 'x')
            player = 'o';
        else
            player = 'x';
    }

    if(target == 'x')
        cout<<"Player x is the winner , congratulations"<<endl;
    else if(target == 'o')
        cout<<"Player o is the winner , congratulations"<<endl;
    else
        cout<<"The game is draw "<<endl;

    return 0;
}
