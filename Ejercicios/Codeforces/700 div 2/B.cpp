#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> pll;
#define ff first
#define ss second

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        ll a,b,n; cin>>a>>b>>n;
        vector<pair<ll,ll>> X(n);
        rep(i,n) cin>>X[i].ff;  rep(i,n) cin>>X[i].ss;
        sort(X.begin(),X.end());
        bool oc=1;
        rep(i,n){
            ll x= X[i].ss/a + (X[i].ss%a==0? 0:1); // ataques para matar
            b-=(x-1)*X[i].ff; //hago x-1 ataques
            //reviso si es que puedo matar al ultimo
            if(i==n-1 && b<1) oc=0;
            //hago el ultimo ataque
            b-=X[i].ff;
            //reviso si puedo matar a un monstruo normal
            if(b<=0 && i<n-1) oc=0;
        }
        if(oc) cout<<"YES\n";
        else cout<<"NO\n";
    }


    return 0;
}