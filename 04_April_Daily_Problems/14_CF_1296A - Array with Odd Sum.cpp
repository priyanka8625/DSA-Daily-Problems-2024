#include<bits/stdc++.h>
using namespace std;

int main(){
    int sum=0, t, n, ele;
    for(cin>>t; t; t--){
        cin>>n;
        sum=0;
        bool odd=false, even=false;
        for(int i=0; i<n; i++){
            cin>>ele;
            sum += ele;
            if(ele&1)
                odd = true;
            else
                even = true;
        }
        if(sum&1 || (odd && even))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}