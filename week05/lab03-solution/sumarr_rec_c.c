int sumarr_rec1_c(int *arr, int start, int end) {
    if (start == end) {
        return arr[start];
    }
    return arr[start] + sumarr_rec1_c(arr, start + 1, end);
}

int sumarr_rec2_c(int *arr, int start, int end) {
    int start_val = arr[start];
    
    if (start == end) {
        return start_val;
    }
    return start_val + sumarr_rec2_c(arr, start + 1, end);
}


int sumarr_rectail_c(int *arr, int start, int end, int sum) {
    if (start == end) {
        return arr[end] + sum;
    }

    return sumarr_rectail_c(arr, start + 1, end, arr[start] + sum);
}

int sumarr_rec_c(int *arr, int start, int end) {
    return sumarr_rectail_c(arr, start, end, 0);
}


