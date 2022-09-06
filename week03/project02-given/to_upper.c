#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void to_upper_c(char *buf);

int main(int argc, char **argv) {
    const int BUF_MAX = 33;
    char buf[BUF_MAX];

    if (argc != 2) {
        printf("usage: to_upper StrIng\n");
        exit(-1);
    }

    strncpy(buf, argv[1], BUF_MAX - 1);
    to_upper_c(buf);
    printf("C: %s\n", buf);

    /* TODO
    strncpy(buf, argv[1], BUF_MAX - 1);
    to_upper_s(buf);
    printf("Asm: %s\n", buf);
    */

    return 0;    
}
