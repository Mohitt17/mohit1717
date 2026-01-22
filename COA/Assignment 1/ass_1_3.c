#include <stdio.h>

void dec_to_octal(int n)
{
    int oct[100], i = 0;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        oct[i++] = n % 8;
        n /= 8;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%d", oct[j]);
}

void dec_to_hex(int n)
{
    char hex[100];
    int i = 0;

    if (n == 0)
    {
        printf("0");
        return;
    }

    while (n > 0)
    {
        int rem = n % 16;
        if (rem < 10)
            hex[i++] = rem + '0';
        else
            hex[i++] = rem - 10 + 'A';
        n /= 16;
    }

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex[j]);
}

int main()
{
    int n;
    scanf("%d", &n);

    printf("Octal: ");
    dec_to_octal(n);

    printf("\nHexadecimal: ");
    dec_to_hex(n);

    return 0;
}
