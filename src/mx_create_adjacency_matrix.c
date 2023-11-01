#include "../inc/pathfinder.h"

int **mx_create_adjacency_matrix(t_bridge** bridges, int bridges_size, char** islands, int size) {
    int **matrix = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++) {
            if(i != j) {
                matrix[i][j] = INF;
            } else {
                matrix[i][j] = 0;
            }
        }
    }

    for(int i = 0; i < bridges_size; i++) {
        int j = mx_array_index_of(islands, bridges[i]->left);
        int k = mx_array_index_of(islands, bridges[i]->right);

        matrix[j][k] = matrix[k][j] = bridges[i]->distance;
    }

    return matrix;
}


