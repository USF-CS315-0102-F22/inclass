#include <stdio.h>

int strlen_ptr_c(char *str);
int strlen_index_c(char *str);
int strlen_ptr_s(char *str);
int strlen_index_s(char *str);

int main(int argc, char *argv[]) {
    char str1[128] = "Hello World!\n";
    int r;

    r = strlen_ptr_c(str1);
    printf("strlen_ptr_c(str1) = %d\n", r);
    r = strlen_ptr_s(str1);
    printf("strlen_ptr_s(str1) = %d\n", r);

    r = strlen_index_c(str1);
    printf("strlen_index_c(str1) = %d\n", r);
    r = strlen_index_s(str1);
    printf("strlen_index_s(str1) = %d\n", r);

    return 0;
}
