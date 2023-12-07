//
// Created by darka on 20/11/2023.
//


#ifndef DIARY_LIST_H
#define DIARY_LIST_H

// -- Includes

#include "cell.h"

// -- Structures

typedef struct s_lvl_list {
    int max_level;
    p_lvl_cell *heads;
} t_lvl_list, *p_lvl_list;

// -- Functions levels list

t_lvl_list createEmptyLvlList(int);
t_lvl_list createOneOnTwoList(int);


void addHeadInLvlList(p_lvl_list, int, int);
void addInOrder(p_lvl_list, int);

void displayLevelOfList(t_lvl_list, int);
void displayAllLevels(t_lvl_list);
void displayAllLevelsAlign(t_lvl_list);

int classicSearchInList(t_lvl_list, int);
int optimalSearchInList(t_lvl_list, int);

// -- Functions standard list

#endif //DIARY_LIST_H
