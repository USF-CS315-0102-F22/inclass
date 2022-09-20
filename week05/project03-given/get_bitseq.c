#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t get_bitseq_c(uint32_t num, int start, int end);
uint32_t get_bitseq_s(uint32_t num, int start, int end);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("usage: get_bitseq number start_bit end_bit\n");
        exit(-1);
    }
    
    int num = atoi(argv[1]);
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    uint32_t c_result = get_bitseq_c(num, start, end);
    printf("C: %u\n", c_result);

    uint32_t s_result = get_bitseq_s(num, start, end);
    printf("Asm: %u\n", s_result);
    
    return 0;
}
