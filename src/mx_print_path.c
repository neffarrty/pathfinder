#include "../inc/pathfinder.h"

void mx_print_path(int start, int end, int distance, t_list* route, t_list* islands) {
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
            mx_printchar('\n');
            mx_printstr("Distance: ");
            mx_printint(distance);
            mx_printstr("\n========================================\n");
        }
        else {
            mx_printstr((char*)tmp->data);
            mx_printstr(" -> ");
        }
        tmp = tmp->next;
    }
}

