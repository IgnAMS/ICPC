#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 FixedLengthPathII2.cpp && time ./a.out <input.txt> output.txt
 
const int mxN = 2e5 + 5;
vi G[mxN];
int removed[mxN], sz[mxN];
 
ll ans = 0, n, k1, k2;
 
struct ST { 
    // vi T = vi(4 * mxN, 0);
    int T[4 * mxN];
    void upd(int ind, int x, int l = 0, int r = mxN, int u = 0) {
        if(l == r) {
            T[u] += x;
            return;
        }
 
        int m = (l + r) / 2;
        if(ind <= m) upd(ind, x, l, m, 2 * u + 1);
        else upd(ind, x, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
    }
    int query(int i, int j, int l = 0, int r = mxN, int u = 0) {
        if(l > j or i > r) return 0;
        if(i <= l and r <= j) return T[u];
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
} st;
 
 
int calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}
 
int ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}
 
void dfs_sz(int u, int p, int d, vi& currdist) {
    currdist.pb(d);
    // cout<<"entre en "<<u<<" con dist "<<d<<" hago la query de "<<k1 - d<<", "<<k2 - d<<'\n';
    // cout<<st.query(k1 - d, k2 - d)<<'\n';
    ans += st.query(k1 - d, k2 - d);
 
    for(auto v: G[u]) if(v != p and !removed[v]) dfs_sz(v, u, d + 1, currdist);
}
 
 
void build(int u = 0) {
    int centroid = ctroid(u, calcsz(u));
    // cout<<"el centroide es "<<centroid<<'\n';
 
    // Obtengo las distancias y obtengo la respuesta
    vi CurrDist, AccDist;
    for(auto v: G[centroid]) if(!removed[v]) {
        CurrDist.clear();
        // rep(i, n) cout<<st.query(i, i)<<' '; cout<<'\n';
        dfs_sz(v, centroid, 1, CurrDist);
        for(auto d: CurrDist) {
            AccDist.pb(d);
            st.upd(d, 1);
        }
    }
 
    for(auto d: AccDist) st.upd(d, -1);
 
    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}
 
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k1>>k2;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    st.upd(0, 1);
    
    build();
 
    cout<<ans<<'\n';
 
    return 0;
}