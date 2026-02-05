#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
     while (t--)
     {
        int n,x,k;
        cin>>n>>x>>k;

        if(x>k){
            if(x%k==0){
                cout<<0<<endl;
    
            }
            else cout<<x%k<<endl;
        }

        else if(x<k){
            if((n-x)%k!=0 && k-x!=0)
            cout<<max((n-x)%k,k-x)<<endl;
            else if((n-x)%k==0) cout<< k-x;
            else if((k-x)==0) cout<<(n-x)%k;
        }
     }
     
}