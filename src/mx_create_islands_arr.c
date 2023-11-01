#include "../inc/pathfinder.h"

char** mx_create_islands_arr(t_bridge** bridges, int bridges_size, int islands_size) {
    char** islands = (char**)malloc((islands_size + 1) * sizeof(char*));
    islands[islands_size] = NULL;
    int index = -1;

    for(int i = 0; i < bridges_size; i++) {
        if(mx_array_index_of(islands, bridges[i]->left) == -1) {
            index++;
            if(index < islands_size) {
                islands[index] = mx_strdup(bridges[i]->left);
            }
            else {
                mx_handle_err(INVALID_NUM_OF_ISLANDS, NULL);
            }
        }
        if(mx_array_index_of(islands, bridges[i]->right) == -1) {
            index++;
            if(index < islands_size) {
                islands[index] = mx_strdup(bridges[i]->right);
            }
            else {
                mx_handle_err(INVALID_NUM_OF_ISLANDS, NULL);
            }
        }
    }

    return islands;
}


