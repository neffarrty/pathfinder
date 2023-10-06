#include "../inc/pathfinder.h"

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_handle_err(INVALID_ARGS, NULL);
    }
    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    t_list* list_of_bridges = NULL;

    if(fd < 0) {
        mx_handle_err(INVALID_FILE, (void*)filename);
    }

    if(mx_file_size(fd) == 0) {
        mx_handle_err(EMPTY_FILE, (void*)filename);
    }
    
    read_file(list_of_bridges, filename);
    //printf("%d\n", mx_list_size(list_of_bridges));
    // for(t_list* i = list_of_bridges; i->next != NULL; i = i->next) {
    //     if(i->data != NULL) {
    //         t_bridge* bridge = (t_bridge*)i->data;
    //         printf("%s-%d\n", bridge->left, mx_strlen(bridge->left));
    //         printf("%s-%d\n", bridge->right, mx_strlen(bridge->right));
    //     }
    // }

    return EXIT_SUCCESS;
}

