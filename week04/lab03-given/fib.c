#include <stdio.h>
#include <stdlib.h>

int fib_rec_c(int);

int main(int argc, char **argv) {
    int n = atoi(argv[1]);

    int c_result = fib_rec_c(n);
    printf("C: %d\n", c_result);

    /* TODO
    int s_result = fib_rec_s(n);
    printf("Asm: %d\n", s_result);
    */
    
    return 0;
}
