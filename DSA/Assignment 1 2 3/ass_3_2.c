#include <stdio.h>

int main() {
    int a[] = {1, 3, 8, 12, 4, 2};
    int n = 6;

    int i = 0, j = n - 1;

    while (i < j) {
        int mid = i + (j - i) / 2;

        if (a[mid] < a[mid + 1]) {
            i = mid + 1;   
        } else {
            j = mid;      
        }
    }


    printf("Peak element: %d", a[i]);
    return 0;
}
