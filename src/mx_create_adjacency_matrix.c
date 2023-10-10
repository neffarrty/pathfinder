#include "../inc/pathfinder.h"

int **mx_create_adjacency_matrix(t_list* bridges, t_list* islands) {
    int size = mx_list_size(islands);
    int **matrix = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
        mx_memset((void*)matrix[i], 0, size);
    }

    t_list* tmp = bridges;
    while(tmp) {
        t_bridge* bridge = (t_bridge*)tmp->data;
        int i = mx_list_index_of(islands, bridge->left);
        int j = mx_list_index_of(islands, bridge->right);

        if(matrix[i][j] == 0 && matrix[j][i] == 0) {
            matrix[i][j] = matrix[j][i] = bridge->cost;
        }
        tmp = tmp->next;
    }

    return matrix;
}
