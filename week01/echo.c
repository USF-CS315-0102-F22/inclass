#include <stdio.h>
#include <stdlib.h>

void print_usage(void) {
    printf("usage: echo <string>\n");
}

int main(int argc, char **argv) {

    if (argc != 2) {
        print_usage();
        exit(-1);
    } 
    
    printf("%s\n", argv[1]);

    return 0;
}
