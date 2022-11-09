#include "../inc/pathfinder.h"

static inline void print_boundary(void){
    for(int i = 0; i < 40; i++)
        mx_printchar('=');
    mx_printchar('\n');
}

static inline void print_path(const char* from, const char* to) {
    mx_printstr("Path: ");
    mx_printstr(from);
    mx_printstr(" -> ");
    mx_printstr(to);
    mx_printstr("\n");
}

static inline void print(t_imatrix* start, t_imatrix* result, int* path, int count, char** islands){
    for(int i = 0; i < result->dim; i++){
        if(i != path[count] && start->elements[path[count]][i] ==
           result->elements[path[count]][path[0]] - result->elements[i][path[0]]) {
            path[count + 1] = i;
            print(start, result, path, count + 1, islands);
        }
    }
    if(path[count] != path[0])
        return;

    print_boundary();
    print_path(islands[path[1]], islands[path[0]]);
    mx_print_route(islands, path, count);
    mx_print_dist(path, start->elements, count);
    mx_printstr("\n");
    print_boundary();
}

static inline void prepare_mat(t_imatrix* mat){
    for(int i = 0; i < mat->dim; i++)
        for(int j = 0; j < mat->dim; j++)
            if(mat->elements[i][j] == -1)
                mat->elements[i][j] = INT_MAX;
}


void mx_print_result(t_imatrix* start, t_imatrix* result, char** islands) {
 
   int path[result->dim + 1];
   prepare_mat(start);

   for(int i = 0; i < result->dim; i++) {
       for(int j = i + 1; j < result->dim; j++){
           path[0] = j;
           path[1] = i;
           print(start, result, path, 1, islands);
       }
   } 
}

