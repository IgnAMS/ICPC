#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int i = n;
        for(i=0; (1<<(i+1)) <= n && i < 30; i++);
        cout<<(1<<i)-1<<"\n";
    }

    return 0;
}