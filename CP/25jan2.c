#include <stdio.h>

int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        char a[10][11];
        int point = 0;
        for (int i = 0; i < 10; i++)
        {

            scanf("%s", a[i]);
        }

        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (a[i][j] == 'X')
                {
                    if (i == 0 || i == 9 || j == 0 || j == 9)
                        point += 1;
                    else if (i == 1 || i == 8 || j == 1 || j == 8)
                        point += 2;
                    else if (i == 2 || i == 7 || j == 2 || j == 7)
                        point += 3;
                    else if (i == 3 || i == 6 || j == 3 || j == 6)
                        point += 4;
                    else
                        point += 5;
                }
            }
        }

        printf("%d\n", point);
    }

    return 0;
}