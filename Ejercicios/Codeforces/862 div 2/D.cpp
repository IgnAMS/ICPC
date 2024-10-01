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

vl G[100005];
ll D[100005];
void dfs(ll u, ll d, ll p) {
    D[u] = d; 
    for(auto v: G[u]) if(v != p) dfs(v, d + 1, u);
}

set<ll> Hojas;


struct DSU {
    vl p; DSU(int N) : p(N, -1) {}
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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // Quiero saber cuales nodos son los extremos
    int n; cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    dfs(0, 0, -1);
    ll mxu = 0;
    rep(u, n) if(D[mxu] < D[u]) mxu = u;
    
    // Consigo las hojas del diametro :)
    dfs(mxu, 0, -1);
    ll prev = mxu;
    ll mxdist = 0;
    vector<set<ll>> S(n, set<ll>());
    rep(u, n) {
        if(D[mxu] < D[u]) mxu = u, mxdist = D[u], Hojas.clear();
        if(D[mxu] == D[u]) Hojas.insert(u);
        S[D[u]].insert(u);
    }
    dfs(*Hojas.begin(), 0, - 1);
    rep(u, n) {
        if(D[u] == mxdist) Hojas.insert(u);
        S[D[u]].insert(u);
    }
    // rep(d, n) {
    //     cout<<"nodos del tiempo "<<d<<'\n';
    //     for(auto u: S[d]) cout<<u<<' '; cout<<'\n';
    // }
    // cout<<prev<<'\n';
    // cout<<"Hojas:\n";
    // for(auto u: Hojas) cout<<u<<" "; cout<<'\n';


    // Calculo la respuesta
    ll Ans[n]; 
    DSU dsu(n);
    ll components = n;
    for(int i = n - 1; i >= mxdist; i--) Ans[i] = components;
    for(int i = mxdist - 1; i >= 0; i--) {
        // cout<<"estoy en el tiempo "<<i<<'\n';
        for(auto u: S[i + 1]) {
            if(!dsu.sameSet(u, prev)) {
                dsu.unite(u, prev);
                components--;
            }
        }
        Ans[i] = components;
    }
    for(auto u: Ans) cout<<u<<' '; cout<<'\n';

    return 0;
}