#include "../inc/pathfinder.h"

int mx_read_file(const char* filename, t_list** bridges) {
    char* file_str = mx_file_to_str(filename);
    char** lines = mx_strsplit(file_str, '\n');
    int num = mx_atoi(lines[0]);

    if(num < 0) {
        mx_handle_err(INVALID_FIRST_LINE, NULL);
    }

    for(int i = 1; lines[i]; i++) {
        t_bridge* bridge = mx_parse_line(lines[i]);
        if(bridge != NULL) {
            mx_push_back(bridges, (void*)bridge);
        }
        else {
            int line = i + 1;
            mx_handle_err(INVALID_LINE, (void*)&line);
        }
    }
    free(file_str);
    mx_del_strarr(&lines);

    return num;
}


