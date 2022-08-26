#include <stdio.h>
#include <stdlib.h>

void print_usage(void) {
    printf("usage: echo <string>\n");
}

int main(int argc, char **argv) {
    int count;
    
    if (argc != 3) {
        print_usage();
        exit(-1);
    } 

    count = atoi(argv[1]);

    for (int i = 0; i < count; i++) {    
        printf("%s\n", argv[2]);
    }

    return 0;
}
