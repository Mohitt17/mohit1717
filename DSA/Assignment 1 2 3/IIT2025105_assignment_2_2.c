#include <stdio.h>

int totalCost = 0;

void mergeFiles(int arr[], int n)
{
    if (n == 1)
        return;

    int minIndex = 0;
    int minSum = arr[0] + arr[1];

    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] + arr[i + 1] < minSum)
        {
            minSum = arr[i] + arr[i + 1];
            minIndex = i;
        }
    }

    printf("Merge %d and %d is %d (Cost: %d)\n",
           arr[minIndex], arr[minIndex + 1], minSum, minSum);

    totalCost += minSum;
    arr[minIndex] = minSum;

    for (int i = minIndex + 1; i < n - 1; i++)
    {
        arr[i] = arr[i + 1];
    }

    mergeFiles(arr, n - 1);
}

int main()
{
    int n;
    printf("Enter n:-");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    mergeFiles(arr, n);

    printf("Final File Size: %d\n", arr[0]);
    printf("Total Merge Cost: %d\n", totalCost);

    return 0;
}
