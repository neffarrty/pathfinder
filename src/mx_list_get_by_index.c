#include "../inc/pathfinder.h"

char* mx_list_get_by_index(t_list* list, int i) {
    t_list* tmp = list;
    int index = 0;

    while(tmp && index < i) {
        tmp = tmp->next;
        index++;
    }

    return (char*)tmp->data;
}


