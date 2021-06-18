#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a; i<b; i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second

vector<vector<ii>> T;

struct Edge{
    ll u, v, w;
    Edge(ll u, ll v, ll w): u(u), v(v), w(w) {}
    bool operator<(Edge& e) const { return w > e.w; }
};


struct MST{
    int n;
    vector<int> p;
    ll w = 0;
    MST(int n, vector<Edge>& E): n(n){
        p.assign(n, -1);
        sort(E.begin(), E.end());
        reverse(E.begin(), E.end());
        for(auto& e : E) join(e);
    }
    int find(int u){ return p[u] < 0? u: p[u] = find(p[u]); }
    void join(Edge& e){
        int u = find(e.u), v = find(e.v);
        if(u == v) return;
        if(-p[v] > -p[u]) swap(u,v);
        w += e.w;
        T[e.u].emplace_back(e.v, e.w);
        T[e.v].emplace_back(e.u, e.w);
        p[u] += p[v], p[v] = u;
    }
};


struct LCA{
    int n, l;
    vector<vector<int>> up;
    vector<int> D;
    vector<vector<ll>> maxw;
    vector<vector<ii>> T;
    LCA(int n, vector<vector<ii>>& T): n(n), T(T) {
        l = log2(n) + 1;
        D.assign(n, -1); up.assign(n, vector<int>(l, -1));
        maxw.assign(n, vector<ll>(l, 0));
        dfs(0,-1,0,0);
        for(int e = 1; e < l; e++) rep(u, n){
            int a = up[u][e-1];
            if(a != -1){
                up[u][e] = up[a][e-1];
                maxw[u][e] = max(maxw[a][e-1], maxw[u][e-1]);
            }
            else up[u][e] = -1;
        
        }
    }

    void dfs(int u, int p, int d, ll w){
        D[u] = d; up[u][0] = p; maxw[u][0] = w;
        for(auto& v : T[u]) if(v.ff != p) dfs(v.ff, u, d+1, v.ss);
    }

    ll maxi(int u, int v){
        if(D[u] > D[v]) swap(u,v);
        ll maxW=0;
        for(int e = l-1; e>=0; e--){
            if(up[v][e] != -1 && D[up[v][e]] >= D[u]){
                maxW=max(maxW, maxw[v][e]);
                v = up[v][e];
            }
        }
        if(v == u) return maxW;
        for(int e=l-1; e>=0;e--){
            if(up[u][e] != up[v][e]){
                maxW=max({maxW, maxw[v][e], maxw[u][e]});
                v = up[v][e], u = up[u][e];
            }
        }
        maxW = max({maxw[u][0], maxw[v][0], maxW});
        return maxW;
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; T.assign(n, {});
    ll mat[n][n];
    rep(i,m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w);
        mat[u][v] = w;
        mat[v][u] = w;
    }
    MST mst = MST(n, E);
    LCA lca = LCA(n, T);
    int q; cin>>q;
    while(q--){
        int u, v; cin>>u>>v; u--, v--;
        cout<<mst.w + mat[u][v] - lca.maxi(u, v)<<"\n";
    }
    
    return 0;
}