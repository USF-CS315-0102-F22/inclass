int find_max_index_c(int * arr, int len) {
    int idx = 0;
    for (int i = 0; i < len; i++) {
        if (arr[i] > arr[idx]) {
            idx = i;
        }
    }
    return idx;
}
