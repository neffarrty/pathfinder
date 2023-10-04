#include "../inc/pathfinder.h"

void mx_printerr(const char *s) {
    write(STDERR_FILENO, s, mx_strlen(s));
}

// void handle_error(const char* err, int err_type, const char* file, int line) {
//     switch(err_type) {
//         case INVALID_ARGS:
//             mx_printerr("usage: ./pathfinder [filename]\n");
//             break;
// 	    case INVALID_FILE:
//             mx_printerr("error: file ");
//             mx_printerr(file);
//             mx_printerr("does not exist\n");
//             break;
// 	    case EMPTY_FILE:
//             mx_printerr("error: file ");
//             mx_printerr(file);
//             mx_printerr("is empty\n");
//             break;
// 	    case INVALID_FIRST_LINE:
//             mx_printerr("error: line 1 is not valid\n");
//             break;
//     }
    
//     exit(EXIT_FAILURE);
// }
