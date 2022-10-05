
void merge_c(int a[], int aux[], int start, int end);
 
// Sort the subsection a[i .. j] of the array a[]
void merge_sort_c(int a[], int aux[], int start, int end) {
    if (end <= start)  // the subsection is empty or a single element
        return;
    int mid = (start + end) / 2;

    // left sub-array is a[start .. mid]
    // right sub-array is a[mid + 1 .. end]

    // sort the left sub-array recursively
    merge_sort_c(a, aux, start, mid);
    // sort the right sub-array recursively
    merge_sort_c(a, aux, mid + 1, end);

    // merge the left and right sides
    merge_c(a, aux, start, end);
}
