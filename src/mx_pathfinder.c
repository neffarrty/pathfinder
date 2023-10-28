#include "../inc/pathfinder.h"

void mx_pathfinder(const char* filename) {
    int fd, num_of_islands = 0, **matrix = NULL;
    t_list *bridges_list = NULL, *islands_list = NULL, *path_list = NULL;

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
        t_list* pathes = mx_restore_path(matrix, distances, i, num_of_islands, islands_list);
        
        t_list* tmp_pathes = pathes;
        while(tmp_pathes) {
            t_list* path = (t_list*)tmp_pathes->data;
            mx_push_back(&path_list, (void*)path);
            
            t_list* tmp_path = path;
            while(tmp_path->next->next) {
                int** new_matrix = mx_delete_node_from_matrix(matrix, num_of_islands, islands_list, (char*)tmp_path->next->data);
                int*  new_distances = mx_dijkstra(new_matrix, num_of_islands, i);
                t_list* new_pathes = mx_restore_path(matrix, new_distances, i, num_of_islands, islands_list);

                t_list* new_tmp = new_pathes;
                int path_cost = mx_get_path_cost(path, matrix, islands_list);
                while(new_tmp) {
                    int temp_cost = mx_get_path_cost((t_list*)new_tmp->data, matrix, islands_list);
                    if(path_cost == temp_cost) {
                        mx_push_back(&path_list, (void*)new_tmp->data);
                    }
                    new_tmp = new_tmp->next;
                }

                free(new_distances);
                mx_free_matrix(new_matrix, num_of_islands);

                tmp_path = tmp_path->next;
            }
            tmp_pathes = tmp_pathes->next;
        }
        free(distances);
    }
    mx_sort_list(path_list, mx_compare_pathes);
    mx_print_path_list(path_list, islands_list, matrix);

    mx_free_matrix(matrix, num_of_islands);
    mx_free_list(&path_list);
    mx_free_list(&bridges_list);
    mx_free_list(&islands_list);
}

