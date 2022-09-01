#include <stdio.h>

void fill_str(char c, int len, char *str) {
    for (int i = 0; i < len; i++) {
        str[i] = c;
    }

    str[len] = '\0';
}

int main(int argc, char **argv) {
    char str[32];

    fill_str('a', 31, str);
    printf("str = %s\n", str);
    
    fill_str('Z', 31, str);
    printf("str = %s\n", str);

    return 0;
}
