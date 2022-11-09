#include "../inc/pathfinder.h"

int mx_arr_get_index(char** arr, const char* element) {
    int index = -1;
    
    for(int i = 0; arr[i] != NULL; i++) {
        if(mx_strcmp(arr[i], element) == 0){
            index = i;
            break;
        }
    }
    return index;
}

