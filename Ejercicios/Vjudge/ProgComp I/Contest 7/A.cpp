#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repx(i,a,b) for(ll i=a;i<b;i++)


ll DP[505][505];

ll dp(ll n, ll h){
    if(n == 0) return 1; 
    if(h > n) return 0;
    if(DP[n][h] != -1) return DP[n][h];
    
    return DP[n][h] = dp(n, h+1) + dp(n-h, h+1);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;
    ll ans = 0;
    memset(DP, -1, sizeof DP);

    repx(h, 1, n - 1){
        ans += dp(n - h, h + 1);
    }
    cout<<ans<<"\n";

    return 0;
}