//
// Created by Achour on 06/12/2023.
//

#ifndef DIARY_RDV_H
#define DIARY_RDV_H

#include "stdlib.h"

// -- Structures of rendezvous

typedef struct s_date {
    int day;
    int month;
    int year;
} t_date, *p_date;


typedef struct s_time {
    int hour;
    int minute;
} t_time, *p_time;


typedef struct s_contact {
    char *nom;
    char *prenom;
} t_contact, *p_contact;


typedef struct s_rdv {
    p_date date;

    p_time time;
    p_time duration;

    char *reason;

} t_rdv, *p_rdv;

// -- List of rendezvous

typedef struct s_rdv_cell {
    p_rdv rdv;
    struct s_rdv_cell *next;
} t_rdv_cell, *p_rdv_cell;

typedef struct s_rdv_list {
    p_rdv_cell head;
} t_rdv_list, *p_rdv_list ;

// -- Functions - List of rendezvous

p_date createDate(int, int, int);
p_time createTime(int, int);

t_rdv_list createEmptyRdvList();

p_rdv createRdv();
p_rdv_cell createRdvCell(p_rdv);

void showRdv(p_rdv);
void removeRdv(p_rdv);



#endif //DIARY_RDV_H
