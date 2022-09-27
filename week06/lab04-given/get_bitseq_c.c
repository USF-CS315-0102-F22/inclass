#include <stdint.h>

uint32_t get_bitseq_c(uint32_t num, int start, int end) {
    uint32_t val;
    int len;
    uint32_t mask;

    len = end - start;
    val = num >> start;
    mask = ((uint32_t)(((int32_t)(0b1 << 31)) >> len)) >> (31 - len);
    val = val & mask;

    return val;
}
