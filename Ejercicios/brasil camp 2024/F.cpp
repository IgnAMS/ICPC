#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


const ll INF = 2e5 + 5;
vector<vl> G(200005, vl());
ll DP[INF][6];

ll dp(ll u, ll d, ll p) {
    if(DP[u][d] != -1) return DP[u][d];

    ll ans = (d >= 3 and G[u].size() == 1);
    for(auto v: G[u]) if(v != p) {
        if(d <= 2) ans += min(dp(v, d + 1, u), dp(v, 1, u) + 1);
        if(d == 3) ans += dp(v, 1, u) + 1;
    }
    // cout<<u<<' '<<d<<' '<<ans<<'\n';
    return DP[u][d] = ans;
}

ll dp2(ll u, ll d, ll p) {
    if(DP[u][d] != -1) return DP[u][d];
    
    DP[u][d] = 0;
    if(d == 4) {
        // creo una arista en mi mismo
        DP[u][d] += 1;
        for(auto v: G[u]) if(v != p) DP[u][d] += dp2(v, 2, u);
    }
    else {
        ll ans1 = 1;
        for(auto v: G[u]) if(v != p) ans1 += dp2(v, 2, u);

        ll ans2 = 0;
        for(auto v: G[u]) if(v != p) ans2 += dp2(v, d + 1, u);

        // creo una arista en mi mismo en caso contrario
        if(d == 3 and G[u].size() == 1) ans2++;
        DP[u][d] = min(ans1, ans2);
    }
    // cout<<u<<' '<<d<<' '<<DP[u][d]<<'\n';
    return DP[u][d];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    rep(i, n) rep(j, 6) DP[i][j] = -1;

    cout<<dp2(0, 0, -1)<<'\n';


    return 0;
}