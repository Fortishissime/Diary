//
// Created by darka on 20/11/2023.
//

#ifndef DIARY_CELL_H
#define DIARY_CELL_H



// --- Structures

typedef struct s_lvl_cell {
    int value;
    int levels;
    struct s_lvl_cell **next;
} t_lvl_cell, *p_lvl_cell;




/* struct s_std_cell {
    p_rendezvous rdv;
    struct s_std_cell *next;
} t_std_cell, *p_std_cell;*/

// --- Functions level cells

p_lvl_cell createLvlCell(int, int);

// --- Functions standard cells

//p_std_cell createStdCell(p_rendezvous);

#endif //DIARY_CELL_H
