#include "../inc/pathfinder.h"

bool is_valid_sum(t_list* list) {
    long sum = 0;
    t_list* tmp = list;

    while(tmp) {
        t_bridge* bridge = (t_bridge*)tmp->data;
        sum += bridge->cost;
        if(sum > INT_MAX) {
            return false;
        }
        tmp = tmp->next;
    }

    return true;
}

bool has_duplicates(t_list* list) {
	t_list* tmp = list;

	while(tmp) {
		t_bridge* key = (t_bridge*)tmp->data;
		t_list* tmp2 = tmp->next;

		while(tmp2) {
			t_bridge* bridge = (t_bridge*)tmp2->data;
			if(mx_strcmp(key->left, bridge->left) == 0 && mx_strcmp(key->right, bridge->right) == 0) {
				return true;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}

	return false;
}


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

    if(has_duplicates(list_of_bridges)) {
        mx_handle_err(DUPLICATE_BRIDGES, NULL);
    }

    if(!is_valid_sum(list_of_bridges)) {
        mx_handle_err(INVALID_SUM_OF_BRIDGES, NULL);
    }

    for(t_list* i = list_of_bridges; i != NULL; i = i->next) {
        t_bridge* bridge = (t_bridge*)i->data;
        printf("%s-%s,%d\n", bridge->left, bridge->right, bridge->cost);
    }

    return EXIT_SUCCESS;
}

