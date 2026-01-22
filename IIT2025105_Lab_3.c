#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main(){
    //1
    int A[] = {1,2,3,4,5,6};
    int quieries[3][2]={{0,4},{2,5},{1,4}}; // Q=3
    int Q = 3;
    printf("The sum is");
    for(int j=0; j<Q; j++){
        int sum=0;
        int L=quieries[j][0];
        int R=quieries[j][1];
        for (int i=L; i<=R; i++){
            sum+=A[i];
        }
        printf(", %d", sum);
    }

    //2
    int A[] = {1, 2, 2, 3, 3, 3, 4, 5, 5};
    int l = sizeof(A) / sizeof(A[0]);
    int K = 3;

    for (int i = 0; i <= l - K; i++) {
        int distinct_count = 0;

        for (int j = i; j < i + K; j++) {
            int is_distinct = 1;
            for (int k = i; k < j; k++) {
                if (A[k] == A[j]) {
                    is_distinct = 0;
                    break;
                }
            }
            if (is_distinct) distinct_count++;
        }

        printf("%d ", distinct_count);
    }



    //3
    int A[]= {2,3,5,1,10,4,6,12,30,2};
    int smallest=1;
    int n=(sizeof(A)/sizeof(A[0]));
    //sorting A
    for(int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++){
            if (A[j]>A[j+1]){
                int temp=A[j];
                A[j]= A[j+1];
                A[j+1]=temp;
            }
        }
    }
    //finding smallest missing +ve int
    for(int i=0; i<n; i++){
        if (A[i]>0 && A[i]==smallest){
            smallest+=1;
        }
    }
    printf("\nSmallest %d",smallest);

    //4
    int A[]= {-1,-2,0,4,2,5,6,8,20};
    int n=(sizeof(A)/sizeof(A[0]));
    int max_sum=INT_MIN;
    for(int i=0; i<n; i++){//starting pt
        for(int j=i; j<n;j++){//ending pt
            int sum_subarr=0;
            for(int k=i; k<=j; k++){//innerloop(finds sum of subarr[i to j] )
                sum_subarr+=A[k];
            }
            if (sum_subarr>max_sum){
                max_sum=sum_subarr;
            }
            sum_subarr=0;
        }
    }
    printf("maximum sum= %d",max_sum);


    //5
    int A[]= {-1,-2,0,4,2,5,6,8,20};
    int n=(sizeof(A)/sizeof(A[0]));
    int K_1;
    printf("\nGive K: ");
    scanf("%d",&K_1);
    int arr_div_by_k=0;
    for(int i=0; i<n; i++){//starting pt
        for(int j=i; j<n;j++){//ending pt
            int sum_subarr=0;
            for(int k=i; k<=j; k++){//innerloop
                sum_subarr+=A[k];
            }
            if(sum_subarr%K_1==0){
                arr_div_by_k+=1;
            }
            sum_subarr=0;
        }
    }
    printf("\nThe number of subarrays whose sum is divisible by k is %d",arr_div_by_k);

    //6
    int A[]={9,8,7,6,7,8,9};
    int n= (sizeof(A)/sizeof(A[0]));
    for (int i=1; i<n;i++){
        int sum_1 = A[0];
        int sum_2 =0;
        //left
        for (int j=1;j<=i-1;j++){
            // 0
            sum_1+=A[j];
        }
        //right
        for (int k=n-1; k>=i+1; k--){
            sum_2+=A[k];
        }
        
        if (sum_2==sum_1){
            printf("%d ", i);
        }
    }
    
    //7
    int64_t a,b;
    printf("Enter a,b ");
    scanf("%lld %lld", &a,&b);
    
    //gcd
    int64_t num_1 = a;
    int64_t num_2 = b;
    while(num_1!=num_2){
        if (num_1>=num_2){
            num_1-=num_2;
        }
        if (num_2>=num_1){
            num_2-=num_1;
        }
    }

    printf("gcd(%lld,%lld) = %lld",a,b,num_1);
    // lcm = a*b/gcd
    int64_t lcm = a*b/num_1;
    printf("\nlcm(%lld,%lld) = %lld",a,b,lcm);
    

    //8
     int B[]={1,2,3,4,5,6};
    int k;
    printf("Enter roatation number: ");
    scanf("%d",&k);
    int n_b= (sizeof(B)/sizeof(B[0]));
    k %= n_b;
    int temp[n_b]; //temp array to store rotated arr
    for (int i=0; i<n_b; i++){
        temp[(i+k)%n_b] = B[i];
    }
    for (int i=0; i<n_b; i++){
        B[i] = temp[i];
    }
    for(int i=0; i<n_b; i++){
        printf("%d ", B[i]);
    }

    //9
    int C[]={2,2,3,3,2,2};
    int n = sizeof(C)/sizeof(C[0]);
    int N;
    int doesAppear = 0;
    printf("\nEnter N: ");
    scanf("%d", &N);
    int max_int = INT_MIN;
    for(int i=0; i<n; i++){
        if (C[i]>max_int) max_int = C[i];
    }
    int hashmap[max_int+1];
    
    
    for(int i=0; i<max_int; i++){
        hashmap[i]=0;
    }
    
    for(int i=0; i<n; i++){
        hashmap[C[i]]++;
    }
    for(int i=0; i<=max_int; i++){
        if(hashmap[i]>N/2){
            printf("\n%d ", i);
            doesAppear = 1;
            }
    }
    if (!doesAppear) printf("\n-1");



    //10
    int matrix[2][3] = { {1, 4, 2}, {3, 6, 8} };
    int R=2;
    int c=3;
    int row_sums[R];
    int col_sums[c];
    for(int i=0; i<R; i++){
        row_sums[i]=0;
    }
    for(int j=0; j<c; j++){
        col_sums[j]=0;
    }
    for(int i=0; i<R; i++){
        for(int j=0; j<c; j++){
            row_sums[i]+=matrix[i][j];
            col_sums[j]+=matrix[i][j];
        }
    }
    
    printf("\nRow sum: ");
    for(int i=0; i<R; i++){
        printf("%d ",row_sums[i]);
    }
    printf("\nColumn sum: ");
    for(int j=0; j<c; j++){
        printf("%d ",col_sums[j]);
    }

    return 0;
}
