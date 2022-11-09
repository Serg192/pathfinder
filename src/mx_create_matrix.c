#include "../inc/pathfinder.h"


static inline t_imatrix* mat_init(int dim) {
    t_imatrix* mat = (t_imatrix*)malloc(sizeof(t_imatrix));
    mat->elements = (int**)malloc(sizeof(int*) * dim);
    mat->dim = dim;

    for(int i = 0; i < dim; i++) {
        mat->elements[i] = (int*)malloc(sizeof(int) * dim);
        for(int j = 0; j < dim; j++)
            mat->elements[i][j] = -1;
           // mat->elements[i][j] = INT_MAX;
    }

    return mat;
}

static inline int insert_unique(t_imatrix* mat, char** names,  char* i1, char* i2, char* val) {
    int mat_i1 = mx_arr_get_index(names, i1);
    int mat_i2 = mx_arr_get_index(names, i2);
    int i_val = mx_atoi(val);

    if(mat->elements[mat_i1][mat_i2] == -1 && mat->elements[mat_i2][mat_i1] == -1) {
        mat->elements[mat_i1][mat_i2] = i_val;
        mat->elements[mat_i2][mat_i1] = i_val;
        return 0;
    } else
        return -1;
}

static inline void mat_fill(t_imatrix* mat, char** lines, char** names) {
    char* island1 = NULL;
    char* island2 = NULL;
    char* bridge_s = NULL;
    
    for(int i = 0; lines[i] != NULL; i++) {
       int delim = mx_get_char_index(lines[i], '-');
       int coma = mx_get_char_index(lines[i], ','); 
       island1 = mx_strndup(lines[i], delim);
       island2 = mx_strndup(lines[i] + delim + 1, coma - delim - 1);
       bridge_s = mx_strndup(lines[i] + coma + 1, mx_get_char_index(lines[i], '\n'));
    

       if(insert_unique(mat, names, island1, island2, bridge_s) == -1) {
           t_val_res r;
           r.err_code = ERR_HAS_DUPS;
           mx_exit_with_err(&r);
       }
    }
}

t_imatrix* mx_create_matrix(int dim, char** lines, char** names) {
    t_imatrix* mat = mat_init(dim);
    mat_fill(mat, lines, names); 
    return mat;
}

t_imatrix* mx_create_empty_matrix(int dim) {
    t_imatrix* mat = mat_init(dim);
    return mat;
}

