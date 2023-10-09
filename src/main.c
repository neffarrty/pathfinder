#include "../inc/pathfinder.h"

bool check_invalid_sum(t_list* list) {
    long sum = 0;
    t_list* tmp = list;

    while(tmp) {
        t_bridge* bridge = (t_bridge*)tmp->data;
        sum += bridge->cost;
        if(sum > INT_MAX) {
            return true;
        }
        tmp = tmp->next;
    }

    return false;
}

#include <stdio.h>
// MOVE TO HEADER AFTER TEST
int **mx_create_adjacency_matrix(t_list* bridges, t_list* islands);

int main(int argc, const char* argv[]) {
    if(argc != 2) {
        mx_handle_err(INVALID_ARGS, NULL);
    }

    const char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    t_list* list_of_bridges = NULL;

    if(fd < 0) {
        mx_handle_err(INVALID_FILE, (void*)filename);
    }

    if(mx_file_size(fd) == 0) {
        mx_handle_err(EMPTY_FILE, (void*)filename);
    }
    
    read_file(&list_of_bridges, filename);

    if(mx_check_duplicates(list_of_bridges)) {
        mx_handle_err(DUPLICATE_BRIDGES, NULL);
    }

    if(check_invalid_sum(list_of_bridges)) {
        mx_handle_err(INVALID_SUM_OF_BRIDGES, NULL);
    }

    // hardcode of list of islands to test creating adjacency matrix

    t_list* islands_list = NULL;
    char *islands[] = { "Kharkiv", "Kyiv", "Odesa", "Donetsk", "Krym", NULL };
    for(int i = 0; islands[i] != NULL; i++) {
        mx_push_back(&islands_list, islands[i]);
    }

    // printf("created list\n");
    // for(t_list* i = islands_list; i != NULL; i = i->next) {
    //     printf("%s\n", (char*)i->data);
    // }

    int **matrix = mx_create_adjacency_matrix(list_of_bridges, islands_list);

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    // for(t_list* i = list_of_bridges; i != NULL; i = i->next) {
    //     t_bridge* bridge = (t_bridge*)i->data;
    //     printf("%s-%s,%d\n", bridge->left, bridge->right, bridge->cost);
    // }

    return EXIT_SUCCESS;
}

