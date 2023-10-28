#include "../inc/pathfinder.h"

int** mx_delete_node_from_matrix(int** matrix, int size, t_list* islands, char* node) {
    int **new_matrix = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        new_matrix[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++) {
            new_matrix[i][j] = matrix[i][j];
        } 
    }

    for(int i = 0; i < size; i++) {
        new_matrix[mx_list_index_of(islands, node)][i] = 0;
        new_matrix[i][mx_list_index_of(islands, node)] = 0;
    }

    return new_matrix;
}

