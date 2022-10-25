#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Test programs to analyze */

int fib_rec_s(int n);
bool is_pal_rec_s(char *s);
int get_bitseq_s(uint32_t value, int start, int end);
int quadratic_s(int x, int a, int b, int c);

/* Analyze struct */

struct analyze_st {
    int inst_count;
    int itype_count;
    int rtype_count;
    int load_count;
    int stype_count;
    int btype_count;
    int j_count;
    int jal_count;
    int jalr_count;
};

void analyze_init(struct analyze_st *ap) {
    ap->inst_count = 0;
    ap->itype_count = 0;
    ap->rtype_count = 0;
    ap->load_count = 0;
    ap->stype_count = 0;
    ap->btype_count = 0;
    ap->j_count = 0;
    ap->jal_count = 0;
    ap->jalr_count = 0;
}

void analyze_print(struct analyze_st *ap, char *name) {
    printf("[Instruction Analysis: %s]\n", name);
    printf("ITYPE              : %d\n", ap->itype_count);
    printf("RTYPE              : %d\n", ap->rtype_count);
    printf("LOAD               : %d\n", ap->load_count);
    printf("STYPE              : %d\n", ap->stype_count);
    printf("BTYPE              : %d\n", ap->btype_count);
    printf("JAL                : %d\n", ap->jal_count);
    printf("J                  : %d\n", ap->j_count);
    printf("JALR               : %d\n", ap->jalr_count);    
    printf("--------------------\n");
    printf("Total              : %d\n", ap->inst_count);    
}

void analyze_code(struct analyze_st *ap, uint32_t *code) {
    uint32_t *ip = code;
    uint32_t iw;
    uint32_t opcode;
    uint32_t rd;
    while (true) {
        iw = *ip;

        if (iw == 0xc0001073) {
            /* Check for end marker: unimp */
            break;
        }

        opcode = iw & 0b1111111;
        rd     = (iw >> 7) & 0b11111;

        if (opcode == 0b0010011) {
            ap->itype_count += 1;
        } else if (opcode == 0b0110011) {
            ap->rtype_count += 1;
        } else if (opcode == 0b0000011) {
            ap->load_count += 1;
        } else if (opcode == 0b0100011) {
            ap->stype_count += 1;
        } else if (opcode == 0b1100011) {
            ap->btype_count += 1;
        } else if ((opcode == 0b1101111) && (rd == 0)) {
            ap->j_count += 1;
        } else if (opcode == 0b1101111) {
            ap->jal_count += 1;
        } else if (opcode == 0b1100111) {
            ap->jalr_count += 1;
        } else {
            printf("Unrecognized opcode.\n");
            exit(-1);
        }

        ap->inst_count += 1;
        ip += 1;
    }
}

int main(int argc, char **argv) {
    struct analyze_st analyze;

    analyze_init(&analyze);
    analyze_code(&analyze, (uint32_t *) fib_rec_s);
    analyze_print(&analyze, "fib_rec_s");
    printf("\n");

    analyze_init(&analyze);
    analyze_code(&analyze, (uint32_t *) is_pal_rec_s);
    analyze_print(&analyze, "is_pal_rec_s");
    printf("\n");

    analyze_init(&analyze);
    analyze_code(&analyze, (uint32_t *) get_bitseq_s);
    analyze_print(&analyze, "get_bitseq_s");
    printf("\n");

    analyze_init(&analyze);
    analyze_code(&analyze, (uint32_t *) quadratic_s);
    analyze_print(&analyze, "quadratic_s");
    printf("\n");

    return 0;
}
