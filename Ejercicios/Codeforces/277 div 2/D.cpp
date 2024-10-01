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

const int mxN = 2e3+5;
ll A[mxN], V[mxN], DP[mxN];
vl G[mxN];
ll MOD = 1e9+7;
ll n, d;

ll dfs(int u, int r) {
    V[u] = 1;
    DP[u] = 1;
    for(auto v: G[u]) if(!V[v]) {
        if(A[r] < A[v] and A[v] <= A[r] + d) {
            dfs(v, r);
            DP[u] = (DP[u] * (DP[v] + 1)) % MOD;
        }
        if(A[r] == A[v] and r < v) {
            dfs(v, r);
            DP[u] = (DP[u] * (DP[v] + 1)) % MOD;
        }
    }
    return DP[u];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>d>>n;
    rep(i, n) cin>>A[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    ll ans = 0;
    rep(u, n) {
        memset(DP, 0, sizeof(DP));
        memset(V, 0, sizeof(V));
        ans += dfs(u, u);
        ans %= MOD;
    }
    cout<<ans<<'\n';

    return 0;
}