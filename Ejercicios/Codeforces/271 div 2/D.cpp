#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


ll t, k, n;
const ll MOD = 1e9+7;

ll DP[100005];
ll dp(ll x) {
    if(x == 0) return 1;
    if(DP[x] != -1) return DP[x];
    
    DP[x] = 0;
    DP[x] += dp(x - 1);
    if(x >= k) DP[x] += dp(x - k);
    while(DP[x] >= MOD) DP[x] -= MOD;

    return DP[x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>t>>k;
    memset(DP, -1, sizeof(DP));
    ll Acc[100002];
    Acc[0] = 0;
    repx(i, 1, 100001) {
        Acc[i] = Acc[i - 1] + dp(i);
        while(Acc[i] >= MOD) Acc[i] -= MOD;
    }
    while(t--) {
        ll a, b; cin>>a>>b;
        ll ans = Acc[b] - Acc[a - 1] + MOD;
        while(ans >= MOD) ans -= MOD;
        cout<<ans<<'\n';
    }


    return 0;
}