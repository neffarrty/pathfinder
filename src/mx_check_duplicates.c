#include "../inc/pathfinder.h"

void mx_check_duplicates(t_bridge** bridges, int size) {
	for(int i = 0; i < size; i++) {
        for(int j = i + 1; j < size; j++) {
			if((mx_strcmp(bridges[i]->left, bridges[j]->left) == 0 && mx_strcmp(bridges[i]->right, bridges[j]->right) == 0)
			|| (mx_strcmp(bridges[i]->left, bridges[j]->right) == 0 && mx_strcmp(bridges[i]->right, bridges[j]->left) == 0)) {
				mx_handle_err(DUPLICATE_BRIDGES, NULL);
			}
		}
	}
}


