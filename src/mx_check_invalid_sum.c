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

