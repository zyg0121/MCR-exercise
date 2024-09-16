/*
* @Author: zyg0121 zhouyiguo2012@qq.com
* @Date: 2024-09-10 01:15:10
* @LastEditors: zyg0121 zhouyiguo2012@qq.com
* @LastEditTime: 2024-09-10 01:27:08
* @FilePath: \week2-mcr1\code.cpp
* @Description: 
* 
* Copyright (c) 2024 by yiguo, All Rights Reserved. 
*/
#include <iostream>
#include <string.h>
using namespace std;

bool isWin(char game[3][3])
{
    // Check rows
    for (int i = 0; i < 3; i++)
    {
        if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && (game[i][0] == 'X' || game[i][0] == 'O'))
            return true;
    }

    // Check columns
    for (int j = 0; j < 3; j++)
    {
        if (game[0][j] == game[1][j] && game[1][j] == game[2][j] && (game[0][j] == 'X' || game[0][j] == 'O'))
            return true;
    }

    // Check diagonals
    if ((game[0][0] == game[1][1] && game[1][1] == game[2][2]) || (game[0][2] == game[1][1] && game[1][1] == game[2][0]))
    {
        if (game[1][1] == 'X' || game[1][1] == 'O')
            return true;
    }

    return false;
}

void printGame(char game[3][3])
{
    cout << "Game Now:" << endl;
    cout << game[0][0] << " | " << game[0][1] << " | " << game[0][2] << endl;
    cout << "---------" << endl;
    cout << game[1][0] << " | " << game[1][1] << " | " << game[1][2] << endl;
    cout << "---------" << endl;
    cout << game[2][0] << " | " << game[2][1] << " | " << game[2][2] << endl;
}

int main()
{
    int i, j, n;
    char game[3][3]; // Tic-tac-toe
    memset(game, ' ', sizeof(game)); // initialize 3x3 table
    char player1 = 'X';
    char player2 = 'O';
    bool turn = true; // false for player 1's turn, true for player 2's turn. Player 1 first.
    cout<< "Welcome to Tic-Tac-Toe Game!" << endl;
    cout << "X = Player 1" << endl
         << "O = Player 2" << endl;
    for (n = 0; n < 9; n++)
    {
        turn = !turn; // use the not-operator to change true to false or false to true.
        if (turn == false)
            cout << "Player 1: ";
        else
            cout << "Player 2: ";
        cout << "Which cell to mark? i:[0..2], j:[0..2]: ";
        cin >> i >> j;
        if (i < 0 || j < 0 || i > 2 || j > 2 || game[i][j] != ' ')
        {
            cout << "Invalid cell, try again." << endl;
            n--;
            continue;
        }
        if (turn == false)
            game[i][j] = 'X';
        else
            game[i][j] = 'O';
        if (isWin(game))
        {
            if(turn == false)
                cout << "Player 1 wins!" << endl;
            else
                cout << "Player 2 wins!" << endl;
            break; // need to terminate the problem
        }
        // show the game to console
        printGame(game);
    }
    if (n == 9) // all celles with i=0 to 2 have been inputted above but no winner yet
        cout << "Tie!" << endl;
    // show the game to console
    printGame(game);
    return 0;
}
 
