#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "rv_emu.h"

void unsupported(char *s, uint32_t val) {
    printf("%s: %d\n", s, val);
    exit(-1);
}

void rv_init(struct rv_state *rsp, uint32_t *func,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3) {
    int i;

    // Zero out registers
    for (i = 0; i < NREGS; i += 1) {
        rsp->regs[i] = 0;
    }

    // Zero out the stack
    for (i = 0; i < STACK_SIZE; i += 1) {
        rsp->stack[i] = 0;
    }

    // Initialize the Program Counter
    rsp->pc = (uint64_t) func;

    // Initialize the Link Register to a sentinel value
    rsp->regs[RA] = 0;

    // Initialize Stack Pointer to the logical bottom of the stack
    rsp->regs[SP] = (uint64_t) &rsp->stack[STACK_SIZE];

    // Initialize the first 4 arguments in emulated r0-r3
    rsp->regs[A0] = a0;
    rsp->regs[A1] = a1;
    rsp->regs[A2] = a2;
    rsp->regs[A3] = a3;
}

void emu_r_type(struct rv_state *rsp, uint32_t iw) {
    uint32_t rd = (iw >> 7) & 0b11111;
    uint32_t rs1 = (iw >> 15) & 0b11111;
    uint32_t rs2 = (iw >> 20) & 0b11111;
    uint32_t funct3 = (iw >> 12) & 0b111;
    uint32_t funct7 = (iw >> 25) & 0b1111111;    

    if (funct3 == 0b000 && funct7 == 0b0000000) {
        // ADD
        rsp->regs[rd] = rsp->regs[rs1] + rsp->regs[rs2];

    } else if (funct3 == 0b000 && funct7 == 0b0100000) {
        // SUB
        rsp->regs[rd] = rsp->regs[rs1] - rsp->regs[rs2];
        
    } else if (funct3 == 0b000 && funct7 == 0b0000001) {
        // MUL
        rsp->regs[rd] = rsp->regs[rs1] * rsp->regs[rs2];

    } else if (funct3 == 0b111 && funct7 == 0b0000000) {
        // AND
        rsp->regs[rd] = rsp->regs[rs1] & rsp->regs[rs2];

    } else if (funct3 == 0b001 && funct7 == 0b0000000) {
        // SLL
        rsp->regs[rd] = rsp->regs[rs1] << rsp->regs[rs2];

    } else if (funct3 == 0b101 && funct7 == 0b0000000) {
        // SRL
        rsp->regs[rd] = rsp->regs[rs1] >> rsp->regs[rs2];

    } else {
        unsupported("R-type funct3", funct3);
    }
    rsp->pc += 4; // Next instruction
}

void emu_i_type(struct rv_state *rsp, uint32_t iw) {
    uint32_t rd = (iw >> 7) & 0b11111;
    uint32_t rs1 = (iw >> 15) & 0b11111;
    uint32_t shamt = (iw >> 20) & 0b111111;
    uint32_t funct3 = (iw >> 12) & 0b111;
    uint32_t funct6 = (iw >> 26) & 0b111111;    
    int64_t imm_11_0 = (iw >> 20) & 0xFFF;    
    int64_t imm = (imm_11_0 << (20 + 32)) >> (20 + 32);

    if (funct3 == 0b000) {
        // ADD
        rsp->regs[rd] = rsp->regs[rs1] + imm;
    } else if (funct3 == 0b101 && funct6 == 0b000000) {
        // SRLI
        rsp->regs[rd] = rsp->regs[rs1] >> shamt;

    } else {
        unsupported("R-type funct3", funct3);
    }
    rsp->pc += 4; // Next instruction
}

void emu_b_type(struct rv_state *rsp, uint32_t iw) {
    uint32_t rs1 = (iw >> 15) & 0b11111;
    uint32_t rs2 = (iw >> 20) & 0b11111;
    uint32_t funct3 = (iw >> 12) & 0b111;
    int64_t imm_12 = (iw >> 31) & 0b1;
    int64_t imm_10_5 = (iw >> 25) & 0b111111;
    int64_t imm_4_1 = (iw >> 8) & 0b1111;
    int64_t imm_11 = (iw >> 7) & 0b1;

    int64_t imm = (imm_12 << 12) | (imm_11 << 11)
                | (imm_10_5 << 5) | (imm_4_1 << 1);

    imm = (imm << (19 + 32)) >> (19 + 32);

    bool take_branch = false;
    
    if (funct3 == 0b100) {
        // BLT
        if ((int64_t) rsp->regs[rs1] < (int64_t) rsp->regs[rs2]) {
            take_branch = true;
        }
    } else if (funct3 == 0b001) {
        // BLT
        if ((int64_t) rsp->regs[rs1] != (int64_t) rsp->regs[rs2]) {
            take_branch = true;
        }
    } else {
        unsupported("B-type funct3", funct3);
    }

    if (take_branch) {
        rsp->pc += imm;
    } else {
        rsp->pc += 4; // Next instruction
    }
}

void emu_j_type(struct rv_state *rsp, uint32_t iw) {
    uint32_t rd = (iw >> 7) & 0b11111;
    uint64_t imm_20 = (iw >> 31) & 0b1;
    uint64_t imm_10_1 = (iw >> 21) & 0x3FF;
    uint64_t imm_11 = (iw >> 20) & 0b1;
    uint64_t imm_19_12 = (iw >> 12) & 0xFF;

    int64_t imm = (imm_20 << 20) | (imm_19_12 << 12) | (imm_11 << 11) | (imm_10_1 << 1);
    imm = (imm <<  43) >> 43;

    // JAL support
    if (rd != 0) {
        rsp->regs[rd] = rsp->pc + 4;
    }

    rsp->pc = rsp->pc + imm;
}

void emu_jalr(struct rv_state *rsp, uint32_t iw) {
    // RET
    uint32_t rs1 = (iw >> 15) & 0b1111;  // Will be ra (aka x1)
    uint64_t val = rsp->regs[rs1];  // Value of regs[1]

    rsp->pc = val;  // PC = return address
}

void rv_one(struct rv_state *rsp) {

    // Get an instruction word from the current Program Counter    
    uint32_t iw = *(uint32_t*) rsp->pc;

    /* could also think of that ^^^ as:
        uint32_t *pc = (uint32_t*) rsp->pc;
        uint32_t iw = *pc;
    */

    uint32_t opcode = iw & 0b1111111;
    switch (opcode) {
        case 0b0110011:
            // R-type instructions have two register operands
            emu_r_type(rsp, iw);
            break;
        case 0b0010011:
            // I-type instructions have one immediate operand
            emu_i_type(rsp, iw);
            break;
        case 0b1100011:
            // B-type instructions
            emu_b_type(rsp, iw);
            break;
        case 0b1101111:
            // JAL
            emu_j_type(rsp, iw);
            break;    
        case 0b1100111:
            // JALR (aka RET) is a variant of I-type instructions
            emu_jalr(rsp, iw);
            break;
        default:
            unsupported("Unknown opcode: ", opcode);
            
    }
}

int rv_emulate(struct rv_state *rsp) {
    while (rsp->pc != 0) {
        rv_one(rsp);
    }
    
    return (int) rsp->regs[A0];
}
