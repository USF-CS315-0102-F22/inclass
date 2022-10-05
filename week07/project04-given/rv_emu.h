// RISC-V emulator types and constants

#include <stdbool.h>
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


// Dynamic analysis structs

struct rv_analysis_st {
    int i_count;
    int ir_count;
    int ld_count;
    int st_count;
    int j_count;
    int b_taken;
    int b_not_taken;
};

// Cache types
enum cache_type_en {CACHE_NONE, CACHE_DM, CACHE_SA};

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
    enum cache_type_en type;
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

// rv_state represents the state of the emulated RISC-V processor
struct rv_state {
    uint64_t regs[NREGS];
    uint64_t pc;
    uint8_t stack[STACK_SIZE];
    
    bool analyze;
    bool cache_sim;
    bool verbose;

    struct rv_analysis_st analysis;
    struct cache_st i_cache;
};

// Initialize an rv_state struct with a function pointer and arguments
void rv_init(struct rv_state *rsp, uint32_t *fp,
             uint64_t a0, uint64_t a1, uint64_t a2, uint64_t a3);
int rv_emulate(struct rv_state *rsp);

void rv_print(struct rv_analysis_st *analysis);

void cache_init(struct cache_st *csp);
uint32_t cache_lookup(struct cache_st *csp, uint64_t addr);
void cache_print(struct cache_st *csp, char *name);

// Simple logging
void verbose(char *fmt, ...);
void verbose_cache(int mem_type, char *fmt, ...);
