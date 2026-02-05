#include <stdio.h>
// cp31 800 17.Forbidden Integer
int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, k, x;
        scanf("%d %d %d", &n, &k, &x);

        if (x != 1)
        {
            printf("YES\n");
            printf("%d\n", n);
            for (int i = 0; i < n; i++)
            {
                printf("1 ");
            }
            printf("\n");
        }
        else
        {
            if (k == 1)
            {
                printf("NO\n");
            }
            else if (n % 2 == 0)
            {
                printf("YES\n");
                printf("%d\n", n / 2);
                for (int i = 0; i < n / 2; i++)
                {
                    printf("2 ");
                }
                printf("\n");
            }
            else
            {
                if (k >= 3)
                {
                    printf("YES\n");
                    printf("%d\n", (n - 3) / 2 + 1);
                    printf("3 ");
                    for (int i = 0; i < (n - 3) / 2; i++)
                    {
                        printf("2 ");
                    }
                    printf("\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
        }
    }
    return 0;
}