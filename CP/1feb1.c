#include <stdio.h>

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int x;
        scanf("%d", &t);
        int a[x];
        for (int i = 0; i < x; i++)
        {
            scanf("%d", &a[i]);
        }
        int p = 0;
        int n = 0;

        for (int i = 0; i < x; i++)
        {
            if (a[i] == 1)
            {
                p++;
            }
            else
                n++;
        }

        int oP = 0;

        while (p < n || n % 2 == 1)
        {
            oP++;
            p++;
            n--;
        }
        printf("%d\n", oP);
    }

    return 0;
}