#include <stdio.h>
#include <stdlib.h>

int ifelse_c(int val);
int ifelse_s(int val);

int main(int argc, char **argv) {
    int r;
    int val = atoi(argv[1]);

    r = ifelse_c(val);
    printf("ifelse_c(%d) = %d\n", val, r);

    r = ifelse_s(val);
    printf("ifelse_s(%d) = %d\n", val, r);
    
    return 0;    
}
