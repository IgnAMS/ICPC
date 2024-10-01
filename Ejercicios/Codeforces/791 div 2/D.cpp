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
ll DP[mxN], A[mxN];
vl G[mxN];
ll INF = 1e18+5;

ll dp(ll u, ll x) {
    // Si encuentra a un u que no ha terminado de procesar 
    // entonces DP[u] = INF

    if(DP[u] != -1) return DP[u];

    DP[u] = INF;
    ll ans = 1;
    for(auto v: G[u]) if(A[v] <= x) {
        ll val = dp(v, x);

        // Encontre un ciclo
        if(val == INF) ans = INF;
        else ans = max(ans, val + 1);
    }
    return DP[u] = ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin>>n>>m>>k;
    rep(i, n) cin>>A[i];

    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
    }

    ll l = 0, r = INF;
    while(l < r) {
        rep(u, n) DP[u] = -1;
        ll m = (l + r) / 2;
        ll curr = 0;

        // cout<<"pruebo "<<m<<'\n';
        rep(u, n) if(A[u] <= m) {
            curr = max(curr, dp(u, m));
            // cout<<dp(u, m)<<' ';
        }
        cout<<'\n';
        if(curr >= k) r = m;
        else l = m + 1;
    }
    if(l == INF) cout<<"-1\n";
    else cout<<l<<'\n';

    return 0;
}