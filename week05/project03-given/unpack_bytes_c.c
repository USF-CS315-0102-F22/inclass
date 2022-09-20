#include <stdint.h>

int32_t unpack_bytes_c(int val, uint32_t bytes[]) {
    /* Unpack the bytes of a 32 bit int into individual bytes in an array. */
    uint32_t b;


    for (int i = 0; i < 4; i++) {
        b = val & 0xFF;
        bytes[i] = b;
        val = val >> 8;
    }
}
