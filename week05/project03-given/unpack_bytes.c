#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void unpack_bytes_c(int val, uint32_t bytes[]);
void unpack_bytes_s(int val, uint32_t bytes[]);

int main(int argc, char **argv) {
    uint32_t bytes[4];
    
    if (argc != 2) {
        printf("usage: unpack_bytes <int>\n");
        exit(-1);
    }
    
    int val = atoi(argv[1]);

    for (int i = 0; i < 4; i++) {
        bytes[i] = 0;
    }

    unpack_bytes_c(val, bytes);
    printf("C: %u %u %u %u\n", bytes[3], bytes[2], bytes[1], bytes[0]);

    for (int i = 0; i < 4; i++) {
        bytes[i] = 0;
    }

    unpack_bytes_s(val, bytes);
    printf("Asm: %u %u %u %u\n", bytes[3], bytes[2], bytes[1], bytes[0]);

    return 0;
}
