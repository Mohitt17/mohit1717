#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void display(int arr[], int low, int high)
{
    for (int i = low; i <= high; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high)
{
    int pivotIndex = low + rand() % (high - low + 1);

    swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[high];

    printf("\nPivot chosen: %d\n", pivot);
    printf("Before partition: ");
    display(arr, low, high);

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

    printf("After partition : ");
    display(arr, low, high);

    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int p = partition(arr, low, high);

        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main()
{
    int n = 100;
    int marks[n];

    for (int i = 0; i < n; i++)
        marks[i] = rand() % 100;
    srand(time(NULL));

    quickSort(marks, 0, n - 1);

    printf("\nFINAL SORTED MARKS\n");
    for (int i = 0; i < n; i++)
        printf("%d ", marks[i]);

    printf("\n Weak Students (Lowest Marks): %d %d\n",
           marks[0], marks[1]);

    printf("Top Rankers (Highest Marks): %d %d\n",
           marks[n - 2], marks[n - 1]);

    return 0;
}
