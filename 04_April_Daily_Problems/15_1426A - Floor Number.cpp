#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;
    for(cin>>t; t; t--){
        cin>>n>>x;
        if(n<=2)
            cout<<"1"<<endl;
        else{
            cout<<((n-3)/x)+2<<endl;
        }
    }
    return 0;
}