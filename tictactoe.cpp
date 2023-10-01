#include<iostream>
using namespace std;

string player1, player2;
char grid[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
char token = 'X';

int whoseturn()
{
    if(token == 'X')
        return 1;
    else
        return 2;
}

void printboard()
{
    cout << "        |     |     " << endl;
    cout << "     " << grid[0][0] << "  |  " << grid[0][1] << "  |  " << grid[0][2] << endl;
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    cout << "     " << grid[1][0] << "  |  " << grid[1][1] << "  |  " << grid[1][2] << endl;
    cout << "   _____|_____|_____" << endl;
    cout << "        |     |     " << endl;
    cout << "     " << grid[2][0] << "  |  " << grid[2][1] << "  |  " << grid[2][2] << endl;
    cout << "        |     |     " << endl;
}

int winningcombo()
{
    if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2] ||
       grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2] ||
       grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2] ||
       grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0] ||
       grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1] ||
       grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2] ||
       grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2] ||
       grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0])
        return 1;
    else 
        return 0;
}

void function()
{
    int digit;
    if(whoseturn() == 1)
    {
        cout << "   " << player1 << " to enter a number : ";
        cin >> digit;
        if(digit == 1)
        grid[0][0] = 'X';
        else if(digit == 2)
            grid[0][1] = 'X';
        else if(digit == 3)
            grid[0][2] = 'X';
        else if(digit == 4)
            grid[1][0] = 'X';
        else if(digit == 5)
            grid[1][1] = 'X';
        else if(digit == 6)
            grid[1][2] = 'X';
        else if(digit == 7)
            grid[2][0] = 'X';
        else if(digit == 8)
            grid[2][2] = 'X';
        else if(digit == 9)
            grid[2][2] = 'X';
        else
            cout << "   Invalid number!" << endl;
    }
    if(whoseturn() == 2)
    {
        cout << "   " << player2 << " to enter a number : ";
        cin >> digit;  
        if(digit == 1)
            grid[0][0] = 'O';
        else if(digit == 2)
            grid[0][1] = 'O';
        else if(digit == 3)
            grid[0][2] = 'O';
        else if(digit == 4)
            grid[1][0] = 'O';
        else if(digit == 5)
            grid[1][1] = 'O';
        else if(digit == 6)
            grid[1][2] = 'O';
        else if(digit == 7)
            grid[2][0] = 'O';
        else if(digit == 8)
            grid[2][2] = 'O';
        else if(digit == 9)
            grid[2][2] = 'O'; 
        else 
            cout << "   Invalid number!" << endl;
    }  
    printboard();
    if(winningcombo() == 1)
    {
        if(whoseturn() == 1)
            cout << endl << "   " << player1 <<  " wins!!" << endl << endl;
        else if(whoseturn() == 2)
            cout << endl << "   " << player2 <<  " wins!!" << endl << endl;
    }
    else
    {
        if(whoseturn() == 2)
        token = 'X';
        else if(whoseturn() == 1)
        token = 'O';
        function();
    } 
}

int main()
{
    cout << "Player 1 : ";
    getline(cin, player1);
    cout << "Player 2 : ";
    getline(cin, player2);
    cout << endl << "   " << player1 << " will play first!" << endl << endl;
    printboard();
    function();
    return 0;
}