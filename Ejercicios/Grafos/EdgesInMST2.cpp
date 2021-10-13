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
 
 
 
vector<bool> inT;
vector<Edge> conv;
vector<int> ans;
vector<vector<Edge>> G;

struct MST{
    ll weight;
    int cur_w = -1;
    vi p; MST(int N, vector<Edge>& G) : p(N, -1){
        weight = 0;
        vector<Edge> A; rep(i, G.size()) A.emplace_back(G[i]);
        sort(A.begin(), A.end());
        // preuno
        rep(i, A.size()) pre_unite(A[i]);
        
        // analisis posterior
        rep(i, conv.size()){
            int x = get(conv[i].u), y = get(conv[i].v);
            if(x == y) continue;
            inT[conv[i].ind] = 1;
            if(p[x] > p[y]) swap(x,y);
            p[x] += p[y], p[y] = x;
        }
    }
    void pre_unite(Edge e){
        // xd
        if(e.w > cur_w){
            rep(i, conv.size()){
                int x = get(conv[i].u), y = get(conv[i].v);
                if(x == y) continue;
                inT[conv[i].ind] = 1;
                if(p[x] > p[y]) swap(x,y);
                p[x] += p[y], p[y] = x;
            }
            conv.clear();
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
        G[x].push_back(Edge(x, y, e.w, e.ind));
        G[y].push_back(Edge(y, x, e.w, e.ind));
        conv.push_back(e);
    }
};
 
 
 
vi D, L;
vector<bool> cut;
void dfs(int u, int p, int d){
    D[u] = L[u] = d;
    for(Edge e : G[u]) if (e.ind != p){
        if (D[e.v] == -1){
            dfs(e.v, e.ind, d + 1);
            if (L[e.v] > D[u]) { // (u - v) cut edge
                cut[e.ind] = 1;
            } 
            L[u] = min(L[u], L[e.v]);
        }
        else L[u] = min(L[u], D[e.v]);
    }
}
 
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Edge> E; // Edges
    inT.assign(m, 0);
    G.assign(n, vector<Edge>()); D.assign(n, -1); L.assign(n, -1); cut.assign(m, 0);
    rep(i, m){
        int u, v, w; cin>>u>>v>>w; u--, v--;
        E.emplace_back(u, v, w, i);
    }

    // inicializo las cosas
    ans.assign(m, 2);
    MST mst = MST(n, E);
 
    dfs(0, -1, 0);
 
    rep(i, m){
        if(ans[i] == 0) cout<<"none\n";
        else if(!cut[E[i].ind]) cout<<"at least one\n";
        else cout<<"any\n";
    }
 
 
    return 0;
}