#include "../inc/pathfinder.h"

void mx_handle_err(int err_type, void* param) {
    switch(err_type) {
        case INVALID_ARGS:
            mx_printerr("usage: ./pathfinder [filename]\n");
            break;
 	    case INVALID_FILE:
            mx_printerr("error: file ");
            mx_printerr((char*)param);
            mx_printerr(" does not exist\n");
            break;
 	    case EMPTY_FILE:
            mx_printerr("error: file ");
            mx_printerr((char*)param);
            mx_printerr(" is empty\n");
            break;
 	    case INVALID_FIRST_LINE:
            mx_printerr("error: line 1 is not valid\n");
            break;
        case INVALID_LINE:
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(*(int*)param + 1));
            mx_printerr(" is not valid\n");
            break;
        case INVALID_NUM_OF_ISLANDS:
            mx_printerr("error: invalid number of islands\n");
            break;
	    case DUPLICATE_BRIDGES:
            mx_printerr("error: duplicate bridges\n");
            break;
	    case INVALID_SUM_OF_BRIDGES:
            mx_printerr("error: sum of bridges lengths is too big\n");
            break;    
    }
    
    exit(EXIT_FAILURE);
}

