int max2_c(int a, int b) {
    return a > b ? a : b;
}

int max3_c(int a, int b, int c) {
    return max2_c(a, max2_c(b, c));
}
