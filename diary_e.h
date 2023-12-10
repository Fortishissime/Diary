//
// Created by Achour on 06/12/2023.
//

#ifndef DIARY_DIARY_E_H
#define DIARY_DIARY_E_H

#include "rdv.h"


// ----- Structures -----


// -- Structure entrée de donnée (dans l'agenda)

typedef struct s_entry {
    p_contact contact;
    p_rdv_list rdv_list;
} t_entry, *p_entry;

// -- Structure cellule d'entrée de donnée

typedef struct s_entries_cell {
    int levels;
    p_entry entry;
    struct s_entries_cell **next;
} t_entries_cell, *p_entries_cell;

// -- Structure liste d'entrées de données

typedef struct s_entries_list {
    int max_levels;
    p_entries_cell *head;
} t_entries_list, *p_entries_list;

typedef struct s_entries_board {
    int size;
    p_entries_cell *board;
} t_entries_board, *p_entries_board;

// ----- Fonctions -----


p_entry createEntry(); //


p_entries_cell createEntryCell(int, p_entry);
t_entries_list createEmptyEntriesList(int);
p_entries_board findContactInEntriesList(p_entries_list);




void addEntryInList(p_entries_list, p_entry);
void removeEntryFromList(char *);


void showRdvFromEntry(p_entry);
void removeRdvFromEntry(p_entry, int);






#endif //DIARY_DIARY_E_H
