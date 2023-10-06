#include "../inc/pathfinder.h"

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_handle_err(INVALID_ARGS, NULL);
    }
    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);

    if(fd < 0) {
        mx_handle_err(INVALID_FILE, (void*)filename);
    }

    if(mx_file_size(fd) == 0) {
        mx_handle_err(EMPTY_FILE, (void*)filename);
    }
    
    read_file(filename);
    t_bridge *bridge = mx_split_line("Kharkiv-Odesa,4");
    if(bridge != NULL) {
        printf("%s-%d\n", bridge->left, mx_strlen(bridge->left));
        printf("%s-%d\n", bridge->right, mx_strlen(bridge->right));
    }

    return EXIT_SUCCESS;
}

