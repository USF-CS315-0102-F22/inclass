int sumarr_ptr_c(int *arr, int len) {
    int i = 0;
    int sum = 0;

    for (i = 0; i < len; i++) {
        sum += *arr;
        arr += 1;
    }

    return sum;
}

int sumarr_index_c(int *arr, int len) {
    int i = 0;
    int sum = 0;

    for (i = 0; i < len; i++) {
        sum += arr[i];
    }

    return sum;
}
