#include "../inc/pathfinder.h"

void mx_throw_sum_err_if(bool b){
    if(b) {
        t_val_res r;
        r.err_code = ERR_LEN_TOO_BIG;
        mx_exit_with_err(&r);
    }
}

