#include <stdio.h>

int water(int a[],int n){
    



}

int main()
{
int t;
    scanf("%d", &t);

    while (t--)
    {
        int n;
        scanf("%d", &n);

        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }
        


    }



}


    //2
    /*
    int t;
    scanf("%d", &t);

    while (t--)
    {
        int n, x;
        scanf("%d %d", &n, &x);

        int a[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d",&a[i]);
        }

        int count = a[0];

        for (int i = 1; i < n; i++)
        {
            int diff = a[i] - a[i - 1];
            if (diff > count)
            {
                count = diff;
            }
        }

        int last = 2 * (x - a[n - 1]);
        if (last > count)
        {
            count = last;
        }

        printf(" %d \n", count);
    }

    return 0;
}
*/


// 1
/* int t;
 scanf("%d",&t);

 while (t--)
 {
     int n,k;
     scanf("%d %d",&n,&k);

     int a[n];
     for (int i = 0; i < n; i++)
     {
         scanf("%d",&a[i]);
     }

     if(k==1){
         int sorted = 1;

         for (int i = 0; i < n - 1; i++) {
             if (a[i] > a[i + 1]) {
                 sorted = 0;
                 break;
             }
         }

         if (sorted)
             printf("YES\n");
         else
             printf("NO\n");

     }
     else {

         printf("YES\n");

 }

}

return 0;
}*/