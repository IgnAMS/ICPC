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

ll DP[1<<20][21];
vl G[21];
const ll MOD = 1e9+7;
int n, m;

ll dp(int bm, int last) {
    if(bm == 0 and last == n - 1) return 1;
    if(bm == 0) return 0;
    if(DP[bm][last] != -1) return DP[bm][last];
    
    // cout<<bm<<' '<<last<<'\n';
    
    DP[bm][last] = 0;
    for(auto v: G[last]) if(bm & (1<<v)) {
        DP[bm][last] += dp(bm ^ (1<<v), v);
        if(DP[bm][last] >= MOD) DP[bm][last] -= MOD;
    }
    
    // cout<<bm<<' '<<last<<' '<<DP[bm][last]<<'\n';
    // for(auto v: G[last]) {
    //     if(bm & (1<<v)) cout<<"vecino: "<<(bm ^ (1<<v))<<' '<<v<<'\n';
    // }
    // cout<<'\n';

    return DP[bm][last];
} 

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        ll u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
    }

    rep(bm, 1<<n) rep(i, n) DP[bm][i] = -1;

    cout<<dp(((1<<n) - 1) ^ (1<<0), 0)<<'\n';
    return 0;
}