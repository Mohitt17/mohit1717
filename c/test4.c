#include <stdio.h>

int main() {
    int n, k;
    int i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];   // main array

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K (left shifts): ");
    scanf("%d", &k);

    
    if (n > 0)
        k = k % n;

    // Pointer to the first element
    int *p = arr;

    
    while (k > 0) {
        int first = *p;          // save first element

        // shift all elements one step left using pointers
        for (i = 0; i < n - 1; i++) {
            *(p + i) = *(p + i + 1);
        }

        
        *(p + n - 1) = first;

        k--;
    }

    printf("Array after left rotation: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(p + i));
    }
    printf("\n");

    return 0;
}
