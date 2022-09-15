#include <stdio.h>
#include <stdlib.h>

int sumarr_rec_c(int *, int, int);

int main(int argc, char **argv) {
    int arr[1024] = {0};
    int len = 0;

    for (len = 0; len < argc - 1; len++) {
        arr[len] = atoi(argv[len + 1]);
    }

    int c_result = sumarr_rec_c(arr, 0, len - 1);
    printf("C: %d\n", c_result);

    /* TODO
    int s_result = sumarr_rec_s(arr, 0, len - 1);
    printf("Asm: %d\n", s_result);
    */

    return 0;
}
