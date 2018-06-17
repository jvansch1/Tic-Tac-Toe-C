//
//  tic_tac_toe.c
//  tic_tac_toe
//
//  Created by John VanSchultz on 6/17/18.
//  Copyright © 2018 John VanSchultz. All rights reserved.
//

#include <stdbool.h>
#include "tic_tac_toe.h"

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

void printBoard(char board[][3], int boardSize) {
    for(int row = 0; row < boardSize; row++) {
        for(int column = 0; column < boardSize; column++) {
            if(board[row][column] == 0) {
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

bool checkDiagonals(char board[][3]) {
    bool diagonalWon = false;
    if(((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || (board[0][2] == board[1][1] && board[2][0] == board[0][2])) && board[1][1] != 0) {
        diagonalWon = true;
    }
    return diagonalWon;
}

bool columnIsWon(char rowOneValue, char rowTwoValue, char rowThreeValue) {
    return rowOneValue == rowTwoValue && rowOneValue == rowThreeValue && rowOneValue != 0;
}

bool checkColumns(char board[][3]) {
    bool gameOver = false;
    for(int i = 0; i < 3; i++) {
        if(columnIsWon(board[0][i], board[1][i], board[2][i])) {
            gameOver = true;
        }
    }
    return gameOver;
}

bool rowIsWon(char row[]) {
    return row[0] == row[1] && row[0] ==  row[2] && row[0] != 0;
}

bool checkRows(char board[3][3]) {
    bool gameOver = false;
    for(int i = 0; i < 3; i++) {
        if (rowIsWon(board[i])) {
            gameOver = true;
        }
    }
    return gameOver;
}

bool checkForWin(char board[3][3]) {
    bool gameOver = false;
    
    if (checkRows(board) || checkColumns(board) || checkDiagonals(board)) {
        gameOver = true;
    }
    return gameOver;
}

void playTurn(char board[][3], char symbol) {
    int row = getRowIndex();
    int column = getColumnIndex();
    placeOnBoard(row, column, board, symbol);
}

void placeOnBoard(int row, int column, char board[][3], char symbol) {
    board[row][column] = symbol;
}

void gameLoop(char board[][3]) {
    char currentTurnSymbol = 'X';
    while(!checkForWin(board)) {
        currentTurnSymbol = currentTurnSymbol == 'X' ? 'O' : 'X';
        printBoard(board, 3);
        playTurn(board, currentTurnSymbol);
    }
    printBoard(board, 3);
    printf("%c is the winner!\n", currentTurnSymbol);
}
