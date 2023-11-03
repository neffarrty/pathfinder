#include "pathfinder.h"

void mx_print_path(int* path, int size, int** matrix, char** islands) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[path[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands[path[0]]);
    mx_printchar('\n');

    mx_printstr("Route: ");
    for(int i = 1; i < size + 1; i++) {
        mx_printstr(islands[path[i]]);
        if(i != size) {
            mx_printstr(" -> ");
        }
    }
    mx_printchar('\n');

    mx_printstr("Distance: ");
    int total_cost = 0;
    for(int i = 1; i < size; i++) {
        mx_printint(matrix[path[i]][path[i + 1]]);
        total_cost += matrix[path[i]][path[i + 1]];
        if(i != size - 1) {
            mx_printstr(" + ");
        }
    }
    if(size > 2) {
        mx_printstr(" = ");
        mx_printint(total_cost);
    }
    mx_printchar('\n');

    mx_printstr("========================================\n");
}


