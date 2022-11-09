#include "../inc/pathfinder.h"

static inline void printerr(const char* msg) {
    write(2, msg, mx_strlen(msg));
}

void mx_exit_with_err(t_val_res* val_res){
    switch(val_res->err_code){
        case ERR_INV_NUM_OF_ARGS:
            printerr("usage: ./pathfinder [filename]\n");
            break;
        case ERR_FILE_NOT_EXIST:
            printerr("error: file ");
            printerr(val_res->filename);
            printerr(" does not exist\n");
            break;
        case ERR_INV_FIRST_LINE:
            printerr("error: line 1 is not valid\n");
            break;
        case ERR_FILE_IS_EMPTY:
            printerr("error: file ");
            printerr(val_res->filename);
            printerr(" is empty\n");
            break;
        case ERR_INV_LINE:
            printerr("error: line ");
            printerr(mx_itoa(val_res->line));
            printerr(" is not valid\n");
            break;
        case ERR_INV_ISLANDS_NUM:
            printerr("error: invalid number of islands\n");
            break;
        case ERR_HAS_DUPS:
            printerr("error: dublicate bridges\n");
            break;
        case ERR_LEN_TOO_BIG:
            printerr("error: sum of bridges lengths is too big\n");
            break;
        default:
            break;
    }
    exit(-1);
}

