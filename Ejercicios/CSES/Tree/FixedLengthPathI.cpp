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
 
const int mxN = 2e5 + 5;
vl G[mxN];
ll removed[mxN], sz[mxN];
 
ll ans = 0, n, k;
ll Acc[mxN];
 
ll calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}
 
ll ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}
 
void dfs_sz(int u, int p, int d, vl& currdist) {
    currdist.pb(d);
    if(k - d >= 0) ans += Acc[k - d];
    for(auto v: G[u]) if(v != p and !removed[v]) dfs_sz(v, u, d + 1, currdist);
}
 
 
void build(int u = 0) {
    int centroid = ctroid(u, calcsz(u));
 
    // Obtengo las distancias y obtengo la respuesta
    vl CurrDist, AccDist;
    Acc[0] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        CurrDist.clear();
        dfs_sz(v, centroid, 1, CurrDist);
        for(auto d: CurrDist) {
            AccDist.pb(d);
            Acc[d]++;
        }
    }
    for(auto d: AccDist) Acc[d]--;
 
    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    build();
 
    cout<<ans<<'\n';
 
    return 0;
}