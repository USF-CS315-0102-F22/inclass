#include <stdint.h>
#include <stdio.h>

uint32_t get_bit_c(uint32_t value, int i) {
    value = value >> i;
    value = value & 0b1;
    return value;
}

uint32_t set_bit_c(uint32_t value, int i, uint32_t bvalue) {
    if (bvalue == 1) {
        value = value | (0b1 << i);
    } else {
        value = value & (~(0b1 << i));
    }
    return value;
}

uint32_t get_bitseq1_c(uint32_t value, int start, int end) {
    uint32_t mask;
    int len = (end - start) + 1;
    
    if (len < 32) {
        mask = (0b1 << len) - 1;
        value = (value >> start) & mask;
    }
    
    return value;
}

uint32_t get_bitseq_c(uint32_t value, int start, int end) {

    value = value << (31 - end);
    value = value >> ((31 - end) + start);

    return value;
}
