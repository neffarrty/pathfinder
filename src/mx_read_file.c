#include "../inc/pathfinder.h"
#include <stdio.h>

int read_file(const char* filename, t_list** bridges) {
    char* file_str = mx_file_to_str(filename);
    char** lines = mx_strsplit(file_str, '\n');
    int num = mx_atoi(lines[0]);

    if(num < 0) {
        mx_handle_err(INVALID_FIRST_LINE, NULL);
    }

    for(int i = 1; lines[i]; i++) {
        t_bridge* bridge = mx_split_line(lines[i]);
        if(bridge != NULL) {
            mx_push_back(bridges, (void*)bridge);
        }
        else {
            int line_num = i + 1;
            mx_handle_err(INVALID_LINE, (void*)&line_num);
        }
    }

    return num;

}

t_list* mx_create_islands_list(t_list* bridges) {
    t_list* islands = NULL;
    t_list* tmp = bridges;

    while(tmp) {
        t_bridge* bridge = (t_bridge*)tmp->data;
        if(mx_list_index_of(islands, bridge->left) == -1) {
            mx_push_back(&islands, (void*)bridge->left);
        }
        if(mx_list_index_of(islands, bridge->right) == -1) {
            mx_push_back(&islands, (void*)bridge->right);
        }
        tmp = tmp->next;
    }

    // t_list* temp = islands;
    // while(tmp) {
    //     printf("%s\n", (char*)temp->data);
    //     tmp = tmp->next;
    // }
    return islands;
}

