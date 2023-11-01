#include "../inc/pathfinder.h"

void mx_check_file(const char* filename) {
    int fd = open(filename, O_RDONLY);
    if(fd < 0) {
        mx_handle_err(INVALID_FILE, (void*)filename);
    }

    if(mx_file_size(fd) == 0) {
        mx_handle_err(EMPTY_FILE, (void*)filename);
    }
    close(fd);
}


