#include <stdio.h>

int ternarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
        return -1;

    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;

    if (arr[mid1] == key)
    {
        return mid1;
    }
    if (arr[mid2] == key)
    {
        return mid2;
    }

    if (key < arr[mid1])
    {
        return ternarySearch(arr, left, mid1 - 1, key);
    }
    else if (key > arr[mid2])
    {
        return ternarySearch(arr, mid2 + 1, right, key);
    }
    else
    {
        return ternarySearch(arr, mid1 + 1, mid2 - 1, key);
    }
};

int main()
{
    int n;
    scanf("%d", &n);
    printf("Enter Sorted Array : ");
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter Key:");
    int k;
    scanf("%d", &k);
    printf("Index : %d", ternarySearch(a, 0, n - 1, k));

    return 0;
}
