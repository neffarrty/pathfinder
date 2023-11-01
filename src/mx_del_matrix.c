#include "../inc/pathfinder.h"

void mx_del_matrix(int** matrix, int size) {
    for(int i = 0; i < size; i++) {
        free(matrix[i]);
        matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
}


