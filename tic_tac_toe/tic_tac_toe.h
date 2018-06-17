//
//  tic_tac_toe.h
//  tic_tac_toe
//
//  Created by John VanSchultz on 6/17/18.
//  Copyright © 2018 John VanSchultz. All rights reserved.
//

#ifndef tic_tac_toe_h
#define tic_tac_toe_h

#include <stdio.h>

void printBoard(char board[][3], int boardSize);
int getRowIndex();
int getColumnIndex();
bool checkDiagonals(char board[][3]);
bool columnIsWon(char rowOneValue, char rowTwoValue, char rowThreeValue);
bool checkColumns(char board[][3]);
bool rowIsWon(char row[]);
bool checkRows(char board[3][3]);
bool checkForWin(char board[3][3]);
void playTurn(char board[][3], char symbol);
void placeOnBoard(int row, int column, char board[][3], char symbol);
void gameLoop(char board[][3]);

#endif /* tic_tac_toe_h */
