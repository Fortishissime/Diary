//
// Created by darka on 20/11/2023.
//
#include <stdlib.h>
#include "cell.h"


// --- Functions level cell

p_lvl_cell createLvlCell(int value, int levels) {
    p_lvl_cell cell = (p_lvl_cell) malloc(sizeof (t_lvl_cell));

    cell->value = value;
    cell->levels = levels;

    cell->next = (p_lvl_cell*)malloc(levels * sizeof(p_lvl_cell));

    // Initialiser les pointeurs next à NULL
    for (int i = 0; i < levels; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}

// --- Functions standard cell

/*p_std_cell createStdCell(p_rendezvous rdv) {
    p_std_cell cell = (p_std_cell) malloc(sizeof(t_std_cell));

    cell->rdv = rdv;
    cell->next = NULL;

    return cell;
}*/