#include<stdio.h> 

int main(){ 

    int t;
    scanf("%d", &t);

    while (t--)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        if (a>(b+c)){
            printf("First\n");
        }
        else if (b>(a+c))
        {
            printf("Second\n");
        }
        else if (a==b && c%2==1)
        {
            printf("First\n");
        }
        else if (a==b && c%2==0)
        {
            printf("Second\n");
        }
        else if ((a+c)>(b+c))
        {
            printf("First\n");
        }
        else if ((a+c)<(b+c))
        {
            printf("Second\n");
        }

        
       
        // else printf("None\n");
        


    }
return 0;
}