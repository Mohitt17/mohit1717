#include<stdio.h> 
#include<math.h>


int main(){ 
  //1
    int num1;
    printf("Enter the Marks : ");
    scanf("%d",&num1);
    if (num1<=100 && num1>=90)
    {
       printf("Your grade is A+. \n");
    }
    else if ((num1<=89) && (num1>=80)) 
    {
       printf("Your grade is A. \n");
    }
    else if ((num1<=79) && (num1>=70))
    {
       printf("Your grade is B. \n");
    }
    else if ((num1<=69) && (num1>=60))
    {
       printf("Your grade is C. \n");
    }
    else if ((num1<=59) && (num1>=50))
    {
       printf("Your grade is D. \n");
    }
    else if ((num1<50) && (num1>0))
    {
       printf("Your grade is F. \n");
    }
    else{
      printf("Invalid Input \n");
    }
 //2
    //a=50,x=5,y=7,z=10
    int num2;
    int num3=50;//i.e a=50 (fixed meter charge)
    double num4;//total bill
    printf("Enter the Units Consumed :");
    scanf("%d",&num2);
    if (num2<=100 && num2>=0)
    {
        printf("Total bill is %.2lf. \n ",num4=(num2*5 +50));
    }
    else if ((num2>100) &&(num2<=200))
    {
        printf("Total bill is %.2lf. \n",num4=(num2*7 +50));
    }
    else if (num2>200) {
        printf("Total bill is %.2lf. \n",num4=(num2*10 +50));
    }

 //3
    int num5,num6,num7; 
    
    printf("Sides of triangle are : ");
    scanf("%d %d %d", &num5, &num6, &num7);
    if (((num5+num6)<=num7) || ((num6+num7)<=num5) || ((num7+num6)<=num5))
    {
       printf("This is not a triangle. \n");
       
       
    }
    
    else {
          if ((num5==num6) && (num6==num7) && (num5==num7))
          {
              printf("It is Equilateral triangle. \n");
          }
          else if ((num5!=num6) && (num6!=num7) && (num5!=num7))
          {
              printf("It is Scalene triangle. \n");
          }
          else if ((num5==num6) || (num6==num7) || (num5==num7))
          {
              printf("It is Isosceles triangle. \n");
          }
      

       //now 
       int max ,z,y;
       if( num5>=num6 && num5>=num7){ max=num5 , z=num6, y= num7 ;}
       if( num6>=num5 && num6>=num7){ max=num6 , z=num5, y= num7 ;}
       if( num7>=num5 && num7>=num6){ max=num7 , z=num5, y= num6 ;}

       if (((z*z)+(y*y)==(max*max)))
       {
           printf("Triangle is Right angled triangle. \n");
       }
       else if (((z*z)+(y*y)>>(max*max)))
       {
           printf("Triangle is acute angled triangle. \n");
       }
       else if (((z*z)+(y*y)<<(max*max)))
       {
           printf("Triangle is Obtuse angled triangle. \n");
       }}
       
      //4
           int num8, num9, num10;
         printf("Enter date in the form of dd mm yyyy : ");
         scanf("%d %d %d", &num8, &num9, &num10); 
     
         if ((num10 % 400 == 0) || ((num10 % 4 == 0) && (num10 % 100 != 0))) {
             
             if (num9==1 || num9==3 || num9==5 || num9==7 || num9==8 || num9==10) {  
                 if (num8 > 0 && num8 <= 30) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 31) {
                     printf("%d %d %d\n", 1, (num9+1), num10);   
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9==4 || num9==6 || num9==9 || num9==11) {  
                 if (num8 > 0 && num8 <= 29) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 30) {
                     printf("%d %d %d\n", 1, (num9+1), num10);
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9 == 12) {
                 if (num8 > 0 && num8 <= 30) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 31) {
                     printf("%d %d %d\n", 1, 1, (num10+1));
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9 == 2) {
                 if (num8 > 0 && num8 <= 28) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 29) {
                     printf("%d %d %d\n", 1, (num9+1), num10);  
                 } else {
                     printf("Invalid\n");
                 }
             }
             else {
                 printf("Invalid\n");
             }
         }
         else {
            if (num9==1 || num9==3 || num9==5 || num9==7 || num9==8 || num9==10) {  
                 if (num8 > 0 && num8 <= 30) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 31) {
                     printf("%d %d %d", 1, (num9+1), num10);   
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9==4 || num9==6 || num9==9 || num9==11) {  
                 if (num8 > 0 && num8 <= 29) {
                     printf("%d %d %d\n", (num8+1), num9, num10);
                 } else if (num8 == 30) {
                     printf("%d %d %d\n", 1, (num9+1), num10);
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9 == 12) {
                 if (num8 > 0 && num8 <= 30) {
                     printf("%d %d %d", (num8+1), num9, num10);
                 } else if (num8 == 31) {
                     printf("%d %d %d\n", 1, 1, (num10+1));
                 } else {
                     printf("Invalid\n");
                 }
             }
             else if (num9 == 2) {
                 if (num8 > 0 && num8 <= 27) {
                     printf("%d %d %d", (num8+1), num9, num10);
                 } else if (num8 == 28) {
                     printf("%d %d %d", 1, (num9+1), num10);  
                 } else {
                     printf("Invalid\n");
                 }
             }
             else {
                 printf("Invalid\n");
             }
         }
    //5
     
          
    int num11,num12; //num12 == conversion number
    double result1;

   printf("Enter your Value for conversion: ");
    scanf("%d",&num11);

    printf("1: km--> m \n");
    printf("2: Celcius--> fahrenhiet \n");
    printf("3: Kg-->m \n");
  
   
    printf("Conversion no. :- ");
    scanf("%d",&num12);
   
    switch (num12)
    {
    case 1:
      result1= 1000*num11;
      break;
    
    case 2:
      result1= (num11*9/5)+32;
      break;
    
    case 3:
      result1=1000*num11;
      break;
    
    
    default:
      printf("Invalid Option \n");
      break;
    }

   

if (num12==1)
{
   printf("%d km in m is :- %.2lf \n", num11,result1);
}


else if (num12==2)
{
   printf("%d Celcius in fahrenhiet is :- %.2lf \n", num11,result1);
}


else
{
   printf("%d kg in g is :- %.2lf \n", num11,result1);
}
  
//6
 
int num13,num14,num15;
int count=0;
int sum=0;
int product=1;

    printf("Enter any integer :- \n");
    scanf("%d",&num13);

     num15=num13;

    while(num15>0){
        num15/=10;
        count++;
    }
printf("NO. of digits :- %d\n", count );

     num15=num13;

    while(num15>0){
       sum= sum +( num15%10);
        num15=num15/10;

        
    }
printf("Sum of digits :- %d\n", sum );


    num15=num13;

    while(num15>0){

        if(num15%10!=0){
       product= product * ( num15%10);
        num15=num15/10;

        }

    }

    printf("product of digits :- %d\n", product );

    
    



//7
     
     int n, pattern_type;
    
    printf("Enter a number between 1 and 20: ");
    scanf("%d", &n);
    
    printf("Pattern numbers are:- \n");
    printf("2.entered Pyramid \n");
    printf("3.Hollow square \n");
    
    printf("Enter pattern type : ");
    scanf("%d", &pattern_type);
    

    if (n < 1 || n > 20) {
        printf("Invalid number! Must be between 1 and 20.\n");
    }
    
   
    else if (pattern_type == 1) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    
    else if (pattern_type == 2) {
        for (int i = 1; i <= n; i++) {
            
            for (int s = 1; s <= n - i; s++) {
                printf("  ");
            }
            
            for (int j = 1; j <= (2 * i - 1); j++) {
                printf("%d ", j);
            }
            printf("\n");
        }
    }
    
    else if (pattern_type == 3) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                
                if (i == 1 || i == n || j == 1 || j == n) {
                    printf("%d ", j);
                } else {
                    printf("  ");
                }
            }
            printf("\n");
        }
    }
    
    else {
        printf("Invalid pattern type\n");
    }
    

   


