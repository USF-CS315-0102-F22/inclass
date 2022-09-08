#include <stdio.h>
#include <stdlib.h>

int add4_c(int a, int b, int c, int d);
int add4_s(int a, int b, int c, int d);

void fatal(char *s) {
    printf("%s\n", s);
    exit(-1);
}

int main(int argc, char **argv) {
    if (argc != 5)
        fatal("usage: add4 a b c d");

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    int d = atoi(argv[4]);

    int c_result = add4_c(a, b, c, d);
    printf("C: %d\n", c_result);

    int s_result = add4_s(a, b, c, d);
    printf("Asm: %d\n", s_result);

    return 0;
}
