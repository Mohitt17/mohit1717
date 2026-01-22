#include<iostream>
#include<iomanip>

using namespace std;

 
int main() 
{
/* int = 0,1,2,3,4..
   Float = decimal(1.21,1.2)
   Char = c,d,e,f
   Double = 1.30304,...
   Bool = true / false , yes/no...
*/
/* COSTANTS= To not change values 
   const int a= ...
   used for that not change value of any const(by mistakes)
   that it doesn't change later 
*/
const int z=9;
/* Manipuliators 
               1. endl
               2. setw --uses in iomainp == (start #include<iomanip>)
*/
int a= 2 , b=103 ,c=1234;
cout<< "The Value of a is :" <<a <<endl ;
cout<< "The Value of b is :" <<b <<endl ;
cout<< "The Value of c is :" <<c <<endl ; 


cout<< "The Value of a is :" <<setw(4) <<a     <<endl;
cout<< "The Value of b is :" <<setw(4) <<b     <<endl;
cout<< "The Value of c is :" <<setw(4) <<c     <<endl;
/* setw(x) x gap deta hai */
 
/* Operator Precendence :-
  Reference = cpprefence.com website for precendence of operation
( ( a*5)+b)-877  // Top to bottom ,,left to right 
*/

cout<<"CONTROL STRUCTURES" <<endl;
/* Sequence Structure ,,Selection Structure ,, Loop Strcture --- Basic Control Sturcture
   1. Sequeunce--- Entry ---Action 1---Action 2---Exit
   2. Selection----Entry --Condition --True --A1
                                     --False-A2
   3.Loop -- Entry --loop --conditon --true -A1---again looop
                                     --False --A2--Exit


*/
/*IF ELSE STATEMENT
 int i=0
  if(i<3) {
           cout<<i;
           i++;
)
2. If else ladder
3.Switch Case 
         switch(experssion) {
         case 1:
         {action 1;}
         default:
         {action 2}
         }
*/
// IF Else ladder 

int age ;
cout<<"Tell me your age " <<endl;
cin>>age;
if(age<18) {
   cout<<"you cannot come to my party " <<endl;

}
else if (age==18){
   cout<<"You are kid and you will get a kid pass to the party" <<endl;
}
else if (age>90) {
   cout<<"You are dead" <<endl;
}

else {
   cout<<"You can come to the party " <<endl;
}
// SWITCH CASE STATEMENT 
switch (age)
{
   case 18:
      
      cout<<"You are 18" <<endl ;
      break;
   case 22:
      
      cout<<"You are 22"<<endl;
      break;
   
default:
cout<<"NO special cases"<<endl;
   break;
}




return 0;
}