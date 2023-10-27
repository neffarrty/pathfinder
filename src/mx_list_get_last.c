#include "../inc/pathfinder.h"

void* mx_list_get_last(t_list* list) {
    t_list* tmp = list;
    while(tmp->next) {
        tmp = tmp->next;
    }
    return tmp->data;
}

