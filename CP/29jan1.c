#include <stdio.h>

int main()
{

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a[n];
        int xo = 0;

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            xo ^= a[i];
        }

        if (n % 2 == 1)
        {

            printf("%d\n", xo);
        }
        else
        {

            if (xo == 0)
                printf("0\n");
            else
                printf("-1\n");
        }
    }

    return 0;
}