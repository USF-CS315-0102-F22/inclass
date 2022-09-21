#include <stdbool.h>

int pal_rec_c(char *str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return pal_rec_c(str, start + 1, end - 1);
}
