#include<iostream> 

using namespace std; 

   int sum(int a, int b){
   int c= a + b;
   return c;
   }

// This will not swap a and b
void swap(int a, int b){ 
  int temp = a;
  a = b;
  b= temp;}


// this will swap
// call by refernece using pointers
void swapPointer(int* a, int* b) { 
  int temp = *a;
  *a = *b;
  *b= temp;}

//   Call by reference using C++ reference Variables
void swapReferenceVar(int &a, int &b) {          //void swapPointer(int* a, int*b){
  int temp = a;                                  //int temp=*a;
  a = b;                                         // *a = *b;
  b= temp;                                       // *b = temp;}

}
int main(){ 
   int a=4, b=5;

// cout<<"The sum of  4 and 5 is "<<sum(4,5) ;
cout<<"the value of a is "<<a<<endl<<"the value of b is "<<b<<endl;

// swap(a, b); not swap
// swapPointer(&a, &b); this will swap a and b using pointer reference
swapReferenceVar(a, b); //this will swap a and b using reference variables
cout<<"the value of a is "<<a<<endl<<"the value of b is "<<b<<endl;
 


return 0;
}