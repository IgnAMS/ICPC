#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
#define ff first
#define ss second

vector<vector<int>> G1, G2;
vector<int> C1, C2;
vector<int> p1;

struct DSU{
    vi p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};



int ind = 0;
void dfs1(int u, int p, DSU &mst){
    C1[u] = ind;
    for(int v : G1[u]) if(v != p and C1[v] == -1) { mst.unite(u, v); dfs1(v, u, mst); } 
}
void dfs2(int u, int p, DSU &mst){
    C2[u] = ind;
    for(int v : G2[u]) if(v != p and C2[v] == -1) { mst.unite(u, v); dfs2(v, u, mst); }
}

int main(){ 
    int n, m1, m2; cin>>n>>m1>>m2;
    G1.resize(n, vector<int>()), G2.resize(n, vector<int>());
    C1.resize(n, -1); C2.resize(n, -1);
    DSU mst1 = DSU(n); DSU mst2 = DSU(n); // creo los conjuntos
    // inicializo el grafo
    rep(i, m1) {
        int u, v; cin>>u>>v; u--, v--;
        G1[u].push_back(v); G1[v].push_back(u);
    }
    rep(i, m2) {
        int u, v; cin>>u>>v; u--, v--;
        G2[u].push_back(v); G2[v].push_back(u);
    }
    // Creo las componentes
    ind = 0;
    rep(i, n) {
        if(C1[i] == -1) { ind++; dfs1(i, -1, mst1); }
    }
    int c1 = ind;
    ind = 0;
    rep(i, n) {
        if(C2[i] == -1) { ind++; dfs2(i, -1, mst2); }
    }
    int c2 = ind;
    vector<set<int>> Comp1(c1 + 1, set<int>()), Comp2(c2 + 1, set<int>());
    rep(i, n) { Comp1[C1[i]].insert(i); Comp2[C2[i]].insert(i); }
    rep(i, n) cout<<i<<' '<<C1[i]<<' '<<C2[i]<<'\n';
    // a lo mas se pueden añadir min(c1, c2) - 1 conexiones
    // voy al mas pequeño e intento conectarlo, lo hago de forma cuadratica
    int ans = 0;
    vector<ii> P;
    rep(i, n) repx(j, i+1, n){
        if(mst1.get(i) != mst1.get(j) and mst2.get(i) != mst2.get(j)){
            mst1.unite(i, j); mst2.unite(i, j);
            P.emplace_back(i, j);
            ans++;
        }
    }
    cout<<ans<<'\n';
    for(ii u : P) cout<<u.ff + 1<<' '<<u.ss + 1<<'\n';













    return 0;
}