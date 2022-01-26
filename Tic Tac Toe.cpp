#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

// Tic Tac Toe Game

void Draw(vector<char>&v)
{
    cout<<" "<<v[0]<<" | "<<v[1]<<" | "<<v[2]<<" "<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<v[3]<<" | "<<v[4]<<" | "<<v[5]<<" "<<endl;
    cout<<"---|---|---"<<endl;
    cout<<" "<<v[6]<<" | "<<v[7]<<" | "<<v[8]<<" "<<endl;
}

void XorO(vector<char>&v,int choice, int player)
{
    char c;
    if(player%2 == 0)
        c = 'X';
    else
        c = 'O';

    if(v[choice-1] - '0' == choice)
        v[choice-1] = c;
    else
    {
        if(choice > v.size() || choice <= 0)
        cout<<"Invalid Choice ";
        else
        cout<<"Already chosen ";

        int n;
        cin>>n;
        XorO(v, n, player);
    }
}

string checkWin(vector<char>&v, int player)
{
    string winner;
    if(player%2 == 0)
        winner = "Player 1 wins";
    else
        winner = "Player 2 wins";

    if(v[0] == v[1] && v[1] == v[2])
    return winner;

    if(v[3] == v[4] && v[4] == v[5])
    return winner;

    if(v[6] == v[7] && v[7] == v[8])
    return winner;

    if(v[0] == v[4] && v[4] == v[8])
    return winner;

    if(v[2] == v[4] && v[4] == v[6])
    return winner;

    if(v[0] == v[3] && v[3] == v[6])
    return winner;

    if(v[1] == v[4] && v[4] == v[7])
    return winner;

    if(v[2] == v[5] && v[5] == v[8])
    return winner;

    if(v[0] != '1' && v[1] != '2' && v[2] != '3' && v[3] != '4' && v[4] != '5' && v[5] != '6' && v[6] != '7' && v[7] != '8' && v[8] != '9' )
    return "Draw";

    return "";
}

int main()
{
    vector<char>v{'1','2','3','4','5','6','7','8','9'};

    string winner;
    int player = 0;
    int choice;

    do{
    system("cls");

    cout<<setw(60)<<"Tic Tac Toe\n";

    Draw(v);

    if(player%2 == 0)
    cout<<"\nPlayer's 1 turn\n";
    else
    cout<<"\nPlayer's 2 turn\n";

    cout<<"Choose(1 - 9): ";
    cin>>choice;

    XorO(v, choice, player);

    winner = checkWin(v, player);

    ++player;

    cout<<endl;
    }while(winner.empty());

    cout<<winner;
    return 0;
}
