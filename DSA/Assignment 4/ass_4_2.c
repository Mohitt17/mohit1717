#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int p = partition(arr, low, high);

        if (p == k)
            return arr[p];
        else if (p > k)
            return quickSelect(arr, low, p - 1, k);
        else
            return quickSelect(arr, p + 1, high, k);
    }
    return -1;
}

int main()
{
    int n, k, choice;

    printf("Enter number of students: ");
    scanf("%d", &n);

    int marks[n];

    printf("Enter marks:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &marks[i]);

    printf("Enter value of k: ");
    scanf("%d", &k);

    printf("\n1. k-th Smallest\n2. k-th Largest\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        int result = quickSelect(marks, 0, n - 1, k - 1);
        printf("%d-th Smallest Mark = %d\n", k, result);
    }
    else if (choice == 2)
    {
        int result = quickSelect(marks, 0, n - 1, n - k);
        printf("%d-th Largest Mark = %d\n", k, result);
    }
    else
    {
        printf("Invalid choice\n");
    }

    return 0;
}
