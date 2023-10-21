#include "../inc/pathfinder.h"
#include <stdio.h>

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_handle_err(INVALID_ARGS, NULL);
    }

    mx_pathfinder(argv[1]);

    return EXIT_SUCCESS;
}


