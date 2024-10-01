#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;


int main(){
    int t; cin>>t;
    while(t--){
        ll n,m,x; cin>>n>>m>>x;
        ll j = x/n+1-(x%n==0);
        ll i = x-(j-1)*n;
        //cout<<i<<" "<<j<<"\n";
        cout<<(i-1)*m+j<<"\n";
    }




}