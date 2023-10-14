#include "../inc/pathfinder.h"

void mx_dijkstra(int** adj_matrix, int size, int start, t_list* islands) {
    int* distances = (int*)malloc(size * sizeof(int));
    bool* visited = (bool*)malloc(size * sizeof(bool));
    int index = 0, min = 0;

    for(int i = 0; i < size; i++) {
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    distances[start] = 0;

    while (index < INT_MAX) {
        index = INT_MAX;
        min = INT_MAX;
        
        for (int i = 0; i < size; i++) {
            if (!visited[i] && distances[i] < min) { 
                index = i;
                min = distances[i];
            }
        }
            
        if (index != INT_MAX) {
            for (int i = 0; i < size; i++) {
                if (adj_matrix[index][i]) {
                    int temp = min + adj_matrix[index][i];
                    
                    if (temp < distances[i]) {
                        distances[i] = temp;
                    }
                }
            }
            visited[index] = true;
        }
    }

    for (int i = 0; i < size; i++) {
        t_list* path = NULL;

        if (distances[i] != INT_MAX) { 
            int distance = distances[i];
            if(i != start) {
                printf("========================================\nPath: %s -> %s\n", (char*)mx_list_get_by_index(islands, start), (char*)mx_list_get_by_index(islands, i));  
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

                int size = mx_list_size(path);
                t_list* tmp = path;
                printf("Route: ");
                for(int i = 0; i < size; i++) {
                    if(i == size - 1) {
                        printf("%s\nDistance: %d\n========================================\n", (char*)tmp->data, distance);
                    }
                    else {
                        printf("%s -> ", (char*)tmp->data);
                    }
                    tmp = tmp->next;
                }
            }
        }
    }
}


