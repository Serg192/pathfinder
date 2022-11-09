#include "../inc/pathfinder.h"

void mx_del_matrix(t_imatrix* mat) {
    for(int i = 0; i < mat->dim; i++){
        free(mat->elements[i]);
    }
    free(mat->elements);
    free(mat);
}

