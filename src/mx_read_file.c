#include "../inc/pathfinder.h"
#include <stdio.h>

void read_file(const char* filename) {
    char* file_str = mx_file_to_str(filename);
    char** lines = mx_strsplit(file_str, '\n');

    int num = mx_atoi(lines[0]);
    if(num < 0) {
        mx_printerr("error: line 1 is not valid\n");
        exit(EXIT_FAILURE);
    }

    mx_print_strarr(lines, "\n");
}

