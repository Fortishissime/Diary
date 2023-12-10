//
// Created by Achour on 08/12/2023.
//

#include "stdlib.h"
#include "stdio.h"

#include "app.h"
#include "utils.h"

int findContact(p_entries_list p_list) {
    p_entries_board entries_board = findContactInEntriesList(p_list);

    if(entries_board == NULL) {
        printf("Aucun contact ne commence par cette suite de caractères !\n");
        menu(p_list);
    }
    else {
        printf("Liste de contacts possible : \n");

        for(int i = 0; i < entries_board->size; i++) {
            char * nom = entries_board->board[i]->entry->contact->nom;
            char * prenom = entries_board->board[i]->entry->contact->prenom;

            printf("%d : %s_%s\n", i+1, nom, prenom);
        }
        int choice = -1;

        printf("\nSélectionner le contact : ");
        scanf("%d", &choice);

        while (choice <= 0 || choice > entries_board->size) {
            printf("\nErreur : Entrée non valide, veuillez réessayer : ");
            scanf("%d", &choice);
        }

        p_entry entry_picked = entries_board->board[choice-1]->entry;

        printf("\nContact sélectionné : %s_%s", entry_picked->contact->nom, entry_picked->contact->prenom);
        printf("\nQue faire ? :");

        printf("\n1 : Créer un rendez-vous");
        printf("\n2 : Afficher les rendez-vous");
        printf("\n3 : Revenir au menu principal");
        printf("\n4 : Quitter l'application");

        printf("Votre choix : ");
        scanf("%d", &choice);

        while (choice <= 0 || choice > 4) {
            printf("\nErreur : Entrée non valide, veuillez réessayer : ");
            scanf("%d", &choice);
        }

        switch (choice) {
            case 1: {
                makeRdvForContact(p_list, entry_picked);
            }
            case 2: {
                showRdvOfContact(p_list, entry_picked);
            }
            case 3: {
                menu(p_list);
            }
            case 4: {
                printf("\nÀ bientot !");
                return 0;
            }
        }
    }
    return 0;
}

int makeContact(p_entries_list list) {
    p_entry new_entry = createEntry();

    int current_level = list->max_levels - 1;
    int max_level = list->max_levels - 1;

    int undetermined = 1;
    p_entries_cell check_cell = list->head[current_level];

    if(check_cell == NULL) {
        undetermined = 0;
    }

    while (undetermined) { // Tant que la position exacte n'est pas connue - Détermination de la position d'insertion
        p_entries_cell prev = check_cell;
        p_entries_cell temp = prev->next[current_level];

        int isLetterInList = 0;

        while (temp != NULL && temp->entry->contact->nom[max_level - current_level] >
                                     new_entry->contact->nom[max_level - current_level]) {

            if (temp->entry->contact->nom[max_level - current_level] ==
                new_entry->contact->nom[max_level - current_level]) {
                int isPreviousLettersCorrect = 1;

                for (int i = 0; i < max_level - current_level; i++) { // Vérification des caractères précédents
                    if (temp->entry->contact->nom[i] > new_entry->contact->nom[i]) {
                        isPreviousLettersCorrect = 0;
                        break;
                    }
                }

                if(isPreviousLettersCorrect) {
                    isLetterInList = 1;
                    break;
                }
            }

            prev = prev->next[current_level];
            temp = temp->next[current_level];

        }
        if(!isLetterInList) {
            check_cell = prev;
            undetermined = 0;
            break;
        }
        else {
            check_cell = prev;
            current_level -= 1;

            if(current_level < 0) {
                undetermined = 0;
            }
        }
    }

    p_entries_cell new_cell = createEntryCell(current_level+1, new_entry);


    for(int i = current_level; i >= 0; i--) {
        if(check_cell == NULL) {
            list->head[i] = new_cell;
        } else {
            new_cell->next[i] = check_cell->next[i];
            check_cell->next[i] = new_cell;
        }
    }


    printf("Contact ajouté !\n Retour au menu\n\n");

    return menu(list);



    return 0;
}



