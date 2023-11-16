//
// Created by VeKTyS on 16/11/2023.
//

#include "menu.h"
#include "struc.h"
#include <stdio.h>

#define MAX_SIZE 50

void menu(){
    int n;
    printf("1 - Ajouter un contact");
    printf("2 - Prendre un rendez-vous");

}



t_std_list *scanString(){
    char input;
    scanf("%s", &input);

    t_std_list tab;
    p_cell cell = createCell(input);
    p_cell temp = tab->head;

    cell->next = temp;
    tab->head = cell;

    return tab;
}