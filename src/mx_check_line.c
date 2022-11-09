#include "../inc/pathfinder.h"

static inline void throw_err(int line) {
    t_val_res r;
    r.line = line;
    r.err_code = ERR_INV_LINE;
    mx_exit_with_err(&r);
}

static inline void check_island(int line, const char* island){
    for(int i = 0; island[i] != '\0'; i++){
        if(!mx_isletter(island[i]))
            throw_err(line);        
    }
}

static inline void check_bridge(int line, const char* bridge){
    for(int i = 0; bridge[i] != '\0'; i++){
        if(!mx_isdigit(bridge[i]))
            throw_err(line);
    }
}

static inline void check_for_dups(int line, const char* i1, const char* i2) {
    if(mx_strcmp(i1, i2) == 0)
        throw_err(line);
}

void mx_check_line(int line_num, char* island1, char* island2, char* bridge_len) {
    check_island(line_num, island1);
    check_island(line_num, island2);
    check_bridge(line_num, bridge_len);
    check_for_dups(line_num, island1, island2);
}

