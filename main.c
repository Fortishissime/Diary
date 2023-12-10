/* PROJET ALGO - AGENDA

 * Authors : Massil Achour AMI SAADA - Lucas VONG - Angela TCHING
 * Version : 1.0

 * Description : Projet d'agenda en trois parties. Les deux premières parties permettent d'aborder le projet tandis que
 * la dernière est la réalisation concrète de l'application

*/


/* Description des fichiers :
 * app.c : Equivalent du "main", écrit pour pouvoir associer un header
 * utils.c : Recueil de fonctions globalement utile à l'ensemble du projet
 * list.c / cell.c : Parties 1 et 2 du projet
 * rdv.c : Partie 3 du projet. S'occupe de gérer les structures des rendez-vous
 * diary_e.c : Partie 3 du projet. S'occupe de gérer les structures d'entrées de l'agenda et des listes / cellules associées
 *
*/


#include <stdio.h>

#include "app.h"
#include "list.h"




int app() {
    t_entries_list list = createEmptyEntriesList(4);
    p_entries_list list_p = &list;

    menu(list_p);
    


    return 0;
}



int previewParts() {

    // ------ PARTIE 1

    // Création d'une liste vide
    t_lvl_list test_list = createEmptyLvlList(5);

    printf("Partie 1 :");
    printf("Exemple n°1 : Liste non triée\n\n");

    printf("Affichage de la liste à niveaux vides :\n");
    displayAllLevels(test_list);
    printf("");

    // Ajout de valeurs à la liste :

    addHeadInLvlList(&test_list, 91, 3);
    addHeadInLvlList(&test_list, 59, 1);
    addHeadInLvlList(&test_list, 59, 5);
    addHeadInLvlList(&test_list, 36, 3);
    addHeadInLvlList(&test_list, 32, 5);
    addHeadInLvlList(&test_list, 31, 2);
    addHeadInLvlList(&test_list, 25, 1);
    addHeadInLvlList(&test_list, 18, 4);

    printf("\nAffichage de la liste avec les valeurs ajoutées :\n");

    displayAllLevelsAlign(test_list);

    printf("_____________________\n");

    // ------ PARTIE 2


    int n=0;
    t_lvl_list order_list;
    printf("Partie 2 : \n");
    printf("Entrez une valeur de N : ");
    scanf(" %d", &n);
    printf("\n");

    order_list = createOneOnTwoList(n);
    displayAllLevelsAlign(order_list);

    int val = -1;
    int count = 1;

    while(val != -9999) {
        printf("Essai libre n°%d - Recherche de la valeur : ", count);
        scanf("%d", &val);
        printf("\n");
        if(classicSearchInList(order_list, val)) {
            printf("[CLASSICAL] Valeur %d trouvée\n", val);
        }
        else {
            printf("[CLASSICAL] Valeur %d non-trouvée\n", val);
        }

        if(optimalSearchInList(order_list, val)) {
            printf("[OPTIMAL] Valeur %d trouvée\n", val);
        }
        else {
            printf("[OPTIMAL] Valeur %d non-trouvée\n", val);
        }

        printf("\n");
        count += 1;
    }

    return 0;
}



int main() {
    int choice;
    printf("PROJET ALGORITHMIQUE - Accéder à quelle partie ?\n1 : Parties 1 et 2\n2 : Partie 3\nFaites votre choix : ");
    scanf("%d", &choice);

    while(choice <= 0 || choice > 2) {
        printf("\nErreur - Choix non conforme. Veuillez réessayer : ");
        scanf("%d", &choice);
    }

    if(choice == 1) {
        return previewParts();
    }
    else return app();

    return 0;
}
