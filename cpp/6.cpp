#include<iostream>
//#include<iomainp>

using namespace std;
int main (){
/*Loops in C++ :- 
                  1. For Loop
                  2. While loop
                  3. Do while Loop

*/

/*Syntax for FOR LOOP
 for (intalization;condition;updation)
 {
 loop body(C++ code);
 }
*/
for ( int i = 0; i <= 40; i++)
{
    cout<<i <<endl;
    
}
  
/* WHILE LOOP
  syntax:
  while(condition)
{
C++ statements;

}
*/
cout<<"Printing 1 to 10 using while loop" <<endl;
int a=1 ;
while(a<=10){
    cout<<a <<endl;
    a++;
}

/* Do while loop in C++
syntax:
do
{
c++ statements;
}
while (condtion);

*/
cout<<"Do While"<<endl;
int b=1;
do
{
  cout<<b<<endl;
  b++;
} while (b<=10);
cout<<"Assignement"<<endl;
int n;
int c;
cout<<"ENTER ANY NO.==";
cin>>n;
for(c=1;c<=10;c++){
    cout<<c*n;
      cout<<endl;}




return 0;
}