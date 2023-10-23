#include <stdio.h>
#include "struc.c"
#include <time.h>
#include "timer.h" // Assurez-vous d'avoir un module timer fonctionnel
int main() {
    const int numLevels = 5;
    const int maxValue = 100000;

    // Créez une liste à niveaux
    t_d_list multiLevelList = createMultiLevelList(numLevels, maxValue);

    // Effectuez des recherches et mesurez le temps
    int numSearches[] = {1000, 10000, 100000};
    for (int i = 0; i < 3; i++) {
        int numSearch = numSearches[i];

        // Recherche standard (niveau 0)
        startTimer();
        for (int j = 0; j < numSearch; j++) {
            int target = rand() % maxValue + 1;
            t_d_cell *result = searchLevel0(multiLevelList, target);
        }
        stopTimer();
        getTimeAsString();

        // Recherche à plusieurs niveaux
        startTimer();
        for (int j = 0; j < numSearch; j++) {
            int target = rand() % maxValue + 1;
            t_d_cell *result = searchMultiLevel(multiLevelList, target);
        }
        stopTimer();
        getTimeAsString();

        printf("Nombre de recherche : %d\n", numSearch);
        printf("\n");
    }

    return 0;
}
