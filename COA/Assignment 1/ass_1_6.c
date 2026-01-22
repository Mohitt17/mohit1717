#include<stdio.h> 
int oct_dec_method1(int a[],int n){//positional power method
    
    int num=0;
    for (int i = n-1; i >=0; i--)
    {
        num+=(pow(8,i)*a[i]);
    }
    return num;
}

int oct_dec_method2(int a[],int n){//iterative multiplication method
    int decimal=0;
    for (int i = n-1; i >=0; i--) {
        decimal = decimal * 8 + a[i];
    }
    return decimal;
}

int main(){ 

     int n;
    scanf("%d", &n);
    int a[n];
    for (int i = n-1; i >=0; i--)
    {
        scanf("%d",&a[i]);
    }
    printf("positional power method:- %d \n",oct_dec_method1(a,n));
    printf("iterative multiplication method:- %d",oct_dec_method2(a,n));
    

return 0;
}