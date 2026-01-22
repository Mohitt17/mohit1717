#include <stdio.h>

/* swap two values */
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

/* partition used in quickselect */
int partition(float arr[], int left, int right) {
    float pivot = arr[right];
    int i = left - 1, j;

    for (j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

/* function to find kth smallest element */
float kth_smallest(float arr[], int n, int k) {
    int left = 0, right = n - 1;

    while (1) {
        int pos = partition(arr, left, right); // pivot position
        int rank = pos - left + 1;             // rank of pivot

        if (rank == k)
            return arr[pos];
        else if (k < rank)
            right = pos - 1;        // search left part
        else {
            k = k - rank;           // search right part
            left = pos + 1;
        }
    }
}

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (in == NULL) {
        printf("ERROR: Could not open input.txt for reading.\n");
        return 0;
    }

    int n, m, i;
    fscanf(in, "%d", &n);               // read number of elements

    float arr[n];
    for (i = 0; i < n; i++)
        fscanf(in, "%f", &arr[i]);      // read array

    fscanf(in, "%d", &m);               // read M

    if (m < 1 || m > n) {
        fprintf(out, "Invalid M value\n");
        fclose(in);
        fclose(out);
        return 0;
    }

    /* convert M-th largest to k-th smallest */
    int k = n - m + 1;

    float ans = kth_smallest(arr, n, k);

    fprintf(out, "%.2f\n", ans);

    fclose(in);
    fclose(out);

    return 0;
}
