#include "../inc/pathfinder.h"

t_list* mx_restore_path(int** matrix, int* distances, int start, int size, t_list* islands) {
    t_list* path_list = NULL;
    
    for (int i = start; i < size; i++) {
        t_list* path = NULL;

        if (distances[i] != INFINITY) { 
            if(i != start) {
                int end = i;
                int weight = distances[end];
                mx_push_front(&path, (void*)mx_strdup(mx_list_get_by_index(islands, end)));

                while (end != start) {
                    for (int j = 0; j < size; j++) {
                        if (matrix[j][end]) { 
                            int temp = weight - matrix[j][end]; 
                        
                            if (temp == distances[j]) {   
                                end = j;              
                                weight = temp;
                                mx_push_front(&path, (void*)mx_strdup(mx_list_get_by_index(islands, j)));
                            }
                        }
                    }
                }
                mx_push_back(&path_list, (void*)path);
            }
        }
    }

    return path_list;
}

