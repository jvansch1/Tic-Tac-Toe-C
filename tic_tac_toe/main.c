//
//  main.c
//  tic_tac_toe
//
//  Created by John VanSchultz on 6/13/18.
//  Copyright © 2018 John VanSchultz. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>

void printBoard(char board[][3], int boardSize);
int getRowIndex();
int getColumnIndex();
void playTurn();
void placeOnBoard(int row, int column, char board[][3], char symbol);
void gameLoop(char board[][3]);
_Bool checkForWin(char board[3][3]);

int main(int argc, const char * argv[]) {
    char board[3][3] = { { NULL, NULL, NULL }, { NULL, NULL, NULL }, { NULL, NULL, NULL } };
    gameLoop(board);
    return 0;
}

void gameLoop(char board[][3]) {
    while(!checkForWin(board)) {
        printBoard(board, 3);
        playTurn(board);
    }
}

void playTurn(char board[][3]) {
    int row = getRowIndex();
    int column = getColumnIndex();
    placeOnBoard(row, column, board, 'X');
}

int getRowIndex() {
    int row = 0;
    printf("Please enter the row index: \n");
    printf("> ");
    scanf("%d", &row);
    return row;
}

int getColumnIndex() {
    int column = 0;
    printf("Please enter the column index: \n");
    printf("> ");
    scanf("%d", &column);
    return column;
}

void placeOnBoard(int row, int column, char board[][3], char symbol) {
    board[row][column] = symbol;
}

void printBoard(char board[][3], int boardSize) {
    for(int row = 0; row < boardSize; row++) {
        for(int column = 0; column < boardSize; column++) {
            if(board[row][column] == NULL) {
                printf("| |");
            } else {
                printf("|%c|", board[row][column]);
            }
            
            if (column == boardSize - 1) {
                printf("\n");
            }
        }
    }
}

bool rowIsWon(char row[]) {
    if ((row[0] == 'X' && row[1] == 'X' && row[2] == 'X') || (row[0] == 'O' && row[1] == 'O' && row[2] == 'O')) {
        return true;
    } else {
        return false;
    }
}

bool checkRows(board[3][3]) {
    _Bool gameOver = false;
    for(int i = 0; i < 3; i++) {
        if (rowIsWon(board)) {
            gameOver = true;
        }
        board++;
    }
    return gameOver;
}

bool checkForWin(char board[3][3]) {
    _Bool gameOver = false;
    char boardPointer = *board;
    
    if (checkRows(board)) {
        gameOver = true;
    }
    return gameOver;
}


