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
ll V[mxN], B[mxN];
vector<array<int, 3>> G[mxN];

bool bipartite(ll u, bool dir) {
    B[u] = dir;
    for(auto [v, ind, type]: G[u]) {
        if(B[v] == B[u]) return 1;
        if(B[v] == -1 and bipartite(v, !dir)) return 1;
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, n) B[i] = -1;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb({v, i, 0}); G[v].pb({u, i, 1});
    }

    bool bipart = bipartite(0, 0);
    if(bipart) cout<<"NO\n";
    else {
        cout<<"YES\n";
        vl Ans(m, 0);
        rep(u, n) if(B[u]) {
            for(auto [v, ind, type]: G[u]) if(type == 1) {
                Ans[ind] = 1;
            }
        }
        rep(i, m) cout<<Ans[i]; cout<<'\n';
    }

    return 0;
}