//9
      double x,ans;
     printf("Enter value of x for f(X) is : ");
     scanf("%lf", &x);
     if (x<0)
     {
        ans=((x*x)-(3*x)+2);
        printf("Value of F( %lf ) is %.3lf. \n",x,ans);
     }
     else if ((x>0) && (x<=10))
     {
        ans=((2*x)+5);
        printf("Value of F( %lf ) is %.3lf. \n",x,ans);
     }
    else {
         ans=(3*(x*x));
         printf("Value of F( %lf ) is %.3lf. \n",x,ans);
      }
   
   //10
       int a,b,operation;
       float result;
       printf("1: addition\n");
       printf("2: subtraction\n");
       printf("3: multiplication\n");
       printf("4: division\n");
       printf("5: Modulus\n");
       printf("6: Exponentiation\n");
      
       printf("Operation no. :- ");
       scanf("%d",&operation);
      
       printf("Enter your Values:- ");
       scanf("%d %d",&a,&b);
   
       switch (operation)
       {
       case 1:
         result=a+b;
         break;
       
       case 2:
         result=a-b;
         break;
       
       case 3:
         result=a*b;
         break;
       
       case 4:
         result=(float)a/b;
         break;
   
       case 5:
         result=a%b;
         break;
   
       case 6:
         result=pow(a,b);
         break;
       
       default:
         printf("Invalid Operation \n");
         break;
       }

      if (operation>=1 && operation<=6)
      {
         printf("\n Result is :- %.2f", result);
      }

    
     
return 0;
}