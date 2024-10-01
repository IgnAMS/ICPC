#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;


ll f(ll x){
    ll X[] = {6, 8, 10};
    ll T[] = {15, 20, 25};
    ll ans = 1000000000000000000;  

    rep(i, 3) ans = min(ans, (x + X[i] - 1LL) / X[i] * T[i]);
    rep(i, 3) rep(j, 10) rep(k, 3){
        if((x + X[i] - 1LL) / X[i] - j >= 0 and ((x + X[i] - 1LL) / X[i] - j) * X[i] + X[k] * j >= x){
            ans = min(ans, ((x + X[i] - 1LL) / X[i] - j) * T[i] + j * T[k]);
            //cout<<(x + X[i] - 1LL) / X[i] - j<<' '<<j<<'\n';
        }
    }
    return ans; 
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    ll X[] = {6, 8, 10};
    ll T[] = {15, 20, 25};
    //cout<<f(196)<<'\n';
    while(t--){
        ll n; cin>>n;    
        ll ans = 1000000000000000000;  
        rep(i, 3) {
            ans = min(ans, (n + X[i] - 1LL) / X[i] * T[i]);
        }
        cout<<f(n)<<'\n';
    }




    return 0;
}