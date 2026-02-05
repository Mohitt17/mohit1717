#include <stdio.h>

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);

        int y = (d - b);
        int x = (c - a);

        if (y < 0 || x > y)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", 2 * y - x);
        }
    }

    return 0;
}