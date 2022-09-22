#include <stdint.h>

uint32_t get_bit_c(uint32_t value, int n) {
    value = value >> n;
    value = value & 0b1;
    return value;
}

uint32_t set_bit_c(uint32_t value, int n, uint32_t bvalue) {
    if (bvalue == 1) {
        value = value | (0b1 << n);
    } else {
        value = value & (~(0b1 << n));
    }

    return value;
}
