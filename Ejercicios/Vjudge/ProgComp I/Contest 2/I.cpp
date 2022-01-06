#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll intlog(ll x) { return ll(log10(x))+1; }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll w,m,k; cin>>w>>m>>k;
    ll i=0;
    ll ans=0;
    ll d=log10(m)+1;
    ll pot10=1; rep(i,d) pot10*=10;
    while(w - 1.0*k*d*(pot10-m)>=0){
        ans+=pot10-m;
        w-=k*d*(pot10-m);
        m=pot10;
        pot10*=10;
        d+=1;
    }

    ans += w/(d*k);
    cout<<ans<<"\n";
    

    return 0;
}