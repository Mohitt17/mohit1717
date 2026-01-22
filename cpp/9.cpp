#include<iostream> 

using namespace std; 

//Function Prototype
// types function - name (arguments);
//int sum(int a,int b); --->acceptable
//int sum(int a,b); --->Not acceptable
//int sum(int ,int); ---> acceptable
void g(void);
void g(){
        cout<<"\n Hello, good morning ";
    }

int sum(int a, int b) {
int c= a+b;
return c;

}

int main(){ 
    int num1, num2;
    cout<<"Enter first number "<<endl;
    cin>>num1;
    cout<<"Enter second number "<<endl;
    cin>>num2;
   cout<<"the sum is "<<sum(num1, num2)<<endl;
// num1 and num2 are actual paramters 
// a and b will be taking values from actual parameters num1 and num2
g();
   
  

return 0;
}
 