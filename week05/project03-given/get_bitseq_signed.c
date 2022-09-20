#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int get_bitseq_signed_c(uint32_t num, int start, int end);
int get_bitseq_signed_s(uint32_t num, int start, int end);

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("usage: get_bitseq_signed number start_bit end_bit\n");
        exit(-1);
    }
    
    int num = atoi(argv[1]);
    int start = atoi(argv[2]);
    int end = atoi(argv[3]);

    int c_result = get_bitseq_signed_c(num, start, end);
    printf("C: %d\n", c_result);

    int s_result = get_bitseq_signed_s(num, start, end);
    printf("Asm: %d\n", s_result);
    return 0;
}
