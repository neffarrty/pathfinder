#include "pathfinder.h"

t_bridge *mx_parse_line(char* line, int num_line) {
    int hyphen = mx_get_char_index(line, '-');
    if(hyphen < 0) {
        mx_handle_err(INVALID_LINE, (void*)&num_line);
    }

    int comma = mx_get_char_index(line, ',');
    if(comma < 0) {
        mx_handle_err(INVALID_LINE, (void*)&num_line);
    }

    t_bridge *bridge = (t_bridge*)malloc(sizeof(t_bridge));

    bridge->left = mx_strndup(line, hyphen);
    bridge->right = mx_strndup(&line[hyphen + 1], comma - hyphen - 1);
    bridge->distance = mx_atoi(&line[comma + 1]);

    if(!mx_check_island(bridge->left) || !mx_check_island(bridge->right) 
     || mx_strcmp(bridge->left, bridge->right) == 0 || bridge->distance < 0) {
        mx_handle_err(INVALID_LINE, (void*)&num_line);
    }

    return bridge;
}


