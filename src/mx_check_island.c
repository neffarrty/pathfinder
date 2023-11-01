#include "../inc/pathfinder.h"

bool mx_check_island(const char* s) {
    if(!mx_strlen(s)) {
        return false;
    }
    
    for(int i = 0; s[i]; i++) {
        if(!mx_isalpha(s[i])) return false;
    }
    return true;
}


