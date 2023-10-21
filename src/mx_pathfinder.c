#include "../inc/pathfinder.h"

void mx_pathfinder(const char* filename) {
    int fd, num_of_islands = 0;
    int **matrix = NULL;
    t_list *bridges_list = NULL, *islands_list = NULL;

    fd = open(filename, O_RDONLY);
    if(fd < 0) {
        mx_handle_err(INVALID_FILE, (void*)filename);
    }

    if(mx_file_size(fd) == 0) {
        mx_handle_err(EMPTY_FILE, (void*)filename);
    }
    
    num_of_islands = mx_read_file(filename, &bridges_list);

    if(mx_check_duplicates(bridges_list)) {
        mx_handle_err(DUPLICATE_BRIDGES, NULL);
    }

    if(check_invalid_sum(bridges_list)) {
        mx_handle_err(INVALID_SUM_OF_BRIDGES, NULL);
    }

    islands_list = mx_create_islands_list(bridges_list); 

    if(mx_list_size(islands_list) != num_of_islands) {
        mx_handle_err(INVALID_NUM_OF_ISLANDS, NULL);
    }

    matrix = mx_create_adjacency_matrix(bridges_list, islands_list);

    for(int i = 0; i < num_of_islands; i++) {
        mx_dijkstra(matrix, num_of_islands, i, islands_list);
    }

    for(int i = 0; i < num_of_islands; i++) {
        free(matrix[i]);
    }
    free(matrix);

    mx_delete_list(&bridges_list);
    mx_delete_list(&islands_list);
}

