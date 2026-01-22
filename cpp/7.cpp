#include<iostream> 

using namespace std; 

int main(){ 
cout<<"break cout ke baad meh"<<endl;
for (int i = 0; i < 4; i++)
{
    cout<<i<<endl;
    if (i==2)
    {
        break;
    }
    
}
  cout<<"Break cout seh phle"<<endl;   
for (int i = 0; i < 4; i++)
{
    
    if (i==2)
    {
        break;
    }
    cout<<i<<endl;
}
     
//CONTINUE
for (int a = 0; a < 4; a++)
{
    cout<<a<<endl;
    if (a==2)
    {
        continue;//no effect
    }
}
for (int a = 0; a < 4; a++)
{
    
    if (a==2)
    {
        continue;
    }
    cout<<a<<endl;
}
cout<<"The Poniter"<<endl;
/*What is pointer::
                   data type which holds the address of other data types

*/
int d=3;
int* b= &d ;

// &--->address of operator
// *--->Dereference operator

cout<<"The address of d(&d) is "<<&d<<endl;
cout<<"The address of d is "<<b<<endl;

cout<<"the value at address of b is "<<*b<<endl;

//pointer to pointer <<<error aa rha hai
// int** c= &b ;
// cout<<"the address of b is"<<c<<endl;
// cout<<"the address of b(&b) is"<<&b<<endl;
// cout<<"The value at address c is "<<*c<<endl;
// cout<<"The value at address  value_at(value_at(c)) c is "<<**c<<endl;

 

return 0;
}