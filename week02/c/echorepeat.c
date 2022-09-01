#include <stdio.h>
#include <stdlib.h>

void print_usage(void) {
    printf("usage: echo [-r count] <string>\n");
}

void parse_args(int argc, char **argv, int *count, char **str_p) {
    int i = 1;
    int mycount = 0;
    char *s;

    while (i < argc) {
        if (argv[i][0] == '-' && argv[i][1] == 'r'
            && argv[i][2] == '\0') {
            mycount = atoi(argv[i + 1]);
            i += 2;
        } else {
            s = argv[i];
            i += 1;
        }
    }

    *count = mycount;
    *str_p = s; 
}

void echo_print(int count, char *str) {
    for (int i = 0; i < count; i++) {    
        printf("%s\n", str);
    }
}

int main(int argc, char *argv[]) {
    int count;
    char *str;

    parse_args(argc, argv, &count, &str);
    echo_print(count, str);

    return 0;
}    
