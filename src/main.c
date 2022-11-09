#include "../inc/pathfinder.h"

int main(int argc, char **argv){
    if(argc != 2){
        t_val_res r;
        r.err_code = ERR_INV_NUM_OF_ARGS;
        mx_exit_with_err(&r);
    } else {
        mx_process_data(argv);
    }
}

