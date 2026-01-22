#include<stdio.h>
#include<math.h>

int main(){
 //1 
    int a;
    printf("Enter the number 1 ");
    scanf("%d",&a);
    printf("The number is %d \n",a);
 
//2
  
    int b = 10 , c = 9;
    int sum1 = b+c;
    
    printf("The sum of %d and %d is %d.\n",b,c,sum1);


//3 
    int d ;
    printf("The value for cube is ");
    scanf("%d",&d);
    int cube = (d*d*d);
    
    printf("the cube of number is %d\n",cube);

//4
int e=20,f=5;
    int sum=e+f, subt=e-f, multi=e*f, div=e/f;
    printf("Sum of %d and %d is %d. \n",e,f,sum);
    printf("Difference of %d and %d is %d. \n",e,f,subt);
    printf("Product of %d and %d is %d. \n",e,f,multi);
    printf("Divide of %d and %d is %d. \n",e,f,div);

//5

    int num1;
    printf("Enter the number : ");
    scanf("%d",&num1);
    if (a%2==0)
    {
        printf("The number %d is even.\n",num1);
    }
    else{
        printf("The number %d is odd.\n",num1);
    }

//6
    
  int num2,num3;
    printf("Enter the number 1 : ");
    scanf("%d",&num2);

    printf("Enter the number 2 : ");
    scanf("%d",&num3);
    
    if (num2>=num3)
    {
        printf("The larger number is %d.\n",num2);
    }
    else{
        printf("The larger number is %d.\n",num3);
    }

//7
    int num4, num5, num6;
    printf("Enter the value of numbers : ");
    scanf("%d",&num4);
    scanf("%d",&num5);
    scanf("%d",&num6);

    if ((num4>num5)&&(num4>num6))
    {
        printf("The largest number is %d .\n",num4);
    }
    else if ((num5>num4)&&(num5>num6))
    {
        printf("The largest number is %d .\n",num5);
    }
    else {
         printf("The largest number is %d .\n",num6);
    }
    
//8

    int year;

    
    printf("Enter a year: ");
    scanf("%d", &year);

   
    if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) {
        printf("%d is a leap year.\n", year);
    } else {
        printf("%d is not a leap year.\n", year);
    }

 

//9
  
    char character;
    printf("Enter the character : ") ;
    scanf("%c",&character);
    int ascii= character;
    printf("The ASCII code is %d.\n",ascii);

//10

    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        printf("The character is a Letter.\n");
    }
   
    else if (ch >= '0' && ch <= '9') {
        printf("The character is a Digit.\n");
    }
    
    else {
        printf("The character is Other.\n");
    }



//11
   
    int r;
    printf("The Radius is : ") ;
    scanf("%d",&r);

    double area=(3.14*r*r);
    double cirmcum=(2*3.14*r); 

    printf("Area of circle is %.2lf.\n",area);
    printf("Circumference of circle is %.2lf.\n",cirmcum);

//12

    double P, R, T;

    printf("Enter The values : ");

    scanf("%lf",&P);
    printf("Enter rate of interest :");
    scanf("%lf",&R);
    printf("Enter Time :");
    scanf("%lf",&T);

    
    double SI=(P*R*T/100) ;
    double  A = P * pow((1 + R / 100), T); 

    double CI= A-P;
     
    printf("simple Interest is %.2lf.\n",SI);
    printf("Compound Interest is %.2lf.\n",CI);

//13 is in last 


//14


     double num9;
     printf("Enter the value of temprature in fahrenheit = ");
     scanf("%lf", &num9);
     
     double num8 =((num9-32)*0.56);
     
     printf("value in celcius is %.2lf. \n",num8);



//15

    int num10, num11, num12;
    printf("Enter the values for average: ") ;
    scanf("%d",&num10);
    scanf("%d",&num11);
    scanf("%d",&num12);
    float average =((num10+num11+num12)/3);
    printf("Average of %d, %d and %d is %f. \n",num10,num11,num12,average);

   

//13

     int num7;
     
         printf("enter any number = ");
         scanf("%d",&num7);
         
         for(int i=2;i<num7;i++){
             if(num7%i==0){
                 printf("it's not an prime no.\n");
                 return 0;
            
             }
         }
     printf("its a prime no.\n");

 return 0;
        }