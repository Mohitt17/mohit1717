#include <stdio.h>

int ind(int n, int petrol[], int cost[])
{
    int tank = 0;
    int i = 0;
    while (i < n)
    {
        int j = i;
        while ((i == 0 && j < n) || (j >0 && i > 0))
        {
            tank += petrol[j] - cost[j];
            if (tank < 0)
            {
                i++;
            }
            if (j == i - 1)
            {
                return i;
            }

            if (j == n - 1)
            {
                j = 0;
            }
            else
            {
                j++;
            }
        }
    }
}

int main()
{

    int n;
    printf("Enter data :");
    scanf("%d", &n);

    int petrol[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &petrol[i]);
    }

    int cost[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cost[i]);
    }

    printf("Index is %d", ind(n,petrol,cost));

    return 0;
}