#include<iostream> 

using namespace std; 

int main(){ 
/* ARRAY  

*/
     int marks[4]={23,34,56,67} ;
     cout<<marks[0] <<endl;
     cout<<marks[1] <<endl;
     //you can change marks 
     marks[2]=39  ;
     cout<<marks[2] <<endl;
     cout<<marks[3] <<endl;

     for (int i = 0; i < 4; i++)
     {
        cout<<"the value of marks "<<i<<" is "<<marks[i]<<endl;
     
     }
     //DO While loop karna hai abh

     //Pointer and arrays
     int*p =marks;
     cout<<"The value of *p is "<<*p    <<endl;
     cout<<"The value of *(p+1) is "<<*(p+1)<<endl;
     cout<<"The value of *(p+2) is "<<*(p+2)<<endl;
     cout<<"The value of *(p+3) is "<<*(p+3)<<endl;

cout<<"STRUCTURE"<<endl;
//Structure
struct employee
{
    int eID;
    char favchar;
    float salary;

};
struct employee harry;
harry.eID=1;
harry.favchar='c';
harry.salary=10;
cout<<"harry's salary "<<harry.salary<<endl;
cout<<"harry's ID "<<harry.eID<<endl;
cout<<"harry's favchar "<<harry.favchar<<endl;

/*typedef struct employee
{
    int eID;
    char favchar;
    float salary;
}ep;

int main(){
    ep harry;
    harry.eID=2;
    .....
}

*/

cout<<"UNION"<<endl;
//union ..only use one data type at one time
union money
{
    int rice;
    char car;
    float pounds; 
};

cout<<"ENUM"<<endl;
//ENUM
enum Meal{breakfast,lunch,dinner};
Meal m1=breakfast;
cout<<m1<<endl;
cout<<breakfast<<endl;
cout<<lunch<<endl;
cout<<dinner<<endl;




return 0;
}