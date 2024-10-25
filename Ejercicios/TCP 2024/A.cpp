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

const int mxN = 5e5+10;
int id[mxN];
vector<vector<pair<int, int>>> G(500005), G2(4 * mxN);

class HLD {
    int n;
    vector<int> A, H, D, R, P;
    int dfs(int u) {
        int ans = 1, M = 0, s;
        for(auto [v, w]: G[u]) if (v != A[u]) {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(v), ans += s;
            if(s > M) H[u] = v, M = s;
        }
        return ans;
    }
    void init_st(int l, int r, int u) {
        if(l == r) {
            id[l] = u;
            return;
        }
        G2[2 * u + 1].push_back({u, 0});
        G2[2 * u + 2].push_back({u, 0});
        int m = (l + r) / 2;
        init_st(l, m, 2 * u + 1);
        init_st(m + 1, r, 2 * u + 2);
    }
    void add_edge(int i, int j, int v, int w, int l, int r, int u) {
        if(i <= l and r <= j) {
            G2[u].pb({v, w});
            return;
        }
        if(r < i or j < l) return;
        int m = (l + r) / 2;
        add_edge(i, j, v, w, l, m, 2 * u + 1);
        add_edge(i, j, v, w, m + 1, r, 2 * u + 2);
    }

public:

    HLD(int N): n(N), A(N), D(N), R(N), P(N) {
        H.assign(n, -1); A[0] = -1, D[0] = 0; 
        dfs(0); 
        int p = 0;
        init_st(0, n - 1, 0);
        rep(i, n) if(A[i] == -1 || H[A[i]] != i) {
            for(int j = i; j != -1; j = H[j]) {
                R[j] = i, P[j] = p++;
            }
        }
    }
    
    void add_edge(int u, int v, int c, int w) {
        for (; R[u] != R[v]; v = A[R[v]]) {
            if(D[R[u]] > D[R[v]]) swap(u, v);
            add_edge(P[R[v]], P[v], id[P[c]], w, 0, n - 1, 0);
        }
        if(D[u] > D[v]) swap(u, v);
        add_edge(P[u], P[v], id[P[c]], w, 0, n - 1, 0);
    }
    int getP(int u) { return P[u]; }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    // cerr<<n<<' '<<m<<'\n';
    rep(i, n - 1) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    HLD hld(n);
    rep(u, n) {
        for(auto& [v, w]: G[u]) {
            // G2[id[hld.P[u]]].push_back({id[hld.P[v]], w});
            hld.add_edge(u, u, v, w);
        }
    }
    rep(i, m) {
        int a, b, c, w; cin>>a>>b>>c>>w; a--, b--, c--;
        hld.add_edge(a, b, c, w);
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    vector<ll> D(4 * n + 10, 1e17);
    D[id[hld.getP(0)]] = 0;
    pq.push({0, id[hld.getP(0)]});
    // cantidad de aristas ~ 20 * 5 * 10^5 ~  10^7
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        for(auto& [v, w]: G2[u]) {
            // cout<<"voy de "<<u<<" a "<<v<<" con costo "<<w<<'\n';
            if(D[v] > (ll)w + D[u]) {
                D[v] = (ll)w + D[u];
                pq.push({D[v], v});
            }
        }
    }
    repx(i, 1, n) cout<<D[id[hld.getP(i)]]<<' '; cout<<'\n';

    return 0;
}