#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

const int mxN = 2e5+5;

class Dinic{
    struct Edge {int to, rev; ll f, c; };
    int n, t_; vetor<vector<Edge>> G;
    vl D; vi q, W;
    bool bfs(int s, int t){
        W.assign(n, 0); D.assign(n, -1); D[s] = 0;
        int f = 0, l = 0; q[l++] = s;
        while(f<l){
            int u = q[f++];
            for(const Edge &e : G[u]) if(D[e.to] == -1 && e.f < e.c)
                D[e.to] = D[u] + 1, q[l++] = e.to;
        }
        return D[t] != -1;
    }

    ll dfs(int u, ll f){
        if(u == t_) return f;
        for(int &i = W[u]; i<(int)G[u].size(); ++i){
            Edge &e = G[u][i]; int v = e.to;
            if(e.c <= e.f || D[v] != D[u]+1) continue;
            ll df = dfs(v, min(f, e.c - e.f));
            if(df > 0) { e.f += df, G[v][e.rev].f -= df; return df;}
        }
        return 0;
    }
  public:
    Dinic(int N) : n(N), G(N), D(N), q(N) {}
    void addEdge(int u, int v, ll cap){
        G[u].push_back({v, (int)G[v].size(), 0, cap});
        G[v].push_back({u, (int)G[u].size()-1, 0, 0});
    }
};

void solve(){

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}

