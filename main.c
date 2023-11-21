#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "list.h"


int main() {

    // ------ PARTIE 1

    // Création d'une liste vide
    t_list test_list = createEmptyList(5);

    printf("Partie");
    printf("Exemple n°1 : Liste non triée\n\n");

    printf("Affichage de la liste à niveaux vides :\n");
    displayAllLevels(test_list);
    printf("");

    // Ajout de valeurs à la liste :

    addHeadInList(&test_list, 91, 3);
    addHeadInList(&test_list, 59, 1);
    addHeadInList(&test_list, 59, 5);
    addHeadInList(&test_list, 36, 3);
    addHeadInList(&test_list, 32, 5);
    addHeadInList(&test_list, 31, 2);
    addHeadInList(&test_list, 25, 1);
    addHeadInList(&test_list, 18, 4);

    printf("\nAffichage de la liste avec les valeurs ajoutées :\n");

    displayAllLevelsAlign(test_list);

    printf("_____________________\n");

    // ------ PARTIE 2


    int n=0;
    t_list order_list;
    printf("Partie 2 : \n");
    printf("Entrez une valeur de N : ");
    scanf("%d", &n);
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