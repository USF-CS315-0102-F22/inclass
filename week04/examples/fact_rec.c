#include <stdio.h>
#include <stdlib.h>

int fact_rec_c(int n);
int fact_rec_s(int n);

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: fact_rec n\n");
        exit(-1);
    }

    int n = atoi(argv[1]);

    int c_result = fact_rec_c(n);
    printf("C: %d\n", c_result);

    int s_result = fact_rec_s(n);
    printf("Asm: %d\n", s_result);

    return 0;
}
