#include <stdio.h>
#include <math.h>  


int main(){ 
    //1
    int num1,n1=0,n2=1,n3;    //0 1 1 2 3 5 8
    printf("Enter the number for Fibonacci Series(upto n terms):");
    scanf("%d",&num1);
    if (num1<=0){
        printf("Invalid\n");
    }
    else {
        for (int  i = 0; i < num1; i++)
        {
           printf("%d \t",n1);
           n3=n1 + n2;
           n1=n2;
           n2=n3;
        }
    }

    //2
    int num2,num3,isprime;
    printf("\n Enter the first number :");
    scanf("%d",&num2);
    printf(" Enter the last number :");
    scanf("%d",&num3);

    if (num2 > num3 || num2 < 1) {
        printf("Invalid range \n");
        return 0;
    }

    int found = 0;
    for (int i = num2; i <= num3; i++) {
        if (i == 1) continue; // 1 is not prime
        isprime = 1;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isprime = 0;
                break;
            }
        }
        if (isprime) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("None\n");
    }

    //3
    int a, d=0, n, i, sum = 0;
    printf("Enter values of a,d,n:");
    scanf("%d %d %d", &a, &d, &n);
    if(n <= 0) { printf("\nInvalid\n"); 
        return 0; }
    for(i = 0; i < n; i++) {
        int term = a + i*d;
        printf("%d ", term);
        sum += term;
    }
    printf("\n%d\n", sum);

    //4 GP,
    printf("\nPlease enter a r n: ");
    int a_1,r,n_0;
    
    scanf("%d %d %d",&a_1, &r,&n_0);
    int tn=a_1;
    long product=1;
    for(int i=1; i<=n_0; i++){
        printf("%d, ",tn);
        product*=tn;
        tn*=r;
    }
    printf("Product = %ld \n",product);

    //5 alternating HP
    int k;
    printf("\nEnter k: ");
    scanf("%d", &k);
    double S=0;
    if(k<=0){
        printf("Invalid");
    }
    else{
        int sgn=1;
        for(int i=1; i<=k; i++){
            S+= 1.0/i*sgn;
            sgn*= -1;
       }
       printf("\nS = %.6lf \n",S);
    }

    //6 factorial series and Cumulative sum
    int n_1;
    printf("\nEnter n: ");
    scanf("%d",&n_1);
    int fact = 1;
    printf("\n");
    int long Sum=0;
    for(int i=1; i<=n_1; i++){
        fact*=i;
        printf("%d ",fact);
        Sum+= fact;
    }
    printf("\nSum = %ld",Sum);

    //7 Armstrong Number upto N
    

    //8
    printf("\nEnter x and upto which term you want e^x ");
    double x; // use double for x here
    int n_2;
    scanf("%lf %d", &x, &n_2);
    if(n_2<=0){
        printf("\nInvalid");
    }
    else{
        double series_s=1;
        double term=1; // term should be double
        for(int k=1; k<n_2; k++){
            term *= x/k;
            series_s+=term;
        }
        printf("%.6lf",series_s);
    }

    //9
    double x_1;
    int n_3;
    printf("\nEnter x & n");
    scanf("%lf %d", &x_1, &n_3);
    if (x_1 >= 1 || x_1 <= -1 || n_3<=0){ // correct variables used in condition
        printf("Invalid");
    }
    else{
        double log_sum = 0;
        int sgn_ = 1;
        double power = x_1;
        for(int i=1; i<=n_3; i++){
            log_sum+= sgn_ * power / i;
            power *= x_1;
            sgn_*= -1;
        }
        printf("%lf \n",log_sum);
    }

    //10
    double eps;
    int maxN;
    int x_2;
    printf("\nEnter x eps maxN: ");
    scanf("%d %lf %d",&x_2, &eps, &maxN);
    if(eps<0 || maxN<=0){
        printf("\nInvalid");
    }
    else{
        double next_term=1;
        int K=1;
        double Sum_of_series =0;
        do
        {
            Sum_of_series+=next_term;
            next_term*= (double)x_2/K;
            K++;
    } while (fabs(next_term)>=eps && K<=maxN);
        printf("\nSum = %lf \n", Sum_of_series);
    }

    return 0;
}
