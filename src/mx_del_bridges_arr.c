#include "../inc/pathfinder.h"

void mx_del_bridges_arr(t_bridge** bridges, int size) {
    for(int i = 0; i < size; i++) {
        free(bridges[i]->left);
        bridges[i]->left = NULL;
        free(bridges[i]->right);
        bridges[i]->right = NULL;
        free(bridges[i]);
        bridges[i] = NULL;
    }
    free(bridges);
    bridges = NULL;
}

