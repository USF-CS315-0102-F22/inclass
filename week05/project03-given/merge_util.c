#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_util.h"

#define STR_LEN 4096

// gen_array_string makes a string representation of the integer array
void gen_array_string(int array[], int len, char *outstr) {
    outstr[0] = '\0';
    char numstr[33];
    for (int i = 0; i < len; i++) {
        snprintf(numstr, 33, " %d", array[i]);
        strncat(outstr, numstr, len);
    }
}

// args_get_array converts a sequence of numbers from their string 
// representation to an array of integers
void args_get_array(char **argv, int a[], int *n) {
    int i;
    
    *n = atoi(argv[1]);
    for (i = 0; i < *n; i++) {
        a[i] = atoi(argv[2 + i]);
    }
}
