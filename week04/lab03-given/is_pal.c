#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool pal_rec_c(char*, int, int);

int main(int argc, char **argv) {
    char *str = argv[1];
    int end = strlen(str) - 1;

    bool c_result = pal_rec_c(str, 0, end);
    printf("C: %s\n", c_result ? "True": "False");

    /* TODO
    bool s_result = pal_rec_s(str, 0, end);
    printf("Asm: %s\n", s_result ? "True": "False");
    */

    return 0;
}
