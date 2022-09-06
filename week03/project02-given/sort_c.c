int find_max_index_c(int *arr, int len);

int sort_c(int *arr, int len) {
    for (int i = 0; i < len; i++) {
        int idx = find_max_index_c(&arr[i], len - i) + i;
        if (arr[idx] > arr[i]) {
            int tmp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = tmp;
        }
    }
}
