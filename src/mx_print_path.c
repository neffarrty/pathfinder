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

void mx_print_path(int start, int end, t_list* route, t_list* islands, int** matrix) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr((char*)mx_list_get_by_index(islands, start));
    mx_printstr(" -> ");
    mx_printstr((char*)mx_list_get_by_index(islands, end));
    mx_printchar('\n');
    mx_printstr("Route: ");

    int size = mx_list_size(route);
    t_list* tmp = route;
    for(int i = 0; i < size; i++) {
        if(i == size - 1) {
            mx_printstr((char*)tmp->data);
            mx_printstr("\nDistance: ");
            mx_print_distance(route, islands, matrix, size);
            mx_printstr("\n========================================\n");
        }
        else {
            mx_printstr((char*)tmp->data);
            mx_printstr(" -> ");
        }
        tmp = tmp->next;
    }
}


