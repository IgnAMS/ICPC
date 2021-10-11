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
#define ep emplace_back
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

map<int, map<int, int>> Weight;

struct Edge{
    ll u, v, w, ind;
    Edge(int u, int v, int w, int ind) : u(u), v(v), w(w), ind(ind) {}
    bool operator<(const Edge &e) const { return w < e.w; }
};




vector<vi> T;
vector<bool> inT;
vector<Edge> conv, E2;
vector<int> ans;
vector<vector<Edge>> G;
vector<ii> P; vector<int> erase;
struct DSU{
    ll weight;
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(Edge e, bool esp = false){
        int x = e.u, y = e.v, w = e.w;
        int a = e.u, b = e.v;
        if ((x = get(x)) == (y = get(y))) {
            if(esp) {
                cerr<<"empece el caso\n";
                ans[e.ind] = 1;
            }
            return;
        }
        inT[e.ind] = 1;
        if (p[x] > p[y]) { swap(x,y); swap(a, b); }
        P[b] = {a, e.ind};
        cerr<<"concateno "<<b<<" a "<<a<<'\n';
        erase.push_back(b);
        p[x] += p[y], p[y] = x;
    }
};
struct MST{
    ll weight;
    int cur_w = -1;
    DSU dsu;
    vi p; MST(int N, vector<Edge>& G) : p(N, -1), dsu(G.size()) {
        weight = 0;
        vector<Edge> A; rep(i, G.size()) A.emplace_back(G[i]);
        sort(A.begin(), A.end());
        // preuno
        rep(i, A.size()) pre_unite(A[i]);
        
        // analisis posterior
        rep(i, conv.size()) dsu.unite(conv[i], 1);
        rep(i, conv.size()){
            int x = get(conv[i].u), y = get(conv[i].v);
            if(x == y) continue;
            if(p[x] > p[y]) swap(x,y);
            p[x] += p[y], p[y] = x;
        }
    }
    void pre_unite(Edge e){
        // xd
        if(e.w > cur_w){
            rep(i, conv.size()) dsu.unite(conv[i], 1);
            rep(i, conv.size()){
                int x = get(conv[i].u), y = get(conv[i].v);
                if(x == y) continue;
                if(p[x] > p[y]) swap(x,y);
                p[x] += p[y], p[y] = x;
            }
            for(auto x: erase) P[x] = {-1, -1};
            conv.clear(); erase.clear();
            cur_w = e.w;
        }
        unite(e);
    }

    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(Edge e, bool esp = false){
        int x = e.u, y = e.v, w = e.w;
        if ((x = get(x)) == (y = get(y))) {
            ans[e.ind] = 0;
            return;
        }
        // cerr<<x<<' '<<y<<' '<<e.ind<<'\n';
        weight += w; 
        T[e.u].push_back(e.v);
        T[e.v].push_back(e.u);
        // inT[e.ind] = 1;
        G[e.u].push_back(Edge(e.u, e.v, e.w, e.ind));
        G[e.v].push_back(Edge(e.v, e.u, e.w, e.ind));
        E2.push_back(Edge(x, y, e.w, e.ind));
        conv.push_back(e);
        // if(p[x] > p[y]) swap(x,y);
        // p[x] += p[y], p[y] = x;
    }
};



vi D, L;
vector<bool> cut;
void dfs(int u, int p, int d, int w){
    D[u] = L[u] = d;
    for(Edge e : G[u]) if (e.v != p and w == e.w){
        if (D[e.v] == -1){
            dfs(e.v, u, d + 1, w);
            if(e.ind == 8) cerr<<"arista 8: "<<e.v<<' '<<u<<'\n';
            if (L[e.v] > D[u]) { // (u - v) cut edge
                if(e.ind == 8) cerr<<"hola wola\n";
                cut[e.ind] = 1;
            } 
            if(u == 15) cerr<<e.v<<' '<<L[e.v]<<'\n';
            L[u] = min(L[u], L[e.v]);
        }
        else {
            if(u == 15) cerr<<e.v<<' '<<L[e.v]<<' '<<e.ind<<'\n';
            L[u] = min(L[u], D[e.v]);
        }
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; // Edges
    T.assign(n, vi()); inT.assign(m, 0);
    G.assign(n, vector<Edge>());
    set<ii> sW;
    rep(i, m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w, i); sW.insert({u, w});
        Weight[u][v] = w, Weight[v][u] = w;
    }
    // inicializo las cosas
    
    ans.assign(m, 2); P.assign(n, {-1, -1});
    MST mst = MST(n, E);
    // rep(i, m) cout<<cut[i]<<' '; cout<<'\n';

    DSU w_dsu = DSU(m);
    D.assign(n, -1); L.assign(n, -1); cut.assign(m, 0);
    for(auto u: sW) if(D[u.ff] == -1) dfs(u.ff, -1, 0, u.ss);
    vector<vector<int>> A;
    rep(i, E2.size()) {
        // if(n == 20) cout<<E2[i].u<<' '<<E2[i].v<<' '<<E2[i].w<<' '<<E2[i].ind<<'\n';
        // cerr<<E2[i].u<<' '<<E2[i].v<<' '<<E2[i].w<<' '<<E2[i].ind<<'\n';
        vector<int> a = {int(E2[i].w), int(E2[i].u), int(E2[i].ind)};
        vector<int> b = {int(E2[i].w), int(E2[i].v), int(E2[i].ind)}; 
        A.pb(a); A.pb(b);
    }
    sort(A.begin(), A.end());
    // si tienen algo que los una y ademas son del mismo los uno
    rep(i, A.size() - 1) if(tie(A[i][0], A[i][1]) == tie(A[i + 1][0], A[i + 1][1])){
        if(ans[A[i][2]] and ans[A[i+1][2]] and !cut[A[i][2]] and !cut[A[i + 1][2]]) {
            w_dsu.unite(Edge(A[i][2], A[i + 1][2], 0, 0));
        }
    }
    vector<bool> at_least(m, 0); 
    rep(i, E2.size()) if(ans[E2[i].ind] == 1){
        at_least[w_dsu.get(E2[i].ind)] = 1;
    }
    // rep(i, m) if(ans[i]) cout<<i<<" "<<w_dsu.get(i)<<'\n'; cout<<'\n';
    // rep(i, m) if(ans[i]) cout<<i<<' '<<cut[i]<<'\n'; cout<<'\n';
    // if(n == 20) { rep(i, E2.size()) cout<<E2[i].ind<<' '<<cut[E2[i].ind]<<' '; cout<<'\n'; }

    rep(i, m){
        if(ans[i] == 0) cout<<"none\n";
        else if(at_least[w_dsu.get(i)]) cout<<"at least one\n";
        else cout<<"any\n";
    }


    return 0;
}