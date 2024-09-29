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

const int mxN = 1e5+5;
vl G[mxN]; // G[u] = [(v, index), (v, index)] where index is the index of the Edge
int V[mxN];

void dfs(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(V[v] == 0) dfs(v);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    vector<pll> Ans;
    dfs(0);
    rep(u, n) if(!V[u]) {
        dfs(u);
        Ans.pb({0, u});
    }
    cout<<Ans.size()<<'\n';
    for(auto [u, v]: Ans) cout<<u + 1<<' '<<v + 1<<'\n';
    
    return 0;
}