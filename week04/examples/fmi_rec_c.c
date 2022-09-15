
int fmi_rec1_c(int *arr, int len, int i, int max_i) {
    int max_new = max_i;
    
    if (i >= len) {
        /* base case */
        return max_i;
    } else {
        /* recursive step */
        if (arr[i] > arr[max_i]) {
            max_new = i;
        }
        return fmi_rec1_c(arr, len, i + 1, max_new);
    }
}

int fmi_rec_c(int *arr, int len, int i, int max_i) {
    int max_new = max_i;
    int r;
    
    if (i >= len) {
        /* base case */
        r = max_i;
    } else {
        /* recursive step */
        if (arr[i] > arr[max_i]) {
            max_new = i;
        }
        r = fmi_rec_c(arr, len, i + 1, max_new);
    }
    return r;
}
