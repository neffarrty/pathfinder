#include "../inc/pathfinder.h"

void mx_print_path(t_list* route, t_list* islands, int** matrix) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr((char*)route->data);
    mx_printstr(" -> ");
    mx_printstr((char*)mx_list_get_last(route));
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


