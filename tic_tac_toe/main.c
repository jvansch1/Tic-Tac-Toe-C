//
//  main.c
//  tic_tac_toe
//
//  Created by John VanSchultz on 6/13/18.
//  Copyright © 2018 John VanSchultz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include "tic_tac_toe.h"

int getRowIndex();
int getColumnIndex();
void playTurn(char board[][3], char cymbol);
void placeOnBoard(int row, int column, char board[][3], char symbol);
void gameLoop(char board[][3]);
bool checkForWin(char board[3][3]);

int main(int argc, const char * argv[]) {
    char board[3][3] = { {0} };
    gameLoop(board);
    return 0;
}





