#include "../inc/pathfinder.h"

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(argv[1], O_RDONLY);

    if(fd < 0) {
        mx_printerr("error: file [filename] does not exist\n");
        exit(EXIT_FAILURE);
    }

    if(mx_file_size(fd) == 0) {
        mx_printerr("error: file [filename] is empty\n");
        exit(EXIT_FAILURE);
    }
    
    read_file(argv[1]);
    t_bridge *bridge = mx_split_line("Kharkiv-Odesa,4");
    if(bridge != NULL) {
        printf("%s-%d\n", bridge->left, mx_strlen(bridge->left));
        printf("%s-%d\n", bridge->right, mx_strlen(bridge->right));
    }

    return EXIT_SUCCESS;
}

