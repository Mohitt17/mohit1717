#include<stdio.h> 

int main()
{ 
//1 Right-Angled Triangle 
    int n;

   printf("1.Right-Angled Triangle \n Enter the number of rows :");
   scanf("%d",&n);

   for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= i; j++)
         printf("* ");

      printf("\n");
   }
   printf("\n");

//2 Inverted Right-Angled Triangle
 
   
   printf("2.Inverted Right-Angled Triangle \n Enter the number of rows :");
   scanf("%d",&n);

   for(int i = n; i >= 1; i--) {
      for(int j = 1; j <= i; j++)
         printf("* ");

      printf("\n");
   }
   printf("\n");

//3 Number Pyramid
  
   printf("3.Number Pyramid \n Enter the number of rows :");
   scanf("%d",&n);

for (int i = 1; i <= n; ++i) {
       
        for (int j = 1; j <= n - i; ++j) {
            printf("  ");
        }

        
        for (int k = 1; k <= i; ++k) {
            printf("%d ", k);
        }

        
        for (int k = i - 1; k >= 1; --k) {
            printf("%d ", k);
        }

        printf("\n");
    }
    printf("\n");

 //4 Floyd’s Triangle

   int k = 1;

   printf("4.Floyds Triangle \nEnter the number of rows :");
   scanf("%d",&n);

   for(int i = 1; i <= n; i++) {
      for(int j = 1;j <= i; j++)
         printf("%3d", k++);

      printf("\n");
   }
printf("\n");

//5 Pascal’s Triangle

   printf("5.Pascals Triangle \n Enter the number of rows :");
   scanf("%d",&n);
   
    for (int i = 0; i < n; i++)
      {

        for (int j = 0; j < n - i - 1; j++) {
            printf("  ");
        }

        int num = 1; 

        
        for (int j = 0; j <= i; j++) {
            printf("%4d", num);
            num = num * (i - j) / (j + 1); 
         
        }
        printf("\n"); 

      }
   
   printf("\n"); 

//6 Diamond Pattern
   printf("6.Diamond Pattern \n Enter the number of rows :");
   scanf("%d",&n);
       for(int i=0; i<n; i++){
        for(int j=n-i-1; j>0; j--){
            printf(" ");
        }
        for(int k=0; k<=i; k++){
            printf("* ");
        }
        printf("\n");
    }
       for(int i=n-2; i>=0; i--){
        for(int j=n-i-1; j>0; j--){
            printf(" ");
        }
        for(int k=i; k>=0; k--){
            printf("* ");
        }
        printf("\n");
    }
printf("\n"); 

//7 Hollow Square Border
   printf("7.Hollow Square Border \n Enter the number of rows :");
   scanf("%d",&n);

    for(int i=0;i<n; i++){
        for(int j=0; j<n; j++){
            if(j==0 || j==n-1){
                printf("* ");
            }
            else if(i==0 || i==n-1){
                printf("* ");
            }
            else{
                printf("  ");
            }
        }
        printf("\n");
    }
   printf("\n"); 


//8 Zigzag Number
   printf("8.Zigzag Number Pattern \n Enter the number  :");
   scanf("%d",&n);   
   int num=1;
   int s=0;
   
   for(int i=0; num<n; i++){
        for (int k = 0; k < s; k++) {
            printf(" ");
        }
        for(int j=1; j<=5-i; j++){
            printf("%d ",num);
            num++;
        }
        s++;
        printf("\n");
    }
 printf("\n");


//9 Binary Triangle
   printf("9.Binary Triangle \n Enter the number of rows :");
   scanf("%d",&n);

for (int i = 0; i < n; i++)
{
   for (int j = 0; j <=i ; j++)
   {
      while ((i+j)%2==0)
      {
         printf("1 ");
         break;
      }
      while ((i+j)%2!=0)
      {
         printf("0 ");
         break;
      }
   }
   printf("\n");
}



//10 Hourglass Pattern
   printf("10.Hourglass Pattern \n Enter the number of rows :");
   scanf("%d",&n);
    for(int i=n; i>=n/2; i--){
        for(int j=n-i; j>0; j--){
            printf(" ");
        }
        for(int k=0; k<i; k++){
            printf("* ");
        }
        printf("\n");
    }
    for(int i=(n/2)+1; i<=n; i++){
        for(int j=n-i; j>0; j--){
            printf(" ");
        }
        for(int k=0; k<i; k++){
            printf("* ");
        }
        printf("\n");
    }

return 0;
}
