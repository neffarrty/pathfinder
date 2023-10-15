#include "../inc/pathfinder.h"

bool mx_check_duplicates(t_list* list) {
	t_list* tmp = list;

	while(tmp) {
		t_bridge* key = (t_bridge*)tmp->data;
        if(mx_list_has_bridge(tmp->next, key)) {
            return true;
        }
        tmp = tmp->next;
	}

	return false;
}


