//
// Created by Achour on 06/12/2023.
//


#include "stdio.h"
#include "stdlib.h"

#include "diary_e.h"
#include "rdv.h"
#include "utils.h"


t_entries_list createEmptyEntriesList(int levels) {
    t_entries_list list;
    list.max_levels = levels;

    list.head = (p_entries_cell*) malloc(levels * sizeof (p_entries_cell));

    for(int i = 0; i < levels; i++) {
        list.head[i] = NULL;
    }

    return list;
}


p_entry createEntry() {
    char *nom, *prenom;


    printf("Interface de création d'un nouveau contact :\n");

    printf("- Saisir le nom (en minuscule) : \n");
    nom = scanString();

    printf("- Saisir le prenom (en minuscule) : \n");
    prenom = scanString();

    p_contact new_contact = (p_contact) malloc(sizeof (t_contact));

    new_contact->nom = nom;
    new_contact->prenom = prenom;


    p_entry new_entry = (p_entry) malloc(sizeof(t_entry));

    new_entry->contact = new_contact;
    new_entry->rdv_list = (p_rdv_list) malloc(sizeof (t_rdv_list));
    new_entry->rdv_list->head = NULL;

    return new_entry;
}

p_entries_cell createEntryCell(int level, p_entry entry) {
    p_entries_cell cell = (p_entries_cell) malloc(sizeof(t_entries_cell));
    printf("here");

    cell->entry = entry;
    cell->levels = level;
    cell->next = (struct s_entries_cell **) malloc(level * sizeof(p_entries_cell));

    for (int i = 0; i < level; i++) {
        cell->next[i] = NULL;
    }

    return cell;
}

p_entries_board findContactInEntriesList(p_entries_list p_list) {
    p_entries_cell temp_entry = p_list->head[p_list->max_levels - 1];
    char letters[10];
    for(int i = p_list->max_levels - 1; i > 0; i--) { // -- Détection de la cellule locale la plus proche
        char current_char;
        int current_level = i;

        printf("Entrez la lettre n°%d de votre contact : ", p_list->max_levels - i);
        scanf(" %c", &current_char);
        printf("\n");
        letters[p_list->max_levels - 1 - i] = current_char;

        while (current_level == i) {
            if(temp_entry != NULL) {
                if (current_char < temp_entry->entry->contact->nom[p_list->max_levels - 1 - i]) {
                    temp_entry = p_list->head[i - 1];
                    current_level--;
                } else if (current_char == temp_entry->entry->contact->nom[p_list->max_levels - 1 - i]) {
                    current_level--;
                } else {
                    if (temp_entry->next[i] == NULL) {
                        current_level--;
                    } else {
                        temp_entry = temp_entry->next[i];
                    }
                }
            }
            else {
                current_level--;
            }
        }
    }

    int amount = 0;
    int end = 0; // Bool pour arrêter la boucle
    p_entries_cell check_entry = temp_entry;

    // printf("%s", temp_entry->entry->contact->nom);
    // printf("%s", letters);

    if(check_entry == NULL) {
        return NULL;
    }
    while (!end) { // -- Calcul du nombre de noms correspondant au 3 premiers caractères
        char * name = check_entry->entry->contact->nom;
        if(name[0] != letters[0] || name[1] != letters[1] || name[2] != letters[2]) { // Si un des trois caractères ne correspond pas
            end = 1;
            break;
        }
        else {
            amount += 1;
            if(check_entry->next[0] == NULL) {
                end = 1;
                break;
            } else {
                check_entry = check_entry->next[0];
            }
        }
    }

    if(amount == 0) {
        return NULL;
    }

    // Création du tableau de noms correspondant


    p_entries_board board = (p_entries_board) malloc(sizeof(t_entries_board));

    board->size = amount;
    board->board = (p_entries_cell*) malloc(amount * sizeof (p_entries_cell));


    for(int i = 0; i < amount; i++) {
        board->board[i] = temp_entry;
        temp_entry = temp_entry->next[0];
    }

    return board;
}

