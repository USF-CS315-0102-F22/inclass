int max2_c(int a, int b) {
    if (a > b) {
        return a;
    }
    return b;
}

int max3_c(int a, int b, int c) {
    int first_two = max2_c(a, b);
    int retval = max2_c(first_two, c);
    return retval;
}
