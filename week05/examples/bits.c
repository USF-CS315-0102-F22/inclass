#include <stdint.h>
#include <stdio.h>

uint32_t get_bit_c(uint32_t value, int n);
uint32_t get_bit_s(uint32_t value, int n);

uint32_t set_bit_c(uint32_t value, int n, uint32_t bvalue);
uint32_t set_bit_s(uint32_t value, int n, uint32_t bvalue);

uint32_t get_bitseq_c(uint32_t value, int start, int end);
uint32_t get_bitseq_s(uint32_t value, int start, int end);


void print_bin(uint32_t value) {
    int i;
    uint32_t bvalue;

    printf("0b");
    for (i = 31; i >= 0; i--) {
        bvalue = (value >> i) & 0b1;
        printf("%c", '0' + bvalue);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    uint32_t value, rv;
    uint32_t bvalue;

    value = 0b11001011;

    bvalue = get_bit_c(value, 3);
    printf("git_bit_c(0b11001011, 3) = %d\n", bvalue);

    bvalue = get_bit_s(value, 3);
    printf("git_bit_s(0b11001011, 3) = %d\n", bvalue);

    bvalue = get_bit_c(value, 4);
    printf("git_bit_c(0b11001011, 4) = %d\n", bvalue);

    bvalue = get_bit_s(value, 4);
    printf("git_bit_s(0b11001011, 4) = %d\n", bvalue);

    rv = set_bit_c(value, 4, 1);
    printf("set_bit_c(0b11001011, 4, 1) = ");
    print_bin(rv);

    rv = set_bit_s(value, 4, 1);
    printf("set_bit_s(0b11001011, 4, 1) = ");
    print_bin(rv);

    rv = set_bit_c(value, 3, 0);
    printf("set_bit_c(0b11001011, 3, 0) = ");
    print_bin(rv);

    rv = set_bit_s(value, 3, 0);
    printf("set_bit_s(0b11001011, 3, 0) = ");
    print_bin(rv);

    rv = get_bitseq_c(value, 4, 6);
    printf("get_bitseq_c(0b11001011, 4, 6) = ");
    print_bin(rv);

    rv = get_bitseq_s(value, 4, 6);
    printf("get_bitseq_s(0b11001011, 4, 6) = ");
    print_bin(rv);

    value = 0b11110000111100001111000011110000;
    rv = get_bitseq_c(value, 0, 31);
    printf("get_bitseq_c(0b11110000111100001111000011110000, 0, 31) = ");
    print_bin(rv);

    value = 0b11110000111100001111000011110000;
    rv = get_bitseq_s(value, 0, 31);
    printf("get_bitseq_s(0b11110000111100001111000011110000, 0, 31) = ");
    print_bin(rv);

    int x = -1;
    printf("%d = ", x);
    print_bin(x);

    x = -2;
    printf("%d = ", x);
    print_bin(x);

    x = -3;
    printf("%d = ", x);
    print_bin(x);

    int y = 12;
    printf("y << 1 = %d\n", y << 1);
    printf("y << 2 = %d\n", y << 2);

    printf("y >> 1 = %d\n", y >> 1);
    printf("y >> 2 = %d\n", y >> 2);

    uint32_t z = 0xAABB2211;
    printf("z = %X\n", z);

    printf("*((uint8_t *) &z) = %X\n", *((uint8_t *) &z));  

    return 0;
}
