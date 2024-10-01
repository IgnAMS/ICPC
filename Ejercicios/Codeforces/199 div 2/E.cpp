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
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


struct LCA {
    vector<vi> G;
    int N, LOG; vi A, D;
    ll &anc(int u, int l) { return A[l * N + u]; }
    LCA(vector<vi> &G, int N, int root) : G(G), N(N) {
        LOG = 31 - __builtin_clz(N);
        D.assign(N, -1); A.resize(N * (LOG + 1));
        
        dfs(root, -1, 0);
        rep(l, LOG + 1) if (l) rep(u, N)
        {
            int a = anc(u, l - 1);
            anc(u, l) = (a == -1 ? -1 : anc(a, l - 1));
        }
    }
    void dfs(int u, int p, int depth) {
        anc(u, 0) = p, D[u] = depth;
        for (int v : G[u]) if (D[v] == -1) dfs(v, u, depth + 1);
    }
    int raise(int u, int k) {
        for (int l = 0; k; l++, k >>= 1) if (k & 1) u = anc(u, l);
        return u;
    }
    int lca(int u, int v) {       
        if (D[u] < D[v]) swap(u, v); 
        u = raise(u, D[u] - D[v]);
        if (u == v) return u;
        for (int l = LOG; l >= 0; l--) if (anc(u, l) != anc(v, l))
            u = anc(u, l), v = anc(v, l);
        return anc(u,0);
    }
    ll dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v)]; }
    int raise_in_path(int u, int v, int k) {
        if (D[u] - D[lca(u, v)] >= k) return raise(u, k);
        return raise(v, dist(u, v) - k);
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    vector<vi> G(n, vi());
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }

    LCA lca(G, n, 0);
    
    vi Reds = {0};
    vector<ii> Q(m);
    rep(i, m) cin>>Q[i].ff>>Q[i].ss;
    for(auto &u: Q) u.ss--;

    ll sq = sqrt(m);
    rep(i, sqrt(m) + 1) {
        // BFS
        vi D(n, 1e8);
        deque<ii> dq; 
        for(auto u: Reds) {
            dq.push_back({u, 0}); 
            D[u] = 0;
        }
        while(!dq.empty()) {
            ll u, d; tie(u, d) = dq.front(); dq.pop_front();
            for(auto v: G[u]) if(D[v] == 1e8) {
                dq.push_back({v, d + 1});
                D[v] = d + 1;
            }
        }
        // rep(i, n) cout<<D[i]<<' '; cout<<'\n';
        
        // Operations
        vi NewReds; 
        repx(j, sq * i, min(sq * (i + 1), m)) {
            if(Q[j].ff == 1) NewReds.push_back(Q[j].ss);
            else {
                ll ans = D[Q[j].ss];
                for(auto u: NewReds) ans = min(ans, lca.dist(Q[j].ss, u));
                cout<<ans<<'\n';
            }
        }
        for(auto u: NewReds) Reds.push_back(u);
    }

    return 0;
}