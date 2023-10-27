#include "../inc/pathfinder.h"

void mx_pathfinder(const char* filename) {
    int fd, num_of_islands = 0, **matrix = NULL;
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
        int* distances = mx_dijkstra(matrix, num_of_islands, i);
        t_list* path_list = mx_restore_path(matrix, distances, i, num_of_islands, islands_list);
        t_list* tmp = path_list;

        while(tmp) {
            t_list* path = (t_list*)tmp->data;
            mx_print_path(path, islands_list, matrix);
            
            t_list* tmp_path = path;
            while(tmp_path->next->next) {
                int **matrix_cp = (int**)malloc(num_of_islands * sizeof(int*));
                for(int j = 0; j < num_of_islands; j++) {
                    matrix_cp[j] = (int*)malloc(num_of_islands * sizeof(int));
                    for(int k = 0; k < num_of_islands; k++) {
                        matrix_cp[j][k] = matrix[j][k];
                    } 
                }

                for(int j = 0; j < num_of_islands; j++) {
                    matrix_cp[mx_list_index_of(islands_list, (char*)tmp_path->next->data)][j] = 0;
                    matrix_cp[j][mx_list_index_of(islands_list, (char*)tmp_path->next->data)] = 0;
                }

                int* distances2 = mx_dijkstra(matrix_cp, num_of_islands, i);
                t_list* path_list2 = mx_restore_path(matrix, distances2, i, num_of_islands, islands_list);
                t_list* tmp2 = path_list2;
                while(tmp2) {
                    int path_cost = mx_get_path_cost(path, matrix, islands_list);
                    int temp_cost = mx_get_path_cost((t_list*)tmp2->data, matrix, islands_list);
                    if(path_cost == temp_cost) {
                        mx_print_path((t_list*)tmp2->data, islands_list, matrix);
                    }
                    tmp2 = tmp2->next;
                }

                free(distances2);
                for(int j = 0; j < num_of_islands; j++) {
                    free(matrix_cp[j]);
                }
                free(matrix_cp);

                tmp_path = tmp_path->next;
            }

            tmp = tmp->next;
        }

        free(distances);
    }

    for(int i = 0; i < num_of_islands; i++) {
        free(matrix[i]);
    }
    free(matrix);

    mx_delete_list(&bridges_list);
    mx_delete_list(&islands_list);
}

