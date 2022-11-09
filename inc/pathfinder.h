#ifndef PATHFINDER_H
#define PATHFINDER_H

#include <libmx.h>
#include <limits.h>

enum e_err_type {
    ERR_INV_NUM_OF_ARGS,
    ERR_FILE_NOT_EXIST,
    ERR_FILE_IS_EMPTY,
    ERR_INV_FIRST_LINE,
    ERR_INV_LINE,
    ERR_INV_ISLANDS_NUM,
    ERR_HAS_DUPS,
    ERR_LEN_TOO_BIG,
    ERR_NONE
};

typedef struct s_val_res {
    const char *filename;
    int err_code;
    int line;
}              t_val_res;

typedef struct s_imatrix {
    int dim;
    int ** elements;
}              t_imatrix;

typedef struct s_alg_data {
    int* distances;
    int* parents;
    bool* added;
    char** islands;
    t_imatrix* mat;
}              t_alg_data;

void mx_check_line(int line_num, char* island1, char* island2, char* bridge_len);

void mx_throw_sum_err_if(bool b);

void mx_exit_with_err(t_val_res* val_res);

void mx_process_data(char **argv);

char** mx_prepare_islands_arr(char ** islands, int i_exp);

int mx_get_n_of_lines(char **lines);

t_imatrix* mx_create_matrix(int dim, char** lines, char** names);

t_imatrix* mx_create_empty_matrix(int dim);

void mx_del_matrix(t_imatrix* mat);

int mx_arr_get_index(char** arr, const char* element);

void mx_calculate_paths(char** islands, t_imatrix* mat, t_imatrix* res_mat);

void mx_print_result(t_imatrix* first, t_imatrix* result, char** islands);

void mx_print_route(char** islands, int* path, int n);

void mx_print_dist(int* path, int** start_mat_el, int n);
#endif

