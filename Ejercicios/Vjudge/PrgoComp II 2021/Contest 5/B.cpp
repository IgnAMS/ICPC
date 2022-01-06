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


struct Edge{
    ll u, v, w, ind;
    Edge(int u, int v, int w, int ind) : u(u), v(v), w(w), ind(ind) {}
    bool operator<(const Edge &e) const { return w < e.w; }
};


vi L, D, ans, V;
set<int> act;
vector<vector<Edge>> conv;
vector<ii> erase;
void dfs(int u, int p, int d){
    cerr<<"visitare al nodo "<<u<<" en profundidad "<<d<<'\n';
    D[u] = L[u] = d;
    V.push_back(u);
    for(auto e : conv[u]) if (e.v != p){
        if (D[e.v] == -1){
            dfs(e.v, u, d + 1);
            cerr<<"L["<<e.v<<"]: "<<L[e.v]<<", D["<<u<<"]: "<<D[u]<<'\n';
            if (L[e.v] > D[u]) { // cut edge
                cerr<<"marco la arista "<<e.ind<<" como arista de corte\n";
                ans[e.ind] = 2;
            }
            L[u] = min(L[u], L[e.v]);
        }
        else L[u] = min(L[u], D[e.v]);
    }
}


vector<vi> T;
vector<bool> inT; // 0 -> some, 1 -> at least, 2 -> any
map<int, map<int, vector<Edge>>> mapa;
struct DSU{
    ll weight;
    ll cur_w = -1;
    vi p; DSU(int N, vector<Edge>& G) : p(N, -1) {
        weight = 0;
        vector<Edge> A; rep(i, G.size()) A.emplace_back(G[i]);
        sort(A.begin(), A.end());
        cur_w = A[0].w;
        rep(i, A.size()) pre_unite(A[i]);
        for(auto x: act) if(D[x] == -1) dfs(x, -1, 0);
        
    }
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void pre_unite(Edge e){
        int x = e.u, y = e.v;
        if(e.w > cur_w){
            // correr codigo
            // Sacar los vertices de corte
            cerr<<"hare el dfs\n";
            for(auto x: act) if(D[x] == -1) dfs(x, -1, 0);
            // reseteo los datos
            cur_w = e.w;
            rep(i, V.size()) {
                D[V[i]] = L[V[i]] = -1; // reseteo
                conv[V[i]] = vector<Edge>();
            }
            rep(i, erase.size()){ 
                int a = erase[i].first, b = erase[i].second;
                cerr<<a<<' '<<b<<'\n';
                a = get(a), b = get(b);
                if(a == b) continue;
                if(p[a] > p[b]) swap(a, b);
                p[a] += p[b], p[b] = a;
            }
            act.clear(); erase.clear(); V.clear();
        }
        unite(e);
    }
    void unite(Edge e){
        int x = e.u, y = e.v, w = e.w;
        if ((x = get(x)) == (y = get(y))) { 
            ans[e.ind] = 0;
            return;
        }
        weight += w;
        inT[e.ind] = 1;
        T[e.u].push_back(e.v);
        T[e.v].push_back(e.u);
        // coloco las cosas a trabajar
        act.insert(e.u); act.insert(e.v);
        cerr<<"agrego la arista de "<<x<<" a "<<y<<'\n';
        conv[x].push_back(Edge(x, y, w, e.ind));
        conv[y].push_back(Edge(y, x, w, e.ind));
        erase.push_back({x, y});
        // if(p[x] > p[y]) swap(x,y);
        // p[x] += p[y], p[y] = x;
    }
};




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; // Edges
    T.assign(n, vi()); inT.assign(m, 0);
    rep(i, m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w, i);
        Weight[u][v] = w, Weight[v][u] = w;
    }
    ans.assign(m, 1); L.assign(n, -1); D.assign(n, -1); conv.assign(n, vector<Edge>());
    DSU dsu = DSU(n, E);
    rep(i, m) {
        if(ans[i] == 0) cout<<"none\n";
        else if(ans[i] == 1) cout<<"";
        cout<<ans[i]<<'\n';
    }


    return 0;
}