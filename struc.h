
#ifndef UNTITLED_STRUC_H
#define UNTITLED_STRUC_H

struct s_cell
{
    int value;
    struct s_cell *next;
};

typedef struct s_cell, *p_cell;

typedef struct s_std_list
{
    p_cell head;
} t_std_list;

p_cell createCell(char);