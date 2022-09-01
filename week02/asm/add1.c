#include <stdio.h>
#include <stdlib.h>

int add1_c(int a);
int add1_s(int a);

int main(int argc, char **argv) {
    int r;
    int val = atoi(argv[1]);

    r = add1_c(val);
    printf("add1_c(%d) = %d\n", val, r);

    r = add1_s(val);
    printf("add1_s(%d) = %d\n", val, r);
    
    return 0;    
}
