int fact_rec_c_1(int n) {
    if (n == 0) {
        /* Base case */
        return 1;
    } else {
        /* Recursive step */
        return fact_rec_c_1(n - 1) * n;
    }
}

int fact_rec_c(int n) {
    int r;
    
    if (n == 0) {
        r = 1;
    } else {
        r = fact_rec_c(n - 1) * n;
    }

    return r;
}
