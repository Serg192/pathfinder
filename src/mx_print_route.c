#include "../inc/pathfinder.h"

void mx_print_route(char** islands, int* path, int n) {
    mx_printstr("Route: ");
    for(int i = 1; i < n + 1; i++) {
        mx_printstr(islands[path[i]]);
        if(i != n)
            mx_printstr(" -> ");
    }
}

