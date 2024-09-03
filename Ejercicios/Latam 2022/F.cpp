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


ll DP[101][101];
vl G1[101], G2[101];

class Dinic {
    struct Edge { int to, rev; ll f, c; };
    int n, t_; vector<vector<Edge>> G;
    vl D; vector<int> q, W;
    bool bfs(int s, int t){
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while (f < l){
            int u = q[f++];
            for (const Edge &e : G[u]) if (D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f){
        if (u == t_) return f;
        for (int &i = W[u]; i < (int)G[u].size(); ++i){
            Edge &e = G[u][i]; int v = e.to;
            if (e.c <= e.f || D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if (df > 0) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }

public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap){
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size() - 1, 0, 0}); // cap if bidirectional
    }
    ll maxFlow(int s, int t){
        t_ = t; ll ans = 0;
        while (bfs(s, t)) while (ll dl = dfs(s, LLONG_MAX)) ans += dl;
        return ans;
    }
};


ll dp(ll u1, ll u2, ll p1, ll p2) {
    if(DP[u1][u2] != -1) return DP[u1][u2];
    DP[u1][u2] = 0;

    // Caso de ser una hoja
    if(G2[u2].size() == 1 and p1 != -1) return DP[u1][u2] = 1;
    if(G2[u2].size() == 0 and p1 == -1) return DP[u1][u2] = 1;

    // Pongo los id's 
    ll id = 0;
    ll source = id++;
    vl V1(G1[u1].size());
    rep(i, G1[u1].size()) V1[i] = id++;
    vl V2(G2[u2].size());
    rep(i, G2[u2].size()) V2[i] = id++;
    ll target = id++;
    Dinic dinic(id + 2);

    // Creo el grafo
    rep(i, G1[u1].size()) dinic.addEdge(source, V1[i], 1);
    rep(i, G2[u2].size()) dinic.addEdge(V2[i], target, 1);
    rep(i, G1[u1].size()) rep(j, G2[u2].size()) if(G1[u1][i] != p1 and G2[u2][j] != p2) {
        if(dp(G1[u1][i], G2[u2][j], u1, u2)) {
            dinic.addEdge(V1[i], V2[j], 1);
        }
    }
    // Si logro asignar todos entonces marco como que se puede resolver
    if(dinic.maxFlow(source, target) == G2[u2].size() - (p2 != -1)) DP[u1][u2] = 1;
    return DP[u1][u2];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        ll u, v; cin>>u>>v; u--, v--;
        G1[u].pb(v); G1[v].pb(u);
    }
    int m; cin>>m;
    rep(i, m - 1) {
        ll u, v; cin>>u>>v; u--, v--;
        G2[u].pb(v), G2[v].pb(u);
    }
    ll ans = 0;
    rep(i, n) {
        rep(j, 100) rep(k, 100) DP[j][k] = -1;
        ans |= dp(i, 0, -1, -1);
    }
    cout<<(ans? "Y": "N")<<'\n';





    return 0;
}