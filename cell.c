//
// Created by darka on 20/11/2023.
//

#include "cell.h"
#include <stdlib.h>

p_cell createCell(int value, int levels) {
    p_cell cell = (p_cell) malloc(sizeof (t_cell));

    cell->value = value;
    cell->levels = levels;

    cell->next = (p_cell*)malloc(levels * sizeof(p_cell));

    // Initialiser les pointeurs next à NULL
    for (int i = 0; i < levels; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}