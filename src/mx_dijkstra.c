#include "../inc/pathfinder.h"

void mx_dijkstra(int** adj_matrix, int size, int start, t_list* islands) {
    int* distances = (int*)malloc(size * sizeof(int));
    bool* visited = (bool*)malloc(size * sizeof(bool));
    int index = 0, weight = 0;

    for(int i = start; i < size; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[start] = 0;

    while (index < INT_MAX) {
        index = INT_MAX;
        weight = INT_MAX;
        
        for (int i = start; i < size; i++) {
            if (!visited[i] && distances[i] < weight) { 
                index = i;
                weight = distances[i];
            }
        }
            
        if (index != INT_MAX) {
            for (int i = start; i < size; i++) {
                if (adj_matrix[index][i]) {
                    int temp = weight + adj_matrix[index][i];
                    
                    if (temp < distances[i]) {
                        distances[i] = temp;
                    }
                }
            }
            visited[index] = true;
        }
    }

    for (int i = start; i < size; i++) {
        t_list* path = NULL;

        if (distances[i] != INT_MAX) { 
            int distance = distances[i];
            if(i != start) {
                int end = i;
                int weight = distances[end];
                mx_push_front(&path, (void*)mx_list_get_by_index(islands, end));

                while (end != start) {
                    for (int j = 0; j < size; j++) {
                        if (adj_matrix[j][end]) { 
                            int temp = weight - adj_matrix[j][end]; 
                        
                            if (temp == distances[j]) {   
                                end = j;              
                                weight = temp;
                                mx_push_front(&path, (void*)mx_list_get_by_index(islands, j));
                            }
                        }
                    }
                }
                mx_print_path(start, i, distance, path, islands);
            }
        }
    }

    free(distances);
    free(visited);
}


