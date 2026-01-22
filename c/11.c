#include<stdio.h> 
#include<math.h>

int main(){ 

   double P, R, T;

    printf("Enter The values : ");

    scanf("%lf",&P);
    printf("Enter rate of interest :");
    scanf("%lf",&R);
    printf("Enter Time :");
    scanf("%lf",&T);

    double n=1;
    double SI=(P*R*T/100) ;
    double  A = P * pow((1 + R / 100), T); 

    double CI= A-P;
     
    printf("simple Interest is %.2lf.",SI);
    printf("Compound Interest is %.2lf.",CI);
return 0;
}