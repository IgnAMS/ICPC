#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct DSU
{
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};


vector<vi> G;
vi S;
void dfs(int u, int d, vi& D) {
    S.push_back(u);
    D[u] = d;
    for(auto v: G[u]) if(D[v] == -1) dfs(v, d + 1, D);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    DSU dsu(n);
    
    G.assign(n, vi());
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
        dsu.unite(u, v);
    }
    
    vi D(n, -1);
    vi D2(n, -1);
    vi Diam(n, 1);
    rep(i, n) if(D[i] == -1){
        dfs(i, 0, D);
        ll mxind = i;
        for(auto u: S) if(D[mxind] < D[u]) mxind = u;

        dfs(mxind, 0, D2);
        for(auto u: S) if(D2[mxind] < D2[u]) mxind = u;
        Diam[dsu.get(i)] = D2[mxind];
        S.clear();
    }

    while(q--) {
        int op; cin>>op;
        if(op == 1) {
            int u; cin>>u; u--;
            u = dsu.get(u);
            cout<<Diam[u]<<'\n';
        }
        else {
            int u, v; cin>>u>>v; u--, v--;
            u = dsu.get(u), v = dsu.get(v);
            if(u == v) continue;
            ll x = (Diam[v] + 1) / 2 + (Diam[u] + 1) / 2 + 1;
            dsu.unite(u, v);
            Diam[dsu.get(u)] = max({Diam[u], Diam[v], x});
        }
    }

    return 0;
}