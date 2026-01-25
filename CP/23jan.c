#include<stdio.h> 

int main(){ 

     int t;
     scanf("%d",&t);

     while (t--)
     {
        int n;
        scanf("%d",&n);
        int a[n];
        for (int i = 0; i < n ; i++)
        {
            scanf("%d",&a[i]);
        }
            int max=0;
            int count=0;

            for (int i = 0; i < n; i++)
            {
                if (a[i]==0)
                {
                    count++;
                    if (count>=max)
                    {
                        max=count;
                    }
                    
                }
                
                else if(a[i]==1){
                    count=0;
                }
            }
            
        
        printf("%d\n",max);
     }
     

return 0;
}