#include "../inc/pathfinder.h"

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


