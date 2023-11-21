//
// Created by darka on 20/11/2023.
//

#include "utils.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>


void replaceWithUnder(int value) {
    int abs_value = abs(value);

    while (abs_value >= 10) {
        printf("-");
        abs_value /= 10;
    }

    if(value < 0) { // Ne pas oublier le signe " - " comme caractère
        printf("-");
    }
    return ;

}

int *makeBoardMaker(int n) {
    int *board;
    int cells_amount;

    cells_amount = pow(2,  n) - 1;
    board = (int*) malloc(cells_amount * sizeof(int));

    // Initialisation à 0 de toutes les valeurs couplé à l'ajo

    for(int i=1; i < cells_amount+1; i++) {
        board[i-1] = 0; // Initialisation
        for(int j=1; j < cells_amount+1; j++){
            int val = pow(2, j);
            if(i%val == 0) {
                board[i-1] += 1;
            }
        }
    }
    return board;
}