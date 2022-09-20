#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t pack_bytes_c(uint32_t b0, uint32_t b1, uint32_t b2, uint32_t b3);
int32_t pack_bytes_s(uint32_t b0, uint32_t b1, uint32_t b2, uint32_t b3);


int main(int argc, char **argv) {
    if (argc != 5) {
        printf("usage: pack_bytes <b3> <b2> <b1> <b0>\n");
        exit(-1);
    }
    
    int b3 = atoi(argv[1]);
    int b2 = atoi(argv[2]);
    int b1 = atoi(argv[3]);
    int b0 = atoi(argv[4]);

    int32_t c_result = 0;
    c_result = pack_bytes_c(b3, b2, b1, b0);
    printf("C: %d\n", c_result);

    
    int32_t s_result = 0;
    s_result = pack_bytes_s(b3, b2, b1, b0);
    printf("Asm: %d\n", s_result);

    return 0;
}
