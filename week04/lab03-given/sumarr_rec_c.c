int sumarr_rec_c(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }
    return arr[start] + sumarr_rec_c(arr, start + 1, end);
}
