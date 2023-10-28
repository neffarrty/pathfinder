#include "../inc/pathfinder.h"

void mx_free_matrix(int** matrix, int size) {
    for(int i = 0; i < size; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

