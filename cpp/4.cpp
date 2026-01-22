#include<iostream>

using namespace std;

int main()
{
    int num1 ,num2;
    int num3 ,num4;
    //int num5 ,num6;
    //int num7 ,num8;
    
    
    cout<< "Enter the value of num1: "; /* '<<'this is called insertion operator*/
    cin>>num1;  /* '>>' this is extraction operator*/
    cout<< "Enter the value of num2: "; /* '<<'this is called insertion operator*/
    cin>>num2;  /* '>>' this is extraction operator*/ 

    cout<< "Enter the value of num3: "; /* '<<'this is called insertion operator*/
    cin>>num3;  /* '>>' this is extraction operator*/
    cout<< "Enter the value of num4: "; /* '<<'this is called insertion operator*/
    cin>>num4;  /* '>>' this is extraction operator*/  
    
    //cout<< "Enter the value of num5: \n"; /* '<<'this is called insertion operator*/
    //cin>>num5;  /* '>>' this is extraction operator*/
    //cout<< "Enter the value of num6: \n"; /* '<<'this is called insertion operator*/
    //cin>>num6;  /* '>>' this is extraction operator*/ 
    
    //cout<< "Enter the value of num7: \n"; /* '<<'this is called insertion operator*/
    //cin>>num7;  /* '>>' this is extraction operator*/
    //cout<< "Enter the value of num8: \n"; /* '<<'this is called insertion operator*/
    //cin>>num8;  /* '>>' this is extraction operator*/ 

    
    int a= num1, b=num2;
    int c= num3, d=num4;
    
    cout<< "The Arthematic Operations  are :" <<endl;
    cout<< "The Sum is " << num1+num2  <<endl;
    cout<< "The difference is " << num1-num2  <<endl;
    cout<< "a++ is " << num1++  <<endl;
    cout<< "a-- is " <<num1--  <<endl;
    cout<< "--a is " <<--num1  <<endl;
    cout<< "++a is " <<++num1  <<endl;

    //cout<< "THE COMAPRISON OPERATORS ARE FOLLOWING: " <<endl;
    //cout<< "Equality Operation  " <<(a==b)<<endl;
    //cout<< "Greater than Operation  " <<(a>b)<<endl;
    //cout<< "Less than Operation  " <<(a<b)<<endl;
    
   // cout<<"THE LOGICAL OPERATION ARE FOLLOWING " <<endl;
   // cout<<"  And Operation  " <<(a==b)&&(a<b) ; 
   // cout<<" Or Operation  " <<(a==b)||(a<b) ;
   // cout<<"  Not Operation  " <<(!(a==b)) <<endl;

 
   return 0 ;
}