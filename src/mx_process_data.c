#include "../inc/pathfinder.h"


static inline void check_if_file_exist(const char* filename){
    int fd = open(filename, O_RDONLY);
    if(fd < 0){
        close(fd);
        t_val_res r;
        r.filename = filename;
        r.err_code = ERR_FILE_NOT_EXIST;
        mx_exit_with_err(&r);
    }

    close(fd);
}

static inline void check_if_empty(const char* file_src, const char* filename) {
    if(file_src == NULL || mx_strlen(file_src) == 0) {
        t_val_res r;
        r.filename = filename;
        r.err_code = ERR_FILE_IS_EMPTY;
        mx_exit_with_err(&r);
    }
}

static inline int check_first_line(const char* file_src) {
    char* first_line = mx_strndup(file_src, mx_get_char_index(file_src, '\n'));
    for(int i = 0; i < mx_strlen(first_line); i++) {
        if(!mx_isdigit(first_line[i])){
            t_val_res r;
            r.err_code = ERR_INV_FIRST_LINE;
            mx_exit_with_err(&r);
        }
    }
    int num = mx_atoi(first_line);
    mx_strdel(&first_line);
    return num;
}

//return true if sum of all bridges len is greater that max int
static inline bool process_lines(char** lines, char** islands) {
    
    int index = 0;
    char* island1 = NULL;
    char* island2 = NULL;
    char* bridge_len_s = NULL;
    unsigned long sum = 0;
   
    for(int i = 0; lines[i] != NULL; i++){
        int delim_index = mx_get_char_index(lines[i], '-');
        int coma_index = mx_get_char_index(lines[i], ',');
        island1 = mx_strndup(lines[i], delim_index);
        island2 = mx_strndup(lines[i] + delim_index + 1, coma_index - delim_index - 1);
        islands[index++] = mx_strdup(island1);
        islands[index++] = mx_strdup(island2);
        bridge_len_s = mx_strndup(lines[i] + coma_index + 1, mx_get_char_index(lines[i], '\n'));
        mx_check_line(i + 2, island1, island2, bridge_len_s);
        sum += mx_atoi(bridge_len_s);
        mx_strdel(&island1);
        mx_strdel(&island2);
        mx_strdel(&bridge_len_s);

        if(sum > INT_MAX)
            return true;
    }
    return false;
}

void mx_process_data(char ** argv){
     bool len_overflow; 
     int islands_exp;   
     check_if_file_exist(argv[1]);
     
     char* file_src = mx_file_to_str(argv[1]);
     check_if_empty(file_src, argv[1]);
     islands_exp = check_first_line(file_src);

     char** lines = mx_strsplit(file_src + mx_get_char_index(file_src, '\n') + 1, '\n');
     int line_count = mx_get_n_of_lines(lines);
     char** islands = (char**) malloc(sizeof(char**) * line_count * 2 + 1); 
     islands[sizeof(char**) * line_count * 2] = NULL;

     len_overflow = process_lines(lines, islands);
     islands = mx_prepare_islands_arr(islands, islands_exp); 

     t_imatrix* mat = mx_create_matrix(islands_exp, lines ,islands);
     mx_throw_sum_err_if(len_overflow);
 
     t_imatrix* res_mat = mx_create_empty_matrix(mat->dim);
     mx_calculate_paths(islands, mat, res_mat);

     mx_print_result(mat, res_mat, islands);
     mx_del_strarr(&islands);
     mx_del_matrix(mat);
     mx_del_matrix(res_mat);
}

