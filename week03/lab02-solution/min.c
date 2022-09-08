#include <stdio.h>
#include <stdlib.h>

int min_c(int a, int b);
int min_s(int a, int b);

int fatal(char *s) {
    printf("%s\n", s);
    exit(-1);
}

int main(int argc, char **argv) {
    if (argc != 3)
        fatal("usage: min a b");

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    int c_result = min_c(a, b);
    printf("C: %d\n", c_result);

    int s_result = min_s(a, b);
    printf("Asm: %d\n", s_result);

    return 0;
}
