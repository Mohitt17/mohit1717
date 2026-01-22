#include<stdio.h> 
#include<math.h>

int bin_dec(int a[],int n){
    
    int num=0;
    for (int i = n-1; i >=0; i--)
    {
        num+=(pow(2,i)*a[i]);
    }
    return num;
}

int main(){ 

    int n;
    scanf("%d",&n);
    int a[n];
    for (int i = n-1; i >=0; i--)
    {
        scanf("%d",&a[i]);
    }

    printf("%d",bin_dec(a,n));
    
     

return 0;
}