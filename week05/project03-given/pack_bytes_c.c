#include <stdint.h>

int32_t pack_bytes_c(uint32_t b3, uint32_t b2, uint32_t b1, uint32_t b0) {
    /* Pack 4 bytes into one 32 bit word. Assume b0 is least significant byte */
    int32_t val = 0;

    val = b3;
    val = (val << 8) | b2;
    val = (val << 8) | b1;
    val = (val << 8) | b0;

    return val;
}
