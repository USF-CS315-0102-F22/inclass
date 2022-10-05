#include <stdint.h>
#include <stdbool.h>

#define MAX_ARRAY 1024

uint64_t fib_rec_c(uint32_t);
uint64_t fib_rec_s(uint32_t);

int get_bitseq_c(int n, int start, int end);
int get_bitseq_s(int n, int start, int end);

bool pal_rec_c(char *s, int start, int end);
bool pal_rec_s(char *s, int start, int end);

int max3_c(int a, int b, int c);
int max3_s(int a, int b, int c);

void merge_sort_c(int a[], int aux[], int start, int end);
void merge_sort_s(int a[], int aux[], int start, int end);

int midpoint_c(int start, int end);
int midpoint_s(int start, int end);

int quadratic_c(int x, int a, int b, int c);
int quadratic_s(int x, int a, int b, int c);

void sort_c(int arr[], int len);
void sort_s(int arr[], int len);

void to_upper_c(char *src, char *dst);
void to_upper_s(char *src, char *dst);
