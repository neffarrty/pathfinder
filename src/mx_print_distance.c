#include "../inc/pathfinder.h"

void mx_print_distance(t_list* route, t_list* islands, int** matrix, int size) {
    t_list* tmp = route;
    int sum = 0;
    
    while(tmp->next) {
        int left = mx_list_index_of(islands, (char*)tmp->data);
        int right = mx_list_index_of(islands, (char*)tmp->next->data);
        mx_printint(matrix[left][right]);
        sum += matrix[left][right];

        if(tmp->next->next != NULL) {
            mx_printstr(" + ");
        }
        else {
            if(size > 2) {
                mx_printstr(" = ");
                mx_printint(sum);
            }
        }
        tmp = tmp->next;
    }
}

