#include "pathfinder.h"

void mx_print_all_pathes(int **adj_matrix, int **dist_matrix, int size, char **islands, int *path, int path_size) {
    int start = path[0];
    int end = path[path_size];

    for (int i = 0; i < size; i++) {
        if ((adj_matrix[end][i] == dist_matrix[end][start] - dist_matrix[i][start]) && i != path[path_size]) {
            path_size++;
            path[path_size] = i;
            mx_print_all_pathes(adj_matrix, dist_matrix, size, islands, path, path_size--);
        }
    }

    if (path[path_size] != start) {
        return;
    }

    mx_print_path(path, path_size, adj_matrix, islands);
}


