#include "pathfinder.h"

int mx_min(int a, int b) {
    return a < b ? a : b;
}

int** mx_floyd_warshall(int** matrix, int size) {
    int** dist_matrix = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        dist_matrix[i] = (int*)malloc(size * sizeof(int));
        for(int j = 0; j < size; j++) {
            dist_matrix[i][j] = matrix[i][j];
        }
    }

    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            for(int k = 0; k < size; k++) {
                if(dist_matrix[i][k] != INF && dist_matrix[k][j] != INF) {
                    dist_matrix[i][j] = mx_min(dist_matrix[i][j], dist_matrix[i][k] + dist_matrix[k][j]);
                }
            }
        }
    }

    return dist_matrix;
}


