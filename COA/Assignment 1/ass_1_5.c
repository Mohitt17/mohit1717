#include<stdio.h> 

int main(){ 
    char bin[100];
    int len, i, value;

    scanf("%s", bin);
    len = strlen(bin);

    int pad = (4 - (len % 4)) % 4;
     for (i = 0; i < len; i++)
    {
         if ((i + pad + 1) % 4 == 0)
        {
         value = ( (bin[i - 3] - '0') * 8 +
                    (bin[i - 2] - '0') * 4 +
                    (bin[i - 1] - '0') * 2 +
                    (bin[i] - '0') * 1 );
            if (value>9){
                if (value==10)
                {
                    printf("A");
                }
                else if (value==11)
                {
                    printf("B");
                }
                else if (value==12)
                {
                    printf("C");
                }
                else if (value==13)
                {
                    printf("D");
                }
                else if (value==14)
                {
                    printf("E");
                }
                else if (value==15)
                {
                    printf("F");
                }
             }
            
            else printf("%d", value);
        }
    }
return 0;
}
