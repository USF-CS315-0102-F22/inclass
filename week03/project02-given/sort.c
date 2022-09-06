#include <stdio.h>
#include <stdlib.h>

int sort_c(int *arr, int len);

int init_array(int argc, char **argv, int *arr) {
    int i;
    for (i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }
    return i - 1;
}

void print_array(char *prefix, int *arr, int len) {
    printf("%s", prefix);
    for (int i = 0; i < len; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    const int MAX_ARGS = 33;
    int arr[MAX_ARGS];

    if (argc < 2 || argc > MAX_ARGS) {
        printf("usage: sort up to 32 integers\n");
        exit(-1);
    }

    int len = init_array(argc, argv, arr);
    sort_c(arr, len);
    print_array("C:", arr, len);
    
    /* TODO
    init_array(argc, argv, arr);
    sort_s(arr, len);
    print_array("Asm:", arr, len);
    */
    return 0;
}
