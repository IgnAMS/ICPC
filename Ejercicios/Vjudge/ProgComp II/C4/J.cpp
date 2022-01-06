#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll l,p,v; 
    ll cas=0;
    while(cin>>l>>p>>v){
        if(l==0 && p==0 && v==0) break;
        cas++;
        ll x= v/p;
        ll ans= x*l;
        ans+= min((v-x*p),l);
        cout<<"Case "<<cas<<": "<<ans<<"\n";
    }

    return 0;
}