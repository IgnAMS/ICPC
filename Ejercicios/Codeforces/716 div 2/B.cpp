#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

ll mod=1000000000+7;

ll m(ll x) { return (x%mod+mod)%mod; }

int main(){hola 
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll ans=1;
        rep(i,k) ans=m(ans*n);
        cout<<ans<<"\n";
    }


    return 0;
}