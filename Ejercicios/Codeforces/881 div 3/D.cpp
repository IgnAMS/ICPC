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
vl G[mxN];
ll DP[mxN], P[mxN];

void dfs(ll u, ll p) {
    P[u] = p;
    for(auto v: G[u]) if(v != p) dfs(v, u);
}

ll dp(ll u) {
    if(DP[u] != -1) return DP[u];
    if(G[u].size() == 1 and u != 0) return 1;

    DP[u] = 0;    
    for(auto v: G[u]) if(v != P[u]) {
        DP[u] += dp(v);
    }
    return DP[u];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        rep(u, n) {
            DP[u] = -1;
            G[u].clear();
        }

        rep(i, n - 1) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].pb(v); G[v].pb(u);
        }
        dfs(0, - 1);


        int q; cin>>q;
        while(q--) {
            int a, b; cin>>a>>b; a--, b--;
            ll left = dp(a), right = dp(b);
            cout<<left * right<<'\n';
        }
    }


    return 0;
}