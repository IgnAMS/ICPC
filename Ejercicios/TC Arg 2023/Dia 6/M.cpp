#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 4e5+5;
ll D[mxN], L[mxN];
vector<vl> G;
vector<vl> G2;
vector<pll> S; 
vl Val;

void dfs(int u, int p, int d) {
    // cerr<<"entre con "<<u<<' '<<p<<'\n';
    D[u] = L[u] = d;
    for(auto v: G[u]) if(v != p) {
        if(D[v] == -1) {
            S.pb({u, v});
            dfs(v, u, d+1); 
            // Cut Edge
            if(L[v] > D[u]) {
                // cout<<"conecto los nodos "<<u<<' '<<v<<'\n';
                G2[u].pb(v);
                G2[v].pb(u);
            }
            // Componente biconexa
            if(p == -1 or L[v] >= d) {
                int nodocb = G2.size();
                G2.pb(vl());
                set<ll> nodos;
                int cont = 0;
                while(1) {
                    pll e = S.back(); S.pop_back();
                    cont++;
                    if(e == pll(u, v)) break;
                    nodos.insert(e.ff); nodos.insert(e.ss);
                }
                for(auto k: nodos) G2[nodocb].pb(k), G2[k].pb(nodocb);
                Val.pb(cont);
            }
            L[u] = min(L[u], L[v]);

        }
        else if(D[v] < d) {
            S.pb({u,v});
            L[u] = min(L[u], D[v]);
        }
    }

}


struct LCA {
    vector<vl> G3;
    int N, LOG;
    vector<vl> A;
    vl Acc, V, D2;
    LCA(vector<vl> &G, vl &V, int N, int root) : G3(G), N(N), V(V) {
        LOG = 31 -  __builtin_clz(N);
        D2.assign(N, -1); A.assign(N, vl(LOG + 1)); Acc.assign(N, 0);
        dfs2(root, -1, 0);
        repx(l, 1, LOG + 1) rep(u, N) {
            int a = A[u][l - 1];
            A[u][l] = (a == -1? -1: A[a][l-1]);
        }
    }
    void dfs2(int u, int p, int d) {
        A[u][0] = p, D2[u] = d;
        Acc[u] = (p == -1? 0: Acc[p]) + V[u];
        for(int v: G3[u]) if(D2[v] == -1) dfs2(v, u, d+1);
    }
    int raise(int u, int k) {
        for(int l = 0; k; l++, k >>= 1) if(k & 1) u = A[u][l];
        return u;
    }

    int lca(int u, int v) {
        if(D2[u] < D2[v]) swap(u, v);
        u = raise(u, D2[u] - D2[v]);
        if(u == v) return u;
        for(int l = LOG; l >= 0; l--) if(A[u][l] != A[v][l]) {
            u = A[u][l], v = A[v][l];
        }
        return A[u][0];
    }
    ll distancia(int u, int v) {
        return Acc[u] + Acc[v] - 2 * Acc[lca(u, v)] + V[lca(u, v)]; 
    }
};






int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    memset(D, -1, sizeof(D));
    memset(L, -1, sizeof(L));
    
    int n, m; cin>>n>>m;
    G.assign(n, vector<ll>()); 
    G2.assign(n, vector<ll>()); 
    Val.assign(n, 0);
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    dfs(0, -1, 0);

    // rep(u, G2.size()) {
    //     for(auto v: G2[u]) cout<<u<<' '<<v<<'\n';
    // }
    // for(auto u: Val) cout<<u<<' '; cout<<'\n';

    LCA lca(G2, Val, G2.size(), 0);
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v; u--, v--;
        cout<<lca.distancia(u, v)<<'\n';
    }

    return 0;
}