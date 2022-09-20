#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "merge_util.h"

void merge_sort_c(int a[], int aux[], int start, int end);
void merge_sort_s(int a[], int aux[], int start, int end);

// merge_sort_test calls the C and Asm versions of the full merge sort
void merge_sort_test(int array[], int len) {
    int i;
    char arrstr1[4096];
    char arrstr2[4096];
    int acopy[4096];
    int aux[4096];
    for (i = 0; i < len; i++) {
        acopy[i] = array[i];
    }   
    gen_array_string(acopy, len, arrstr1);
    merge_sort_c(acopy, aux, 0, len - 1);
    gen_array_string(acopy, len, arrstr2);
    printf("C:%s\n", arrstr2);

    // Re-initialize the array to unsorted values since it was sorted in place
    for (i = 0; i < len; i++) {
        acopy[i] = array[i];
    }
    gen_array_string(acopy, len, arrstr1);
    merge_sort_s(acopy, aux, 0, len - 1);
    gen_array_string(acopy, len, arrstr2);
    printf("Asm:%s\n", arrstr2);
}


int main(int argc, char **argv) {
    int n;
    int a[4096];

    if (argc == 1) {
        printf("usage: merge_sort [<arg1> ...]\n");
        exit(-1);
    }

    args_get_array(argv, a, &n);
    merge_sort_test(a, n);

    return 0;
}
