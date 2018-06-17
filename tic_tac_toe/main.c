//
//  main.c
//  tic_tac_toe
//
//  Created by John VanSchultz on 6/13/18.
//  Copyright © 2018 John VanSchultz. All rights reserved.
//

#include <stdio.h>
#include "tic_tac_toe.h"

int main(int argc, const char * argv[]) {
    char board[3][3] = { {0} };
    gameLoop(board);
    return 0;
}





