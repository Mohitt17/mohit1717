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
        int c[n + 1];

        for (int i = 0; i <= n; i++)
        {
            c[i] = 0;
        }

        for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            c[a[i]]++;
        }

        int ans = 0;

        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
            {
                 break;
            }
            ans += c[i];
        }

        printf("%d\n", ans);
    }
}
