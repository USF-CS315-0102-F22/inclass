#include <stdio.h>
#include <stdlib.h>

int find_max_index_c(int *arr, int len);

int main(int argc, char **argv) {
    const int ARR_MAX = 32;
    int arr[ARR_MAX];

    if (argc == 1) {
        printf("usage: find_max_index number ...\n");
        exit(-1);
    }

    for (int i = 0; i < argc - 1; i++) {
        arr[i] = atoi(argv[i + 1]);
    }
    int len = argc - 1;

    int c_result = find_max_index_c(arr, len);
    printf("C: %d\n", c_result);

    /* TODO
    int s_result = find_max_index_s(arr, len);
    printf("Asm: %d\n", s_result);
    */

    return 0;
}
