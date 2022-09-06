#include <stdio.h>

int sumarr_ptr_c(int *arr, int len);
int sumarr_index_c(int *arr, int len);

int sumarr_ptr_s(int *arr, int len);
int sumarr_index_s(int *arr, int len);


int main(int argc, char *argv[]) {
    int arr1[5] = {1, 2, 3, 4, 5};
    int r;

    r = sumarr_ptr_c(arr1, 5);
    printf("sumarr_ptr_c(arr1, 5) = %d\n", r);

    r = sumarr_ptr_s(arr1, 5);
    printf("sumarr_ptr_s(arr1, 5) = %d\n", r);

    r = sumarr_index_c(arr1, 5);
    printf("sumarr_index_c(arr1, 5) = %d\n", r);

    r = sumarr_index_s(arr1, 5);
    printf("sumarr_index_s(arr1, 5) = %d\n", r);

    return 0;
}
