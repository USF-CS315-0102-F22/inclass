#include <stdint.h>
#include <stdio.h>

uint32_t get_bit_c(uint32_t value, int n);
uint32_t get_bit_s(uint32_t value, int n);

uint32_t set_bit_c(uint32_t value, int n, uint32_t bvalue);
uint32_t set_bit_s(uint32_t value, int n, uint32_t bvalue);


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

    bvalue = get_bit_c(value, 4);
    printf("git_bit_c(0b11001011, 4) = %d\n", bvalue);

    rv = set_bit_c(value, 4, 1);
    printf("set_bit_c(0b11001011, 4, 1) = ");
    print_bin(rv);

    rv = set_bit_c(value, 3, 0);
    printf("set_bit_c(0b11001011, 3, 0) = ");
    print_bin(rv);

    return 0;
}
