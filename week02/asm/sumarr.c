#include <stdio.h>
#include <stdlib.h>

int sumarr_c(int a[], int len);
int sumarr_s(int a[], int len);

int main(int argc, char **argv) {
    int r;
    int a[] = {1, 2, 3, 4, 5};


    r = sumarr_c(a, 5);
    printf("sumarr_c({1,2,3,4,5}) = %d\n", r);

    r = sumarr_s(a, 5);
    printf("sumarr_s({1,2,3,4,5}) = %d\n", r);
    
    return 0;    
}
