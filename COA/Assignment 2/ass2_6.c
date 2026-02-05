#include<stdio.h> 
#include<float.h>

int main(){ 

    float num= FLT_MIN;

    printf("Normalized minimum values : %e\n",num);

    num=num/2;
    printf("Subnormal value : %e\n",num);
    

return 0;
}