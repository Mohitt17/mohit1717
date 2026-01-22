#include<stdio.h> 


  ///////////mean
    int main() {
   int loop;
   int factorial=1;
   int number = 5;

   for(loop = 1; loop<= number; loop++) {
      factorial = factorial * loop;
   }

   printf("Factorial of %d = %d \n", number, factorial);

   return 0;
}

    ///////////median
    void swap(int *p,int *q) {
   int t;
   
   t=*p; 
   *p=*q; 
   *q=t;
}

void sort(int a[],int n) { 
   int i,j,temp;

   for(i = 0;i < n-1;i++) {
      for(j = 0;j < n-i-1;j++) {
         if(a[j] > a[j+1])
            swap(&a[j],&a[j+1]);
      }
   }
}

int main() {
   int a[] = {6,3,8,5,1};
   int n = 5;
   int sum,i;

   sort(a,n);
   
   n = (n+1) / 2 - 1;      // -1 as array indexing in C starts from 0

   printf("Median = %d ", a[n]);

   return 0;
}
//////mode
int mode(int a[],int n) {
   int maxValue = 0, maxCount = 0, i, j;

   for (i = 0; i < n; ++i) {
      int count = 0;
      
      for (j = 0; j < n; ++j) {
         if (a[j] == a[i])
         ++count;
      }
      
      if (count > maxCount) {
         maxCount = count;
         maxValue = a[i];
      }
   }

   return maxValue;
}

int main() {
   int n = 5;
   int a[] = {0,6,7,2,7};

   printf("Mode = %d ", mode(a,n));

   return 0;
}
/////permutation
int factorial(int n) {
   int f;

   for(f = 1; n > 1; n--)
      f *= n;

   return f;
}

int npr(int n,int r) {
   return factorial(n)/factorial(n-r);
}

int main() {
   int n, r;

   n = 4;
   r = 3;

   printf("%dp%d = %d \n", n, r, npr(n,r));

   return 0;
}
////////hcf
int main() {
   int a, b, i, hcf;

   a = 12;
   b = 16;

   for(i = 1; i <= a || i <= b; i++) {
   if( a%i == 0 && b%i == 0 )
      hcf = i;
   }

   printf("HCF = %d", hcf);
   
   return 0;
}
////////lcm
int main() {
   int a, b, max, step, lcm;

   a   = 3;
   b   = 4;
   lcm = 0;

   if(a > b)
      max = step = a;
   else
      max = step = b;

   while(1) {
      if(max%a == 0 && max%b == 0) {
         lcm = max;
         break;    
      }

      max += step;
   }

   printf("LCM is %d", lcm);
   return 0;
}

