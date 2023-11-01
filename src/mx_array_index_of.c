#include "../inc/pathfinder.h"

int mx_array_index_of(char** arr, const char* key) {
    if(arr != NULL || key != NULL) {
        for(int i = 0; arr[i] != NULL; i++) {
            if(mx_strcmp(arr[i], key) == 0) {
                return i;
            }
        }
    }

    return -1;
}


