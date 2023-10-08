#include "../inc/pathfinder.h"

void read_file(t_list** list, const char* filename) {
    char* file_str = mx_file_to_str(filename);
    char** lines = mx_strsplit(file_str, '\n');
    int num = mx_atoi(lines[0]);

    if(num < 0) {
        mx_handle_err(INVALID_FIRST_LINE, NULL);
    }

    for(int i = 1; lines[i]; i++) {
        t_bridge* bridge = mx_split_line(lines[i]);
        if(bridge != NULL) {
            mx_push_back(list, (void*)bridge);
        }
        else {
            mx_handle_err(INVALID_LINE, (void*)&i);
        }
    }
}

