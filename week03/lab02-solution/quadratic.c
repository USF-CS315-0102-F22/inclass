#include <stdio.h>
#include <stdlib.h>

int quadratic_c(int x, int a, int b, int c);
int quadratic_s(int x, int a, int b, int c);

void fatal(char *s) {
    printf("%s\n", s);
    exit(-1);
}

int main(int argc, char **argv) {
    if (argc != 5)
        fatal("usage: quadratic x a b c");

    int x = atoi(argv[1]);
    int a = atoi(argv[2]);
    int b = atoi(argv[3]);
    int c = atoi(argv[4]);

    int c_result = quadratic_c(x, a, b, c);
    printf("C: %d\n", c_result);

    int s_result = quadratic_s(x, a, b, c);
    printf("Asm: %d\n", s_result);

    return 0;
}
