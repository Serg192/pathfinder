#include "../inc/pathfinder.h"

int mx_get_n_of_lines(char** lines) {
    int res = 0;
    for(int i = 0; lines[i] != NULL; i++)
        res += 1;
    return res;
}


