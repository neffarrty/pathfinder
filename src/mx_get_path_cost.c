#include "../inc/pathfinder.h"

int mx_get_path_cost(t_list* path, int** matrix, t_list* islands) {
    t_list* tmp = path;
    int cost = 0;

    while(tmp->next) {
        int left = mx_list_index_of(islands, (char*)tmp->data);
        int right = mx_list_index_of(islands, (char*)tmp->next->data);
        cost += matrix[left][right];

        tmp = tmp->next;
    }

    return cost;
}

