//
// Created by Achour on 08/12/2023.
//

#ifndef DIARY_APP_H
#define DIARY_APP_H

#include "diary_e.h"

int menu(p_entries_list);
int findContact(p_entries_list);
int makeContact(p_entries_list);
int showRdvOfContact(p_entries_list, p_entry);
int makeRdvForContact(p_entries_list, p_entry);
int delRdv(p_entries_list, p_entry);
int saveDiary(p_entries_list);
int loadDiary(p_entries_list);


#endif //DIARY_APP_H
