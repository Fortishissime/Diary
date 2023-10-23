#include <stdio.h>
#include <stdlib.h>
#include "struc.h"
#include <time.h>
#include "timer.h"

// Fonction pour créer une cellule
t_d_cell *createCell(int value) {
    t_d_cell *newCell = (t_d_cell *)malloc(sizeof(t_d_cell));
    newCell->value = value;
    newCell->next_0 = NULL;
    newCell->next_1 = NULL;
    return newCell;
}

// Fonction pour insérer une cellule dans la liste
void insertCell(t_d_list *list, t_d_cell *newCell, int level) {
    if (level == 0) {
        newCell->next_0 = list->head_0;
        list->head_0 = newCell;
    } else if (level == 1) {
        newCell->next_1 = list->head_1;
        list->head_1 = newCell;
    }
}


// Fonction pour afficher les cellules d'un niveau donné
void printLevel(t_d_list list, int level) {
    t_d_cell *current = (level == 0) ? list.head_0 : list.head_1;
    while (current != NULL) {
        printf("%d ", current->value);
        current = (level == 0) ? current->next_0 : current->next_1;
    }
    printf("\n");
}


// Créez une liste à niveaux en utilisant le nombre de niveaux défini
t_d_list createMultiLevelList(int numLevels, int maxValue) {
    t_d_list multiLevelList;
    multiLevelList.head_0 = NULL;
    multiLevelList.head_1 = NULL;

    int levels[numLevels];
    for (int i = 0; i < numLevels; i++) {
        levels[i] = 0;
    }

    // Créez les cellules pour chaque niveau
    for (int i = 1; i <= maxValue; i++) {
        t_d_cell *newCell = (t_d_cell *)malloc(sizeof(t_d_cell));
        newCell->value = i;
        newCell->next_0 = NULL;
        newCell->next_1 = NULL;

        for (int level = 0; level < numLevels; level++) {
            if (levels[level] == 0 || i % (1 << level) == 0) {
                levels[level]++;
                if (level == 0) {
                    newCell->next_0 = multiLevelList.head_0;
                    multiLevelList.head_0 = newCell;
                } else {
                    newCell->next_1 = multiLevelList.head_1;
                    multiLevelList.head_1 = newCell;
                }
            }
        }
    }

    return multiLevelList;
}

// Fonction de recherche standard (niveau 0)
t_d_cell *searchLevel0(t_d_list list, int value) {
    t_d_cell *current = list.head_0;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next_0;
    }
    return NULL;
}

// Fonction de recherche à partir du niveau le plus haut
t_d_cell *searchMultiLevel(t_d_list list, int value) {
    t_d_cell *current = list.head_1;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next_1;
    }

    current = list.head_0;
    while (current != NULL) {
        if (current->value == value) {
            return current;
        }
        current = current->next_0;
    }

    return NULL;
}

