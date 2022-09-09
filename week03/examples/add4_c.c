int add2_c(int a, int b) {
    int result = a + b;
    return result;
}

int add4_c(int a, int b, int c, int d) {
    int result, r1, r2;

    r1 = add2_c(a, b);
    r2 = add2_c(c, d);
    result = add2_c(r1, r2);

    return result;
}

int add4_c_hold(int a, int b, int c, int d) {
    int result = a + b + c + d;
    return result;
}
