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

const int mxN = 1e2+5;
vl G[mxN], G2[mxN];

// DP[i][j] = number of roads from i to n - 1 without the node x
ll DP[mxN][mxN];

int n, m;
ll dfs(int u, int x) {
    if(DP[u][x] != -1) return DP[u][x];
    if(u == x) return DP[u][x] = 0;
    if(u == n - 1) return DP[u][x] = 1;

    DP[u][x] = 0;
    for(auto v: G2[u]) DP[u][x] += dfs(v, x);
    return DP[u][x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    
    ll D[n];
    rep(i, n) D[i] = 1e10;
    queue<ll> q; q.push(0);
    D[0] = 0;
    
    
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(int v: G[u]) if(D[v] > D[u] + 1) {
            q.push(v);
            D[v] = D[u] + 1;
        }
    }

    ll inQ[n]; rep(i, n) inQ[i] = 0;
    q.push(n - 1);

    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v: G[u]) {
            if(D[u] == D[v] + 1 and !inQ[v]) {
                inQ[v] = 1;
                q.push(v);
            }
            if(D[u] == D[v] + 1) {
                G2[v].pb(u);
            }
        } 
    }

    rep(i, n) rep(x, n + 1) DP[i][x] = -1;
    
    ll total = dfs(0, n);
    ll ans = total;
    repx(i, 1, n - 1) {
        ans = max(ans, 2 * (total - dfs(0, i)));
    }
    // cout<<ans<<'\n';
    
    cout<<setprecision(10)<<fixed<<db(ans) / db(total)<<'\n';

    return 0;
}