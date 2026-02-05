#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    //int pivotIndex = low + rand() % (high - low + 1);

   // swap(&arr[pivotIndex], &arr[high]);

    int pivot = arr[low];

    // printf("\nPivot chosen: %d\n", pivot);
    // printf("Before partition: ");
    // display(arr, low, high);

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

    // printf("After partition : ");
    // display(arr, low, high);

    return i+1;
}

void kth_rank(int k, int arr[], int l, int n)
{

    int m = partition(arr, l, n - 1);
    int ans;
    if (k == m)
    {
        ans = arr[k];
    }

    else if (k > m)
    {
        kth_rank(k, arr, m + 1, n - 1);
    }
    else if (k < m)
    {
        kth_rank(k, arr, l, m - 1);
    }
    else
    {
        printf("Invalid");
    }

    printf("The K th rank marks is %d.", ans);
}

int main()
{
    int n,k;
    printf("Enter number of students: ");
    scanf("%d", &n);
   
    int marks[n];

    for (int i = 0; i < n; i++)
    {
        // marks[i] = rand() % 100;
        scanf("%d", &marks[i]);
    }
     printf("Enter value of k: ");
    scanf("%d",&k);

    kth_rank(k,marks,0,n-1);

    return 0;
}