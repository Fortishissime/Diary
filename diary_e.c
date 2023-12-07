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

    list.head = NULL;
    list.max_levels = levels;
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
    new_entry->rdv_list = NULL;

    return new_entry;
}

