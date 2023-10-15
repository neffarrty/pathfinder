#include "../inc/pathfinder.h"

void mx_print_path(int start, int end, int distance, t_list* route, t_list* islands) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr((char*)mx_list_get_by_index(islands, start));
    mx_printstr(" -> ");
    mx_printstr((char*)mx_list_get_by_index(islands, end));
    mx_printchar('\n');
    mx_printstr("Route: ");

    int size = mx_list_size(route);
    t_list* tmp = route;
    for(int i = 0; i < size; i++) {
        if(i == size - 1) {
            mx_printstr((char*)tmp->data);
            mx_printchar('\n');
            mx_printstr("Distance: ");
            mx_printint(distance);
            mx_printstr("\n========================================\n");
        }
        else {
            mx_printstr((char*)tmp->data);
            mx_printstr(" -> ");
        }
        tmp = tmp->next;
    }
}

// void mx_print_path(int start, int end, int distance, t_list* route, t_list* islands) {
//     printf("========================================\n");
//     printf("Path: %s -> %s\n", (char*)mx_list_get_by_index(islands, start), (char*)mx_list_get_by_index(islands, end));

//     int size = mx_list_size(route);
//     t_list* tmp = route;
//     printf("Route: ");
//     for(int i = 0; i < size; i++) {
//         if(i == size - 1) {
//             printf("%s\nDistance: %d", (char*)tmp->data, distance);
//             printf("\n========================================\n");
//         }
//         else {
//             printf("%s -> ", (char*)tmp->data);
//         }
//         tmp = tmp->next;
//     }
// }

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


