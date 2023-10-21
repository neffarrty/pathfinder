#include "../inc/pathfinder.h"

t_list* mx_create_islands_list(t_list* bridges) {
    t_list* islands = NULL;
    t_list* tmp = bridges;

    while(tmp) {
        t_bridge* bridge = (t_bridge*)tmp->data;
        if(mx_list_index_of(islands, bridge->left) == -1) {
            mx_push_back(&islands, (void*)bridge->left);
        }
        if(mx_list_index_of(islands, bridge->right) == -1) {
            mx_push_back(&islands, (void*)bridge->right);
        }
        tmp = tmp->next;
    }

    return islands;
}

