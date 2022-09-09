#include <stdio.h>
#include <string.h>

int find_char_index_c(char c, char *str, int start, int len);
int count_char_c(char c, char *str, int len);

int find_char_index_s(char c, char *str, int start, int len);
int count_char_s(char c, char *str, int len);


int main(int argc, char *argv[]) {
    char test_str[128] = "My dog ate my homework";
    int len;
    int idx;
    int count;

    len = strlen(test_str);

    idx = find_char_index_c('o', test_str, 0, len);
    printf("find_char_index_c('o', \"%s\", 0, %d) = %d\n", test_str, len, idx);

    idx = find_char_index_s('o', test_str, 0, len);
    printf("find_char_index_s('o', \"%s\", 0, %d) = %d\n", test_str, len, idx);

 
    count = count_char_c('o', test_str, len);
    printf("count_char_c('o', \"%s\", %d) = %d\n", test_str, len, count);

    count = count_char_s('o', test_str, len);
    printf("count_char_s('o', \"%s\", %d) = %d\n", test_str, len, count);
  
    return 0;
}
