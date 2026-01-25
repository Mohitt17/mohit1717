#include<stdio.h> 

int main(){ 

    int t;
    scanf("%d",&t);

    while (t--)
    {
        int n;
        scanf("%d",&n);
        int a[n];
        for (int i = 0; i < n-1; i++)
        {
            scanf("%d",&a[i]);
        }

        a[n-1]=0;
        for (int i = 0; i < n-1; i++)
        {
            a[n-1]+=a[i];
        }
        
        printf("%d\n",(-a[n-1]));

    }
    
     

return 0;
}