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



vector<Edge> E2;
vector<int> ans;
vector<vector<Edge>> G;

vi D, L;
vector<bool> cut;
void dfs(int u, int p, int d){
    D[u] = L[u] = d;
    for(Edge e : G[u]) if (e.ind != p){
        if (D[e.v] == -1){
            dfs(e.v, e.ind, d + 1);
            if (L[e.v] > D[u]) { // (u - v) cut edge
                ans[e.ind] = 2;
            } 
            L[u] = min(L[u], L[e.v]);
        }
        L[u] = min(L[u], D[e.v]);
    }
}

struct MST{
    ll weight;
    int cur_w = -1;
    vi p; MST(int N, vector<Edge>& G) : p(N, -1) {
        weight = 0;
        vector<Edge> A; rep(i, G.size()) A.emplace_back(G[i]);
        sort(A.begin(), A.end());
        // preuno
        rep(i, A.size()) pre_unite(A[i]);
        
        // analisis posterior
        for(auto e_: E2) if(D[e_.u] == -1) dfs(e_.u, -1, 0);
        rep(i, E2.size()){
            int x = get(E2[i].u), y = get(E2[i].v);
            if(x == y) continue;
            if(p[x] > p[y]) swap(x,y);
            p[x] += p[y], p[y] = x;
        }
    }
    void pre_unite(Edge e){
        if(e.w > cur_w){
            for(auto e_: E2) if(D[e_.u] == -1) dfs(e_.u, -1, 0);
            rep(i, E2.size()){
                int x = get(E2[i].u), y = get(E2[i].v);
                if(x == y) continue;
                if(p[x] > p[y]) swap(x,y);
                p[x] += p[y], p[y] = x;
            }
            for(auto e_: E2) { G[e_.u].clear(); G[e_.v].clear(); }
            E2.clear();
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
        weight += w; 
        D[x] = L[x] = -1; D[y] = L[y] = -1;
        G[x].push_back(Edge(x, y, e.w, e.ind));
        G[y].push_back(Edge(y, x, e.w, e.ind));
        E2.push_back(Edge(x, y, e.w, e.ind));
        // if(p[x] > p[y]) swap(x,y);
        // p[x] += p[y], p[y] = x;
    }
};






int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; // Edges
    G.assign(n, vector<Edge>());
    rep(i, m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w, i);
    }

    // inicializo las cosas
    ans.assign(m, 1); D.assign(n, -1); L.assign(n, -1);
    MST mst = MST(n, E);

    rep(i, m){
        if(ans[i] == 0) cout<<"none\n";
        else if(ans[i] == 1) cout<<"at least one\n";
        else cout<<"any\n";
    }


    return 0;
}