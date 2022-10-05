int fib_rec_c(int n) {
    if (n <= 1) {
        return n;
    }
    return fib_rec_c(n - 1) + fib_rec_c(n - 2);
}
