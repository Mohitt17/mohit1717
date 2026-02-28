#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int exponentialSearch(int arr[], int n, int key) {
    if (arr[0] == key)
        return 0;

    int i = 1;
    while (i < n && arr[i] <= key)
        i = i * 2;

    int left = i / 2;
    int right = (i < n) ? i : n - 1;

    return binarySearch(arr, left, right, key);
}


int main()
{
    int n;
    scanf("%d", &n);
    printf("Enter Sorted Array :");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Key:");
    int k;
    scanf("%d", &k);

    printf("Position using Binary Search : %d \n",binarySearch(a,0,n-1,k));
    printf("Position using Exponential Search : %d \n",exponentialSearch(a,n,k));

    return 0;
}
