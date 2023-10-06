#include "../inc/pathfinder.h"
#include <stdio.h>

int mx_char_index(char* str, char c) {
    int i = 0;
    while(str[i]) {
        if(str[i] == c) return i;
        i++;
    }

    return -1;
}

bool mx_is_valid_island(const char* s) {
    if(!mx_strlen(s)) {
        return false;
    }
    
    for(int i = 0; s[i]; i++) {
        if(!mx_isalpha(s[i])) return false;
    }
    return true;
}

t_bridge *mx_split_line(char* line) {
    int hyphen = mx_char_index(line, '-');
    if(hyphen == -1) {
        return NULL;
    }

    int comma = mx_char_index(line, ',');
    if(comma == -1) {
        return NULL;
    }

    t_bridge *bridge = (t_bridge*)malloc(sizeof(t_bridge));

    bridge->left = mx_strndup(line, hyphen);
    bridge->right = mx_strndup(&line[hyphen + 1], comma - hyphen - 1);
    bridge->cost = mx_atoi(&line[comma + 1]);

    if(!mx_is_valid_island(bridge->left) || !mx_is_valid_island(bridge->right) || mx_strcmp(bridge->left, bridge->right) == 0 || bridge->cost < 0) {
        return NULL;
    }

    return bridge;
}
