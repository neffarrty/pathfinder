#include "../inc/pathfinder.h"

bool mx_compare_pathes(void* fst, void* scd) {
    t_list* fst_tmp = (t_list*)fst;
    t_list* scd_tmp = (t_list*)scd;

    if(mx_strcmp((char*)fst_tmp->data, (char*)scd_tmp->data) == 0
        && mx_list_size((t_list*)fst_tmp) == mx_list_size((t_list*)scd_tmp)
        && mx_strcmp((char*)mx_list_get_last(fst_tmp), (char*)mx_list_get_last(scd_tmp)) == 0) {
            while(fst_tmp && scd_tmp) {
                if(mx_strcmp((char*)fst_tmp->data, (char*)scd_tmp->data) > 0) {
                    return true;
                }
                fst_tmp = fst_tmp->next;
                scd_tmp = scd_tmp->next; 
            }
    }

    return false;
}

