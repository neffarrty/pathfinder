#include "../inc/pathfinder.h"

void mx_print_path_list(t_list* list, t_list* islands, int** matrix) {
    t_list* tmp = list;
    while(tmp) {
        mx_print_path((t_list*)tmp->data, islands, matrix);
        tmp = tmp->next;
    }
}


