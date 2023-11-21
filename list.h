//
// Created by darka on 20/11/2023.
//


#ifndef DIARY_LIST_H
#define DIARY_LIST_H

// -- Includes

#include "cell.h"

// -- Structures

typedef struct s_list {
    int max_level;
    p_cell *heads;
} t_list, *p_list;

// -- Functions

t_list createEmptyList(int);
t_list createOneOnTwoList(int);


void addHeadInList(p_list, int, int);
void addInOrder(p_list, int);

void displayLevelOfList(t_list, int);
void displayAllLevels(t_list);
void displayAllLevelsAlign(t_list);

int classicSearchInList(t_list, int);
int optimalSearchInList(t_list, int);



#endif //DIARY_LIST_H
