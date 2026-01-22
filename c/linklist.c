#include<stdio.h> 
#include<stdlib.h>

struct linklist
{
    int a;
    struct  linklist *b;

};

struct mystruct{
   int a;
   struct mystruct *b;
};

int main(){ 

    struct linklist x={10,NULL} , y = {20,NULL} , z = { 30, NULL};
    struct linklist *p7, *p8, *p9;
    p7 = &x;
    p8 = &y;
    p9 = &z;

    x.b = p8;
    y.b = p9;

    printf("%d %d \n", x.a,x.b);
    printf("%d %d \n", y.a,y.b);
    printf("%d %d \n", z.a,z.b);

    struct linklist *p4, *p5, *p6;

    p4 = (struct linklist *)malloc(sizeof(struct linklist));
    p5 = (struct linklist *)malloc(sizeof(struct linklist));
    p6 = (struct linklist *)malloc(sizeof(struct linklist));
     
    p4->a=40; p4->b=NULL;
    p5->a=50; p5->b=NULL;
    p6->a=60; p6->b=NULL;
 
    p4->b=p5;
    p5->b=p6;

    printf("\n%d %d \n", p4->a,p4->b);
    printf("%d %d \n", p5->a,p5->b);
    printf("%d %d \n", p6->a,p6->b);
    
    int n=1,m=0;
    enum status {OKAY, CANCEL};// OKAY=0,CANCEL=1; if okay=n , cnacel = n++;
    n = OKAY ;  //n=0 
    m = CANCEL;  //m=1
    printf("%d\n \n",CANCEL);

    struct mystruct *p1, *p2, *start;
   int i;

   p1 = (struct mystruct *)malloc(sizeof(struct mystruct));
   p1 -> a = 0; p1 -> b = NULL;

   start = p1;
   
   for(i = 1; i <= 5; i++){
      p2 = (struct mystruct *)malloc(sizeof(struct mystruct));
      //printf("Enter The %dth Value  :",i);
      //
     // scanf("%d",&(p2->a));   
       p2->a=i;
      p2 -> b = NULL;
      p1 -> b = p2;
      p1 = p2;
   }
   
   p1 = start;
   while(p1 != NULL){
      printf("Add of current address: %d \na: \t %d add of next address : %d\n", p1, p1 -> a, p1 -> b);
      p1 = p1 -> b;
   }


return 0;
}