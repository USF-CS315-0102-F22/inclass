#include <stdint.h>
#include <stdio.h>

int add2_s(int a0, int a1);

int main(int argc, char **argv) {
    int r;

    r = add2_s(1, 2);
    printf("add2_s(1, 2) = %d\n", r);

    uint32_t iw;
    uint32_t *pc;

    pc = (uint32_t *) add2_s;
    iw = *pc;

    printf("iw = %x\n", iw);

    uint32_t opcode;
    uint32_t rd;
    uint32_t funct3;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct7;

    opcode = iw & 0b1111111;
    rd = (iw >> 7) & 0b11111;
    funct3 = (iw >> 12) & 0b111;
    rs1 = (iw >> 15) & 0b11111;
    rs2 = (iw >> 20) & 0b11111;
    funct7 = (iw >> 25) & 0b1111111;

    printf("opcode = %d\n", opcode);
    printf("rd = %d\n", rd);
    printf("funct3 = %d\n", funct3);
    printf("rs1 = %d\n", rs1);
    printf("rs2 = %d\n", rs2);
    printf("funct7 = %d\n", funct7);

    return 0;    
}
