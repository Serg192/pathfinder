#include "../inc/pathfinder.h"

static inline void arrs_prepare(t_alg_data* data) {
    for(int i = 0; i < data->mat->dim; i++) {
        data->added[i] = false;
        data->distances[i] = INT_MAX;
        data->parents[i] = -1;
    }
}


static inline void dijkstra(int s_vertex, t_alg_data* data) {

   arrs_prepare(data);
   data->distances[s_vertex] = 0;
   
   for(int i = 1; i < data->mat->dim; i++) {
       int nearest = -1;
       int shortest = INT_MAX;
       for(int index = 0; index < data->mat->dim; index++) {
           if(!data->added[index] && data->distances[index] < shortest) {
               nearest = index;
               shortest = data->distances[index];
           }
       }
       data->added[nearest] = true;
       for(int index = 0; index < data->mat->dim; index++) {
           int edge_dis = data->mat->elements[nearest][index];
           if(edge_dis > 0 && ((shortest + edge_dis) < data->distances[index])) {
               data->parents[index] = nearest;
               data->distances[index] = shortest + edge_dis;
           } 
        }
   }
}


void mx_calculate_paths(char** islands, t_imatrix* mat, t_imatrix* res_mat) {
    int distances[mat->dim];
    int parents[mat->dim];
    bool added[mat->dim];

    t_alg_data data;
    data.distances = distances;
    data.parents = parents;
    data.added = added;
    //data.paths = result_arr;
    data.islands = islands;
    data.mat = mat;
    
    int index = 0;
    for(int vertex = 0; vertex < mat->dim; vertex++) {
        dijkstra(vertex, &data);
        //write_path(vertex, &data);
        for(int i = 0; i < mat->dim; i++){
            res_mat->elements[index][i] = distances[i];
        }
        index++;
    }
 }

