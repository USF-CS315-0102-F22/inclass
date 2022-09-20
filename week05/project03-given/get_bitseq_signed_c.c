#include <stdint.h>

uint32_t get_bitseq_c(uint32_t num, int start, int end);

int get_bitseq_signed_c(int32_t num, int start, int end) {
    uint32_t val;
    int val_signed;
    int len = (end - start) + 1;
    int shift_amt = 32 - len;

    val = get_bitseq_c(num, start, end);

    val = val << shift_amt;
    val_signed = ((int) val) >> shift_amt;

    return val_signed;
    
}
    
