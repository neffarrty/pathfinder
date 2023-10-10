#include "../inc/pathfinder.h"

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
    int hyphen = mx_get_char_index(line, '-');
    if(hyphen < 0) {
        return NULL;
    }

    int comma = mx_get_char_index(line, ',');
    if(comma < 0) {
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
