//
// Created by darka on 20/11/2023.
//

#include "utils.h"
#include "math.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 128 // Taille maximale d'une chaine de caractère entrée par l'utilisateur. Définie arbitrairement

void replaceWithUnder(int value) {
    int abs_value = abs(value);

    while (abs_value >= 10) {
        printf("-");
        abs_value /= 10;
    }

    if(value < 0) { // Ne pas oublier le signe " - " comme caractère
        printf("-");
    }
}

int *makeBoardMaker(int n) {
    int *board;
    int cells_amount;

    cells_amount = (int) pow(2,  n) - 1;
    board = (int*) malloc(cells_amount * sizeof(int));

    // Initialisation à 0 de toutes les valeurs couplé à l'ajout des valeurs selon l'algorithme de la partie 2

    for(int i=1; i < cells_amount+1; i++) {
        board[i-1] = 0; // Initialisation
        for(int j=1; j < cells_amount+1; j++){
            int val = (int) pow(2, j);
            if(i%val == 0) {
                board[i-1] += 1;
            }
        }
    }
    return board;
}

char *scanString() {
    int size = 0;

    char string[MAX_LENGTH];
    char *dynamic_string;
    scanf("%s", string);

    while(string[size] != '\0') { // Détermination de la longueur utilisé (on inclus le caractère '\0')
        size += 1;
    }
    size += 1;

    dynamic_string = (char *) malloc(size * sizeof(char)); // Allocation de la mémoire

    for(int i=0; i < size; i++) { // Ecriture des emplacements mémoires avec les caractères correspondant
        dynamic_string[i] = string[i];
    }

    return dynamic_string;
}