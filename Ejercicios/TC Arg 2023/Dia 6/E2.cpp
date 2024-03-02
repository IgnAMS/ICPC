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

const int mxN = 1e5+5;
ll Ans[mxN];

struct DSU {
    vl p, A; 
    // Q = {valor, id}
    vector<set<pll>> Q;
    // vector<set<ll>> G;
    DSU(int N, vl &A, vector<set<pll>> &Q): p(N, -1), A(A), Q(Q) {}
    int get(int x) { return p[x] < 0? x: p[x] = get(p[x]); }
    bool same(int x, int v) { return get(x) == get(v); }
    int size(int x) { return -p[get(x)]; }
    void unite(ll x, ll y, ll v) {
        if((x = get(x)) == (y = get(y))) return;
        if(p[x] > p[y]) swap(x, y);

        // Saco lo que corresponde y guardo las respuestas
        while(!Q[x].empty() and Q[x].begin()->ff + A[x] < v) {
            Ans[Q[x].begin()->ss] = A[x] + Q[x].begin()->ff;
            Q[x].erase(Q[x].begin());
        }
        while(!Q[y].empty() and Q[y].begin()->ff + A[y] < v) {
            Ans[Q[y].begin()->ss] = A[y] + Q[y].begin()->ff;
            Q[y].erase(Q[y].begin());
        }

        // Cambio los punteros y actualizo los nuevos nodos
        if(Q[y].size() > Q[x].size()) swap(Q[y], Q[x]);
        for(auto u: Q[y]) Q[x].insert(u);
        
        A[x] += A[y], p[x] += p[y], p[y] = x;
    }
};




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, q; cin>>n>>m>>q;
    vl A(n); rep(i, n) cin>>A[i];
    vector<vl> E;

    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        E.pb({w, u, v});
    }
    sort(E.begin(), E.end());

    vector<set<pll>> Q(n, set<pll>());
    rep(i, q) {
        ll x, k; cin>>x>>k; x--;
        Q[x].insert({k, i});
    }
    
    DSU dsu(n, A, Q);
    for(auto e: E) dsu.unite(e[1], e[2], e[0]);
    rep(i, n) {
        auto &val = dsu.A[dsu.get(i)];
        auto &queries = dsu.Q[dsu.get(i)];
        while(!queries.empty()) {
            Ans[queries.begin()->ss] = queries.begin()->ff + val;
            queries.erase(queries.begin());
        }
    }


    rep(i, q) cout<<Ans[i]<<'\n';


    return 0;
}