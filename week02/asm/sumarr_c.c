int sumarr_c(int a[], int len) {
    int sum = 0;
    int i;

    for (i = 0; i < len; i++) {
        sum = sum + a[i];
    }

    return sum;
}
