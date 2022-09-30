#include <stdint.h>
#include <stdio.h>

int main(int argc, char **argv) {

    uint32_t addi_pos = 0x02930293;
    uint32_t addi_neg = 0xfd730293;

    int64_t imm;

    imm = (addi_pos >> 20);
    printf("addi_pos >> 20 = %d\n", imm);
    imm = (imm << 52) >> 52;
    printf("addi_pos (0x%08x) imm = %d\n", addi_pos, imm);
    printf("\n");

    imm = addi_pos;
    imm = (imm << 32) >> 52;
    printf("addi_pos (0x%08x) imm = %d\n", addi_pos, imm);
    printf("\n");

    imm = (addi_neg >> 20);
    printf("addi_neg >> 20 = %d\n", imm);
    imm = (imm << 52) >> 52;
    printf("addi_neg (0x%08x) imm = %d\n", addi_neg, imm);
    printf("\n");

    imm = addi_neg;
    imm = (imm << 32) >> 52;
    printf("addi_neg (0x%08x) imm = %d\n", addi_neg, imm);

    return 0;
}
