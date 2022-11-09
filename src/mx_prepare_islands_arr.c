#include "../inc/pathfinder.h"

static inline bool find(char* element, char** container){
    for(int i = 0; container[i] != NULL; i++){
        if(mx_strcmp(element, container[i]) == 0)
            return true;
    }
    return false;
}

char** mx_prepare_islands_arr(char** islands, int i_exp) {
    char** res = (char**)malloc(sizeof(char**) * i_exp + 1);
    int found_unique = 0;

    for(int i = 0; islands[i] != NULL; i++) {
        if(!find(islands[i], res)) {
            found_unique += 1;
            if(found_unique > i_exp)
                break;
            res[found_unique - 1] = mx_strdup(islands[i]);
        }

        mx_strdel(&islands[i]);
    }

    if(found_unique != i_exp) {
        t_val_res r;
        r.err_code = ERR_INV_ISLANDS_NUM;
        mx_exit_with_err(&r);
    }
    
    return res;
}

