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
// g++ -O2 B.cpp && time ./a.out <input.txt> output.txt

db EPS = 1e-12;

class Dinic {
    struct Edge { 
        int to, rev; ll f, c;
        Edge(int to, int rev, ll f, ll c): to(to), rev(rev), f(f), c(c) {}
    };
    int n, t_; vector<vector<Edge>> G;
    vector<ll> D; 
    vector<int> q, W;

    bool bfs(int s, int t) {
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while(f < l) {
            int u = q[f++];
            for(auto &e: G[u]) if(D[e.to] == -1 and e.f < e.c) {
                D[e.to] = D[u] + 1, q[l++] = e.to;
            }
        }
        return D[t] != -1;
    }
    ll dfs(int u, ll f) {
        if(u == t_) return f;
        for(int &i = W[u]; i < G[u].size(); ++i) {
            Edge &e = G[u][i]; int v = e.to;
            if(e.c <= e.f + EPS or D[v] != D[u] + 1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if(df > EPS) { e.f += df, G[v][e.rev].f -= df; return df; }
        }
        return 0;
    }
    public:
    Dinic(int N): n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap) {
        G[u].pb(Edge(v, (int)G[v].size(), 0, cap));
        G[v].pb(Edge(u, (int)G[u].size() - 1, 0, 0));
    }
    ll maxflow(int s, int t) {
        t_ = t; 
        ll ans = 0;
        while(bfs(s, t)) {
            // cout<<bfs(s, t)<<'\n';
            while(ll dl = dfs(s, 1e13)) {
                ans += dl;
                // cerr<<dl<<'\n';
            }
        }
        return ans;
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, x; cin>>n>>m>>x;
    vector<vl> E;
    int source = n, target = n + 1;
    rep(i, m) {
        int u, v, cap; cin>>u>>v>>cap; u--, v--;
        E.pb({u, v, cap});
    }

    
    db l = 0, r = 1e12;
    rep(_, 80) {
        db mid = (l + r) * 0.5;
        Dinic dinic(n + 5);
        rep(i, m) {
            dinic.addEdge(E[i][0], E[i][1], (ll) (E[i][2] / mid));
        }
        db flow = dinic.maxflow(0, n - 1);
        // cout<<setprecision(10)<<fixed<<"Con "<<mid<<" se logro un flujo de "<<flow<<'\n';
        
        if(flow >= x) l = mid;
        else r = mid;
    }
    cout<<setprecision(9)<<fixed<<x * (l + r) * 0.5<<'\n';



    return 0;
}