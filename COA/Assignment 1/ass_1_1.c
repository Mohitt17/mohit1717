#include <stdio.h>
//1
void dec_bin(int a)
{
    int b[100];
    int i = 0;
    while (a >= 0)
    {
        if (a == 0)
        {
            b[i] = 0;
            break;
        }
        else if (a == 1)
        {
            b[i] = 1;
            break;
        }
        else{
            b[i]=(a%2);
        }
        i++;
        a=(a/2);
    }
    for (int j = i; j >=0 ; j--)
    {
        printf("%d",b[j]);
    }    
};
int main()
{
    int a;
    scanf("%d",&a);
    dec_bin(a);
    return 0;
}