#include <stdio.h>
#include <string.h>

int countc_rec_c(char c, char *str);
int countc_rec_s(char c, char *str);


int main(int argc, char *argv[]) {
    char test_str[128] = "My dog ate my homework";
    int len;
    int count;

    len = strlen(test_str);

    count = countc_rec_c('o', test_str);
    printf("countc_rec_c('o', \"%s\") = %d\n", test_str, count );

    count = countc_rec_s('o', test_str);
    printf("countc_rec_s('o', \"%s\") = %d\n", test_str, count);

    return 0;
}
