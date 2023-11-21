//
// Created by darka on 20/11/2023.
//

#ifndef DIARY_CELL_H
#define DIARY_CELL_H

typedef struct s_cell {
    int value;
    int levels;
    struct s_cell **next;
} t_cell, *p_cell;

p_cell createCell(int, int);

#endif //DIARY_CELL_H
