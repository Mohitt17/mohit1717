#include <stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);

    int a[t];
    for (int i = 0; i < t; i++)
    {
        scanf("%d",&a[i]);
    }
    
    int min=abs(a[0]);
    for (int i = 1; i < t; i++)
    {
        if (min>=abs(a[i]))
        {
         min=a[i];
        }
        
    }
    // int b=sqrt(min*min);
    
    printf("%d",min);
    
 return 0;
}

// 3 	1890A Doremy's Paint 3 //
//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         int n;
//         scanf("%d",&n);
//         int a[n];
//         for (int i = 0; i < n; i++)     
//         {
//             scanf("%d",&a[i]);

//         }

//         if (n%2!=0)
//         {
//             int k=(a[0]+a[1]);
//             int o=1;
//             int d=1;
//             while(d<n-1)        //(d<<(n/2) ||( (n/2)+1)<<d<<n)
//             {
//                 if((a[d]+a[d+1])!=k){
 
//                     o=0;
//                     break;
//                 }
//                 d++;
//             }
//             int x = n/2 +1 ;
//             if (o)
//             {
//                 printf("Yes\n");
//             }
//             else
//             printf("No\n");
        
//          }
//          else{
//             int k=(a[0]+a[1]);
//             int m=1;
//             int j=1;
//             while(j<n-1)
//             {
//                 if((a[j]+a[j+1])!=k){
 
//                     m=0;
//                     break;
//                 }
//                 j++;
//             }
            
//             if (m)
//             {
//                 printf("Yes\n");
//             }
//             else
//             printf("No\n");
        
//          }

//     }
    
// }
    //2

//     int t;
//     scanf("%d", &t);

//     while (t--)
//     {
//         int n;
//         scanf("%d", &n);

//         int a[n];
//         for (int i = 0; i < n; i++)
//         {
//             scanf("%d", &a[i]);
//         }

//         int changed = 1;
//         while (changed)
//         {
//             changed = 0;
//             for (int i = 1; i <= n - 2; i++)
//             {
//                 if (a[i - 1] < a[i] && a[i] > a[i + 1])
//                 {
//                     int temp = a[i];
//                     a[i] = a[i + 1];
//                     a[i + 1] = temp;
//                     changed = 1;
//                 }
//             }
//         }

//         int ok = 1;
//         for (int i = 0; i < n - 1; i++)
//         {
//             if (a[i] > a[i + 1])
//             {
//                 ok = 0;
//                 break;
//             }
//         }

//         if (ok)
//             printf("YES\n");
//         else
//             printf("NO\n");
//     }

//     return 0;
// }

// 1
//     int t;
//     scanf("%d", &t);

//     while (t--) {

//         int n;
//         scanf("%d",&n);//Vanya First ,,Vova Second .
// if (n % 3 == 0)
//             printf("Second\n");
//         else
//             printf("First\n");
//     }
