#include "../inc/pathfinder.h"

int* mx_dijkstra(int** adj_matrix, int size, int start) {
    int* distances = (int*)malloc(size * sizeof(int));
    bool* visited = (bool*)malloc(size * sizeof(bool));
    int index = 0, weight = 0;

    for(int i = 0; i < size; i++) {
        distances[i] = INFINITY;
        visited[i] = false;
    }
    distances[start] = 0;

    while (index < INFINITY) {
        index = INFINITY;
        weight = INFINITY;
        
        for (int i = 0; i < size; i++) {
            if (!visited[i] && distances[i] < weight) { 
                index = i;
                weight = distances[i];
            }
        }
            
        if (index != INFINITY) {
            for (int i = 0; i < size; i++) {
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
    free(visited);

    return distances;
}


