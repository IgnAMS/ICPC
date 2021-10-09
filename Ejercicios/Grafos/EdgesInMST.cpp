#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<int> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

map<int, map<int, int>> Weight;

struct LCA{
    vector<vi> G;
    int N, LOG; vi A, D, W;
    int &anc(int u, int l) {
        return A[l * N + u];
    }
    LCA(vector<vi> &G, int N, int root) : G(G), N(N) { 
        LOG = 31 - __builtin_clz(N);
        D.assign(N, -1); A.resize(N * (LOG + 1)); W.resize(N * (LOG + 1));
        dfs(root, -1, 0);
        repx(l, 1, LOG + 1) rep(u, N){
            int a = anc(u, l - 1);
            anc(u, l) = (a == -1 ? -1 : anc(a, l - 1));
            if(a != -1){
                W[l * N + u] = max(W[(l - 1) * N + a], W[(l - 1) * N + u]);
            }
            else W[l * N + u] = 0;
        }
    }
    void dfs(int u, int p, int depth){
        anc(u, 0) = p, D[u] = depth; 
        if(p != -1) W[u] = Weight[u][p]; // inicializo el W
        for (int v : G[u]) if(D[v] == -1) dfs(v, u, depth + 1);
    }
    pair<int, int> raise(int u, int k){
        int w = 0;
        for (int l = 0; k; l++, k >>= 1) if(k & 1) {
            w = max(W[l * N + u], w);
            u = anc(u, l);
        }
        return {u, w};
    }
    pair<int, int> lca(int u, int v){  
        if (D[u] < D[v]) swap(u, v); 
        int w = 0;
        tie(u, w) = raise(u, D[u] - D[v]);
        if (u == v) return {u, w};
        for (int l = LOG; l >= 0; l--) if(anc(u, l) != anc(v, l)){
            w = max({w, W[l * N + u], W[l * N + v]});
            u = anc(u, l), v = anc(v, l);
        }
        return { anc(u,0), max({w, W[u], W[v]}) };
    }
    int dist(int u, int v) { return D[u] + D[v] - 2 * D[lca(u, v).ff]; }
    int raise_in_path(int u, int v, int k){
        if (D[u] - D[lca(u, v).ff] >= k) return raise(u, k).ff;
        return raise(v, dist(u, v) - k).ff;
    }
};

struct Edge{
    ll u, v, w;
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const Edge &e) const { return w < e.w; }
};


vector<vi> T;
struct DSU{
    ll weight;
    vi p; DSU(int N, vector<Edge>& G) : p(N, -1) {
        weight = 0;
        vector<Edge> A; rep(i, G.size()) A.emplace_back(G[i]);
        sort(A.begin(), A.end());
        rep(i, A.size()) unite(A[i]);
    }
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(Edge e){
        int x = e.u, y = e.v, w = e.w;
        if ((x = get(x)) == (y = get(y))) return;
        weight += w; 
        T[e.u].push_back(e.v);
        T[e.v].push_back(e.u);
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; // Edges
    T.assign(n, vi());
    rep(i, m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w);
        Weight[u][v] = w, Weight[v][u] = w;
    }
    DSU dsu = DSU(n, E);
    LCA lca = LCA(T, n, 0);
    vector<int> ans(m, 0); // 0 -> none, 1 -> any, 2 -> at least one
    vector<vector<ii>> G(n, vector<ii>());
    rep(i, m) {
        G[E[i].u].push_back({E[i].w, i});
        G[E[i].v].push_back({E[i].w, i});
    }
    // marco los any
    rep(i, n){
        int mini = 10000000;
        int cont = 0; int ind = -1;
        rep(j, G[i].size()){
            if(G[i][j].ff < mini){
                cont = 1, mini = G[i][j].ff;
                ind = G[i][j].ss;
            }
            else if(G[i][j].ff == mini){
                cont++;
            }
        }
        if(cont == 1) ans[ind] = 1;
    }
    rep(i, m){
        if(ans[i]) cout<<"any\n";
        else if(lca.lca(E[i].u, E[i].v).ss == E[i].w) {
            cout<<"at least one\n";
        }
        else cout<<"none\n";
    }


    return 0;
}