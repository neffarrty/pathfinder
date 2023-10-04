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
    int defis = mx_char_index(line, '-');
    if(defis == -1) {
        return NULL;
    }

    int comma = mx_char_index(line, ',');
    if(comma == -1) {
        return NULL;
    }

    t_bridge *bridge = (t_bridge*)malloc(sizeof(t_bridge));

    bridge->left = mx_strndup(line, defis);
    bridge->right = mx_strndup(&line[defis + 1], comma - defis - 1);

    if(!mx_is_valid_island(bridge->left) || !mx_is_valid_island(bridge->right)) {
        return NULL;
    }

    return bridge;
}
