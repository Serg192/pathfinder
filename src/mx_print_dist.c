#include "../inc/pathfinder.h"

void mx_print_dist(int *path, int** start_mat_el, int n) {
    int dis = 0;
    mx_printstr("\nDistance: ");

    for(int i = 1; i < n; i++) {
        int temp = start_mat_el[path[i]][path[i + 1]];
        dis += temp;
        mx_printint(temp);
        if(i != n - 1) 
            mx_printstr(" + ");    
    }

    if(n != 2) {
        mx_printstr(" = ");
        mx_printint(dis);
    }
}

