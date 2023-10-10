#include "../inc/pathfinder.h"

int mx_list_index_of(t_list* list, const char* key) {
    t_list* tmp = list;
    int index = 0;

    while(tmp) {
        if(mx_strcmp((char*)tmp->data, key) == 0) {
            return index;
        }
        tmp = tmp->next;
        index++;
    }

    return -1;
}

