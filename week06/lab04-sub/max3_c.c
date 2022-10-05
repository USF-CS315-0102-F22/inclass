int max3_c(int v0, int v1, int v2) {
    int r;
    int max2 = v0 > v1 ? v0 : v1;
    r = max2 > v2 ? max2 : v2;

    return r;
}
