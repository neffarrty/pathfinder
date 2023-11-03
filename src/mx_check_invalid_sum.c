#include "pathfinder.h"

void mx_check_invalid_sum(t_bridge** bridges, int size) {
    long sum = 0;

    for(int i = 0; i < size; i++) {
        sum += bridges[i]->distance;
        if(sum > INT_MAX) {
            mx_handle_err(INVALID_SUM_OF_BRIDGES, NULL);
        }
    }
}


