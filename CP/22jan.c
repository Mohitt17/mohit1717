#include <stdio.h>
#include <string.h>


int main()
{

    int t;
    scanf("%d", &t);

    while (t--)
    {
        char n[10]; 
        scanf("%s", n);

        int len = strlen(n);
        int first_digit = n[0] - '0';

        int result = 9 * (len - 1) + first_digit;
        printf("%d \n", result);
        

       

    }

    return 0;
}