#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        if(n==1) cout<<0<<"\n";
        else if(n==2) cout<<1<<"\n";
        else if(n==3) cout<<2<<"\n";
        else if(n%2==0) cout<<2<<"\n";
        else cout<<3<<"\n";
    }

    return 0;
}