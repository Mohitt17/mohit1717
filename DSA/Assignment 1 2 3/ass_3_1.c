#include <stdio.h>

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
    printf("Enter Target sum:");
    int target;
    scanf("%d", &target);

    int l = 0, r = n - 1;

    while (l < r)
    {
        int sum = a[l] + a[r];

        if (sum == target)
        {
            printf("(%d, %d)", a[l], a[r]);
            return 0;
        }
        else if (sum < target)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    printf("-1");

    return 0;
}