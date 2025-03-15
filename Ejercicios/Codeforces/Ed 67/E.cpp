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

const int mxN = 2e5+5;

ll sz[mxN];
ll dp[mxN];
vl G[mxN];
int n; 

void calc(int u = 0, int p = -1) {
    sz[u] = 1;
    dp[u] = 0;
    for(auto v: G[u]) if(v != p) {
        calc(v, u);
        dp[u] += dp[v];
        sz[u] += sz[v];
    }
    dp[u] += sz[u];
}


ll ans = 0;
void reroot(int u = 0, int p = -1) {
    // cout<<"Estoy en "<<u<<'\n';
    // rep(i, n) cout<<sz[i]<<' '; cout<<'\n';
    // rep(i, n) cout<<dp[i]<<' '; cout<<'\n';
    // cout<<'\n';
    ans = max(ans, dp[u]);
    for(auto v: G[u]) if(v != p) {
        dp[u] -= dp[v] + sz[v];
        sz[u] -= sz[v];
        dp[v] += dp[u] + sz[u];
        sz[v] += sz[u];

        reroot(v, u);

        dp[v] -= dp[u] + sz[u];
        sz[v] -= sz[u];
        dp[u] += dp[v] + sz[v];
        sz[u] += sz[v];
    }
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    calc();
    reroot();
    cout<<ans<<'\n';


    return 0;
}