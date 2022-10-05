// Merge two adjecent sub arrays
void merge_c(int a[], int aux[], int start, int end) {
    int mid = (start + end) / 2;  // midpoint
    int pointer_left = start;  // points to the beginning of the left sub-array
    int pointer_right = mid + 1; // points to the beginning of the right sub-array
    int i;  // i is the loop index

    // loop from start to end to fill each element of the final merged array
    for (i = start; i <= end; i++) {
        if (pointer_left == mid + 1) {
            //  left pointer has reached the limit
            aux[i] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == end + 1) {
            // right pointer has reached the limit
            aux[i] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {
            // pointer left points to smaller element
            aux[i] = a[pointer_left];
            pointer_left++;
        } else {
            // pointer right points to smaller element
            aux[i] = a[pointer_right];
            pointer_right++;
        }
    }

    // copy the elements from aux[] to a[]
    for (i = start; i <= end; i++)   
        a[i] = aux[i];
}
