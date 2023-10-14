#include "../inc/pathfinder.h"
#include <stdio.h>

void mx_floyd_warshall(int** matrix, int size) {
    // int** next = (int**)malloc(size * sizeof(int*));
    // for(int i = 0; i < size; i++) {
    //     next[i] = (int*)malloc(size * sizeof(int));
    // }

    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         next[i][j] = i;
    //     }
    // }

    for(int k = 0; k < size; k++) {
        for(int i = 0; i < size; i++) {
            for(int j = 0; j < size; j++) {
                if(matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                    matrix[i][j] = mx_min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    // next[i][j] = next[k][j];
                }
            }
        }
    }

    // for(int i = 0; i < size; i++) {
    //     for(int j = 0; j < size; j++) {
    //         printf("%d\t", next[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
}

