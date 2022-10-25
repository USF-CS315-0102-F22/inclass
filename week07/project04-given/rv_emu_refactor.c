#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include "rv_emu.h"

#define DEBUG 0

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

    memset(&rsp->analysis, 0, sizeof(struct rv_analysis_st));
    cache_init(&rsp->i_cache);  
}

static void print_pct(char *fmt, int numer, int denom) {
    double pct = 0.0;

    if (denom) {
        pct = (double) numer / (double) denom * 100.0;
    }
    printf(fmt, numer, pct);
}

void rv_print(struct rv_analysis_st *a) {
    int b_total = a->b_taken + a->b_not_taken;

    printf("=== Analysis\n");
    print_pct("Instructions Executed  = %d\n", a->i_count, a->i_count);
    print_pct("R-type + I-type        = %d (%.2f%%)\n", a->ir_count, a->i_count);
    print_pct("Loads                  = %d (%.2f%%)\n", a->ld_count, a->i_count);
    print_pct("Stores                 = %d (%.2f%%)\n", a->st_count, a->i_count);
    print_pct("Jumps/JAL/JALR         = %d (%.2f%%)\n", a->j_count, a->i_count);
    print_pct("Conditional branches   = %d (%.2f%%)\n", b_total, a->i_count);
    print_pct("  Branches taken       = %d (%.2f%%)\n", a->b_taken, b_total);
    print_pct("  Branches not taken   = %d (%.2f%%)\n", a->b_not_taken, b_total);
}

struct rv_decode_st {
    uint32_t rd;
    uint32_t rs1;
    uint32_t rs2;
    uint32_t funct3;
    uint32_t funct6;
    uint32_t funct7;
    int64_t imm_i;
    int64_t imm_s;
    int64_t imm_b;    
    int64_t imm_u;
    int64_t imm_j
}


void emu_decode(uint32_t iw, struct rv_decode_st *rdp) {
    rdp->rd = (iw >> 7) & 0b11111;    
    rdp->rs1 = (iw >> 15) & 0b11111;
    ...
    // All immediate extraction
}


uint32_t emu_decode_rd(iw) {


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
    } else {
        unsupported("R-type funct3", funct3);
    }
    rsp->pc += 4; // Next instruction
}

void emu_jalr(struct rv_state *rsp, uint32_t iw) {
    // RET
    uint32_t rs1 = (iw >> 15) & 0b11111;  // Will be ra (aka x1)
    uint64_t val = rsp->regs[rs1];  // Value of regs[1]

    rsp->pc = val;  // PC = return address
}

void rv_one(struct rv_state *rsp) {

    uint32_t iw;
    struct rv_decode_st rv_decode;

    /* could also think of below as:
        uint32_t *pc = (uint32_t*) rsp->pc;
        uint32_t iw = *pc;
    */

    //iw = *(uint32_t*) rsp->pc;
    // Use below to add cache
    iw = cache_lookup(&rsp->i_cache, (uint64_t) rsp->pc);

    
    emu_decode(iw, &rv_decode);

    uint32_t opcode = iw & 0b1111111;
    switch (opcode) {
        case 0b0110011:
            // R-type instructions have two register operands
            emu_r_type(rsp, iw, &rv_decode);
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