int menu(p_entries_list p_list) {
    printf("Bienvenue dans votre agenda. Sélectionnez une option : \n");
    printf("1 : Rechercher un contact\n");
    printf("2 : Créer un contact\n");
    printf("3 : Créer un rendez-vous\n");
    printf("4 : Supprimer un rendez-vous\n");
    printf("5 : Sauvegarder votre agenda\n");
    printf("6 : Charger votre agenda\n");
    printf("7 : Quitter\n\n");

    printf("Votre choix : ");

    int choice = -1;

    fflush(stdin);
    scanf(" %d", &choice);
    while (choice <= 0 || choice > 7) {
        printf("\nErreur : Choix incorrect. Veuillez réessayer : ");
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1: {
            return findContact(p_list);
        }
        case 2: {
            return makeContact(p_list);
        }
        case 3: {
            return makeRdvForContact(p_list, NULL);
        }
        case 4: {
            return delRdv(p_list, NULL);
        }
        case 5: {
            return saveDiary(p_list);
        }
        case 6: {
            return loadDiary(p_list);
        }
        case 7: {
            return 0;
        }
        default: {
            printf("Erreur fatale : Choix invalide. Retour au menu");
            return menu(p_list);
        }
    }
}

int showRdvOfContact(p_entries_list p_list, p_entry entry) {
    if(entry->rdv_list->head == NULL) {
        printf("\nCe contact n'a aucun rendez-vous associé");
    }
    else {
        printf("Liste des rendez-vous : ");

        p_rdv_cell temp = entry->rdv_list->head;

        while (temp != NULL) {
            showRdv(temp->rdv);
            temp = temp->next;
        }

    }
    int choice = -1;

    printf("\n1 : Créer un rendez-vous");
    printf("\n2 : Afficher les rendez-vous");
    printf("\n3 : Revenir au menu principal");
    printf("\n4 : Quitter l'application");

    printf("Votre choix : ");
    scanf("%d", &choice);

    while (choice <= 0 || choice > 4) {
        printf("\nErreur : Entrée non valide, veuillez réessayer : ");
        scanf("%d", &choice);
    }

    switch (choice) {
        case 1: {
            makeRdvForContact(p_list, entry);
        }
        case 2: {
            showRdvOfContact(p_list, entry);
        }
        case 3: {
            menu(p_list);
        }
        case 4: {
            printf("\nÀ bientot !");
            return 0;
        }
    }
}

int makeRdvForContact(p_entries_list p_list, p_entry entry) {
    printf("\nInterface de création d'un rendez-vous :");

    p_rdv rdv = createRdv();

    int day, month, year, hour, minutes, duration_h, duration_m;

    fflush(stdin);
    printf("\nSaisir la date (format : J/M/AAAA");
    scanf(" %d/%d/%d", &day, &month, &year);

    while (day <= 0 || day > 31 || month <= 0 || month > 12) {
        printf("\nValeurs entrées incorrect");
        printf("\nSaisir la date (format : J/M/AAAA");
        scanf(" %d/%d/%d", &day, &month, &year);
    }

    rdv->date->day = day;
    rdv->date->month = month;
    rdv->date->year = year;


    fflush(stdin);
    printf("\nSaisir l'heure du rendez-vous (au format HH:MM) : ");
    scanf(" %d:%d", &hour, &minutes);

    while (hour < 0 || hour > 23 || minutes < 0 || minutes > 60) {
        printf("\nValeurs entrées incorrect");
        printf("\nSaisir l'heure du rendez-vous (au format HH:MM) : ");
        fflush(stdin);
        scanf(" %d:%d", &hour, &minutes);
    }

    rdv->time->hour = hour;
    rdv->time->minute = minutes;



    printf("\nSaisir la durée du rendez-vous (au format H/M) :");
    fflush(stdin);
    scanf(" %d/%d", &duration_h, &duration_m);

    while (duration_h < 0 || duration_h > 23 || duration_m < 0 || duration_m > 60) {
        printf("\nValeurs entrées incorrect");
        printf("\nSaisir la durée du rendez-vous (au format H/M) : ");
        fflush(stdin);
        scanf(" %d:%d", &duration_h, &duration_m);
    }

    rdv->duration->hour = duration_h;
    rdv->duration->minute = duration_m;

    printf("\nSaisir une raison de rendez-vous : ");
    fflush(stdin);
    rdv->reason = scanString();

    p_rdv_cell rdv_cell = createRdvCell(rdv);

    if(entry->rdv_list->head == NULL) {
        entry->rdv_list->head = rdv_cell;
    } else {
        p_rdv_cell temp = entry->rdv_list->head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = rdv_cell;
    }

    printf("\nRendez-vous ajoutée ! Retour au menu princial");
    return menu(p_list);
}

int saveDiary(p_entries_list p_list) {
    return 0;
}

int loadDiary(p_entries_list p_list) {
    return 0;
}

int delRdv(p_entries_list p_list, p_entry entry) {
    return 0;
}