#include <limits.h>
 
int find_max_index_c(int *arr, int len) {
    int max_index = 0;
    int max_val = INT_MIN;
    
    for (int i = 0; i < len; i++)
        if (arr[i] > max_val) {
            max_index = i;
            max_val = arr[i];
        }

    return max_index;
}
