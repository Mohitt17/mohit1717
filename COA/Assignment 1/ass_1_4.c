#include <stdio.h>
#include <string.h>

int main()
{
    char bin[100];
    int len, i, value;

    scanf("%s", bin);
    len = strlen(bin);

    int pad = (3 - (len % 3)) % 3;

    for (i = 0; i < len; i++)
    {
        printf("%c", bin[i]);
        if ((i + pad + 1) % 3 == 0)
        {
        
            value = (bin[i - 2] - '0') * 4 +
                    (bin[i - 1] - '0') * 2 +
                    (bin[i] - '0') * 1;
            printf(" : %d ", value);
        }
    }


    printf("\nOctal: ");

    
    int start = (len + pad) % 3;
    for (i = 0; i < len; i += 3)
    {
        int idx = i - pad;
        if (idx < 0) continue;

        value = (bin[idx] - '0') * 4 +
                (bin[idx + 1] - '0') * 2 +
                (bin[idx + 2] - '0');
        printf("%d", value);
    }

    return 0;
}
/*
000 0
001 1
010 2
011 3
100 4
101 5
110 6
111 7
*/