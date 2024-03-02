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


const int mxN = 1e5+5;
ll N[mxN], C[mxN];
ll Cost[mxN], DP[mxN];
vector<pll> G[mxN];

set<ll> F;
ll mx = 0;
bool dfs(ll u, ll cost) {
    bool ans = 0;
    for(auto e: G[u]) {
        ll v = e.ff, w = e.ss;
        if(dfs(v, cost + w)) {
            ans = 1;
        }
        else if(F.count(v)) {
            ans = 1;
            mx = max(mx, cost + w);
        }
    }
    cerr<<u<<' '<<mx<<'\n';
    return ans;
}


ll dp(ll u) {
    ll n = 0, curr = 0;
    DP[u] = 0, Cost[u] = 0;
    for(auto e: G[u]) {
        ll v = e.ff, w = e.ss;
        if(dp(v) != 0 or Cost[v] != 0) {
            n++;
            curr += Cost[v] + w;
            // mx = max(mx, Cost[v] + w);
            DP[u] += DP[v];
        }
        else if(F.count(v)) {
            n++;
            curr += w;
            // mx = max(mx, w);
            DP[u] += DP[v];
        }
    }
    if(n > 1) {
        DP[u] += curr;
        Cost[u] = 0;
    }
    else if(n == 1) Cost[u] = curr;

    if(u == 0 and n == 1) DP[u] += curr;

    // cerr<<u<<' '<<DP[u]<<' '<<Cost[u]<<' '<<n<<' '<<curr<<'\n';
    return DP[u];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, f; cin>>n>>f;
    rep(i, n - 1) {
        ll u, v, w; 
        cin>>u>>v>>w; 
        u--, v--;
        G[u].pb({v, w});
    }
    rep(i, f) {
        int x; cin>>x; x--;
        F.insert(x);
    }

    dfs(0, 0);
    // cout<<dp(0)<<' '<<mx<<'\n';
    cout<<dp(0) - mx<<'\n';

    return 0;
}