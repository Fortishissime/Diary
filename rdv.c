//
// Created by Achour on 06/12/2023.
//

#include "rdv.h"
#include "stdio.h"

t_rdv_list createEmptyRdvList() {
    t_rdv_list list;
    list.head = NULL;

    return list;
}

p_rdv createRdv() {
    p_rdv rdv = (p_rdv) malloc(sizeof (t_rdv));

    rdv->date = (p_date) malloc(sizeof (t_date));
    rdv->time = (p_time) malloc(sizeof (t_time));
    rdv->duration = (p_time) malloc((sizeof (t_time)));

    return rdv;
}

p_rdv_cell createRdvCell(p_rdv rdv) {
    p_rdv_cell cell = (p_rdv_cell) malloc (sizeof(t_rdv_cell));

    cell->rdv = rdv;
    cell->next = NULL;

    return cell;
}

void showRdv(p_rdv rdv) {
    printf("--------\n");
    printf(" - Date : %d/%d/%d", rdv->date->day, rdv->date->month, rdv->date->year);
    printf("| Heure : %d:%d", rdv->time->hour, rdv->time->minute);
    printf("| Durée : %dh%d min", rdv->duration->hour, rdv->duration->minute);
    printf("\n Raison : %s\n", rdv->reason);

}

void removeRdv(p_rdv rdv) {
    free(rdv);
}




