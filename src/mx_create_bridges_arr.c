#include "pathfinder.h"

int mx_create_bridges_arr(char** lines, t_bridge** bridges, int size) {
    int num = mx_atoi(lines[0]);
    if(num < 0) {
        mx_handle_err(INVALID_FIRST_LINE, NULL);
    }

    for(int i = 0; i < size; i++) {
        bridges[i] = mx_parse_line(lines[i + 1], i + 2);
    }

    return num;
}


