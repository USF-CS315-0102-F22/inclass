#include <stdint.h>

#define RV_DEBUG 0
#define MAX_INSTRUCTION_COUNT 1000000

#define NREGS 32
#define STACK_SIZE 8192
#define RA 1
#define SP 2
#define A0 10
#define A1 11
#define A2 12
#define A3 13

// rv_state represents the state of the emulated RISC-V processor
struct rv_state {
    uint64_t regs[NREGS];
    uint64_t pc;
    uint8_t stack[STACK_SIZE];
};

// Initialize an rv_state struct with a function pointer and arguments
void rv_init(struct rv_state *rsp, uint32_t *fp,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
int rv_emulate(struct rv_state *rsp);
