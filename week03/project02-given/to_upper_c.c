#include <string.h>

void to_upper_c(char * str) {
    for (unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 'a' - 'A';
        }
    }
}
