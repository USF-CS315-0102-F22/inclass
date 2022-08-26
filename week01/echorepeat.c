#include <stdio.h>
#include <stdlib.h>

void print_usage(void) {
    printf("usage: echo [-r count] <string>\n");
}

int main(int argc, char **argv) {
    int count = 0;
    int i = 0;
    char *s;
    
    if (argc < 2) {
        print_usage();
        exit(-1);
    } 

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'r'
            && argv[i][2] == '\0') {
            count = atoi(argv[i + 1]);
            i += 2;
        } else {
            s = argv[i];
            i += 1;
        }
    }

    for (int i = 0; i < count; i++) {    
        printf("%s\n", s);
    }

    return 0;
}
