#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv) {
    printf("sizeof(char) = %d\n", sizeof(char));
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(long long) = %d\n", sizeof(long long));
    printf("sizeof(char *) = %d\n", sizeof(char *));
    printf("sizeof(int *) = %d\n", sizeof(int *));
    printf("sizeof(float *) = %d\n", sizeof(float *));

    printf("sizeof(uint8_t) = %d\n", sizeof(uint8_t));
    printf("sizeof(uint32_t) = %d\n", sizeof(uint32_t));
    printf("sizeof(uint64_t) = %d\n", sizeof(uint64_t));

    return 0;
}
