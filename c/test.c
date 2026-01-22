//eq tru
#include <stdio.h>
int factorial(int n) {   /// int sum(a,b){a+b  return 1;}
   int f;
   
   for(f = 1; n > 1; n--)
      f *= n;
      
   return f;
}

int ncr(int n,int r) {
   return factorial(n) / ( factorial(n-r) * factorial(r) );
}

int main() {
   int n,i,j;

   n = 5;   // number of rows.

   for(i = 1; i <= n; i++) {
      for(j = 1; j <= n-i; j++)
         printf(" ");

      for(j = 1; j <= i; j++)
         printf("* ");

      printf("\n");
   }
   return 1;
}
///////////////right anglef
int main() {
   int n,i,j;

   n = 5;

   for(i = 1; i <= n; i++) {
      for(j = 1; j <= i; j++)
         printf("* ");

      printf("\n");
   }
   return 0;
}
///////////////up side down
int main(){
int n,i,j;

   n = 5;

   for(i = 1; i <= n; i++) {
      for(j = 1; j < i; j++)
         printf(" "); 

      for(j = i; j <= n; j++)
         printf("* ");

      printf("\n");
   }

   return 1;
}
////////pascal
int main() {
   int n, i, j;

   n = 5;

   for(i = 0; i <= n; i++) {
      for(j = 0; j <= n-i; j++)
         printf("  ");
         
      for(j = 0; j <= i; j++)
         printf(" %3d", ncr(i, j));

      printf("\n");
   }
   return 0;
}
////////////Floyd's Triangle
int main() {
   int n,i,j,k = 1;

   n = 5;

   for(i = 1; i <= n; i++) {
      for(j = 1;j <= i; j++)
         printf("%3d", k++);

      printf("\n");
   }

   return 0;
}
///////////swaping number
int main() {
   int a, b;

   a = 11;
   b = 99;

   printf("Values before swapping - \n a = %d, b = %d \n\n", a, b);

   a = a + b;  // ( 11 + 99 = 110)
   b = a - b;  // ( 110 - 99 = 11)
   a = a - b;  // ( 110 - 11 = 99)
printf("Values after swapping - \n a = %d, b = %d \n", a, b);
   return 0;}

   ///////////armstrong number
   int main() {
   int arms = 153; 
   int check, rem, sum = 0;

   check = arms;

   while(check != 0) {
      rem = check % 10;
      sum = sum + (rem * rem * rem);
      check = check / 10;
   }

   if(sum == arms) 
      printf("%d is an armstrong number.", arms);
   else 
      printf("%d is not an armstrong number.", arms);
      
   return 0;
}
/////////Factorial


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