// RISC-V emulator types and constants

#include <stdint.h>
#include <stdbool.h>

// ABI register mappings
#define RV_ZERO      0
#define RV_RA        1
#define RV_SP        2
#define RV_A0       10
#define RV_A1       11
#define RV_A2       12
#define RV_A3       13
#define RV_NUM_REGS 32

// Opcodes for instr formats
typedef enum {
    FMT_R       = 0b0110011,
    FMT_I_LOAD  = 0b0000011,
    FMT_I_JALR  = 0b1100111,
    FMT_I_ARITH = 0b0010011,
    FMT_S       = 0b0100011,
    FMT_SB      = 0b1100011,
    FMT_UJ      = 0b1101111
} rv_format;

// Width values for FMT_I_LOAD and FMT_S
#define LDST_BYTE   0
#define LDST_WORD   2
#define LDST_DOUBLE 3

#define STACK_SIZE 8192

// Sentinel value for stopping the emulator
#define RV_STOP 0

// Dynamic analysis structs

typedef struct {
    int i_count;
    int ir_count;
    int ld_count;
    int st_count;
    int j_count;
    int b_taken;
    int b_not_taken;
} rv_analysis;

// Cache types
typedef enum {CACHE_NONE, CACHE_DM, CACHE_SA} cache_type; 

#define CACHE_MAX_SLOTS 4096
#define CACHE_MAX_BLOCK_SIZE 4

struct cache_slot_st {
    uint64_t valid;
    uint64_t tag;
    uint32_t block[CACHE_MAX_BLOCK_SIZE];
    uint64_t timestamp;
};

struct cache_st {
    struct cache_slot_st slots[CACHE_MAX_SLOTS];
    cache_type type;
    int size;
    int ways;
    int block_size;
    uint64_t block_mask;
    uint64_t block_bits;
    uint64_t index_mask;
    uint64_t index_bits;
    int refs;
    int hits;
    int misses;
    int misses_cold;
    int misses_hot;
    int slots_used;
};

typedef struct {
    uint64_t regs[RV_NUM_REGS];
    uint64_t pc;

    uint8_t stack[STACK_SIZE];

    bool analyze;
    bool cache_sim;
    bool verbose;

    rv_analysis  analysis;
    struct cache_st i_cache;
} rv_state;


void rv_init(rv_state *state, uint32_t *target, 
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
uint64_t rv_emulate(rv_state *state);
void rv_print(rv_analysis *analysis);

void cache_init(struct cache_st *csp);
uint32_t cache_lookup(struct cache_st *csp, uint64_t addr);
void cache_print(struct cache_st *csp, char *name);

// Simple logging
void verbose(char *fmt, ...);
void verbose_cache(int mem_type, char *fmt, ...);
