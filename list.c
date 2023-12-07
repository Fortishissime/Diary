//
// Created by darka on 20/11/2023.
//
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "list.h"
#include "utils.h"
#include "cell.h"

// -- Création de liste

t_lvl_list createEmptyLvlList(int max_level) { // Liste partie 1
    t_lvl_list list;

    list.max_level = max_level;
    list.heads = (p_lvl_cell*) malloc(max_level * sizeof(p_lvl_cell));


    for(int i=0; i < max_level; i++) {
        list.heads[i] = NULL;
    }

    return list;
}

t_lvl_list createOneOnTwoList(int max_level) { // Liste de la partie 2
    t_lvl_list list = createEmptyLvlList(max_level);

    int *levels = makeBoardMaker(max_level);
    int cells_amount = (int) pow(2, max_level) - 1;

    for(int i=cells_amount-1; i >= 0; i--) {
        addHeadInLvlList(&list, i+1, levels[i]+1);
    }

    return list;
}


// -- Gestion modification des listes à niveaux

void addHeadInLvlList(p_lvl_list list, int value, int levels) {
    p_lvl_cell cell = createLvlCell(value, levels);

    for (int i = 0; i < levels; i++) {
        if (list->heads[i] != NULL) {
            cell->next[i] = list->heads[i];
        }
        list->heads[i] = cell;
    }
}

void addInOrder(p_lvl_list list, int value) {
    int level = list->max_level - 1;

    p_lvl_cell newCell = createLvlCell(value, level + 1);

    for (int i = level; i >= 0; i--) {
        while (list->heads[i] != NULL && list->heads[i]->value < value) {
            list->heads[i] = list->heads[i]->next[i];
        }

        if (i > 0) {
            newCell->next[i - 1] = list->heads[i];
        }
    }

    for (int i = 0; i <= level; i++) {
        newCell->next[i] = list->heads[i];
        list->heads[i] = newCell;
    }
}

// -- Gestion de l'affichage

void displayLevelOfList(t_lvl_list list, int level) {
    if(level < 0 || level > list.max_level) {
        printf("Error : Bad entry for `level` argument\n");
        return ;
    }

    p_lvl_cell temp = list.heads[level];
    printf("[list head_%d @-]-->", level);

    while(temp != NULL) {
        printf("[ %d|@-]-->", temp->value);
        temp = temp->next[level];
    }
    printf("NULL\n");

}

// Moins couteuse en temps mais affichagé non aligné
void displayAllLevels(t_lvl_list list) {
    for(int i=0; i < list.max_level; i++) {
        displayLevelOfList(list, i);
    }
}

// Pour cette fonction, on compare chaque niveaux avec le niveau 0 (contenant toute les cellules)
// - Achour

void displayAllLevelsAlign(t_lvl_list list) {
    displayLevelOfList(list, 0);
    p_lvl_cell temp_0;

    for(int i=1; i < list.max_level; i++) {
        p_lvl_cell temp = list.heads[i];
        temp_0 = list.heads[0];

        printf("[list head_%d @-]", i);

        while (temp_0 != NULL) {
            if(temp_0 == temp) {
                printf("-->[ %d|@-]", temp->value);
                temp = temp->next[i];
            }
            else {

                // Constante : 9 caractères minimum par cellule évitée
                printf("----------");

                // Calcul des underscores manquants
                replaceWithUnder(temp_0->value);

            }
            temp_0 = temp_0->next[0];
        }
        printf("-->NULL\n");
    }
}

// Gestion des recherches :

int classicSearchInList(t_lvl_list list, int val) {
    p_lvl_cell temp = list.heads[0];

    while (temp != NULL) {
        if(temp->value == val) {
            return 1;
        }
        temp = temp->next[0];
    }

    return 0;
}

int optimalSearchInList(t_lvl_list list, int val) {
    int current_level = list.max_level-1;
    p_lvl_cell current_cell = list.heads[current_level];

    // -- Recherche de la cellule de départ du niveau 0 (et éventuellement la valeur)
    while(current_level > 0) {
        if (current_cell->value == val) {
            return 1;
        } else if (current_cell->value > val) {
            current_level -= 1;
            current_cell = list.heads[current_level];
        } else if (current_cell->value < val) {
            current_level -= 1;
        }
    }

    // -- Recherche de la valeur (si valeur de la cellule plus élevée que celle recherchée, on arrête)
    while (current_cell != NULL) {
        if (current_cell->value == val) {
            return 1;
        }
        else if(current_cell->value > val) {
            return 0;
        }
        current_cell = current_cell->next[current_level];
    }
    return 0;
}