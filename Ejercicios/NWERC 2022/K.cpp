#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> pint;
typedef double db;
typedef vector<int> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

int n, m; 
const int mxN = 1e5+5;
set<int> G[mxN];
int V[mxN];
int P[mxN];

vl curr;
vl Cicle;
int cicle = 0;
int Sz[mxN];

void dfs(int u, int p = -1, int d = 1) {
    // cout<<"visito a "<<u<<'\n';
    curr.pb(u);
    V[u] = d, P[u] = p, Sz[u] = 1;
    for(auto v: G[u]) {
        if(V[v] and p != v and V[u] > V[v]) {
            cicle++;
            int x = u;
            while(x != v) {
                Cicle.pb(x);
                x = P[x];
            }
            Cicle.pb(x);
        }
        if(cicle >= 2) break;
        if(!V[v])  dfs(v, u, d + 1), Sz[u] += Sz[v];
        if(v == u) Sz[u]++;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>m>>n;

    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].insert(v), G[v].insert(u);
    }
    int comps = n;
    rep(i, n) if(G[i].size() == 0) comps--;

    bool imp = 0;
    // Ahora me toca revisar por componente
    rep(u, n) if(!V[u]) {
        cicle = 0; curr.clear(), Cicle.clear();
        dfs(u);
        if(cicle >= 2) {
            // cout<<"entre en ciclo mayor o igual a 2\n";
            imp = 1;
            break;
        }
        else if(cicle >= 1)  {
            for(auto v: curr) V[v] = 0; 
            for(auto v: Cicle) V[v] = 1;
            for(auto v: Cicle) {
                for(auto w: G[v]) if(!V[w]) {
                    dfs(w, v);
                    if(Sz[w] > 1) imp = 1;
                }
            }
            if(curr.size() < comps) imp = 1;
        }
        else {
            // No hay ningun ciclo, debo revisar si es que 
            // fuera del diametro hay un outlier mayor o igual a 1
            // 1. conseguir el diametro del grafo
            int mx = u;
            for(auto v: curr) if(V[v] > V[mx]) mx = v;
            for(auto v: curr) V[v] = 0;
            curr.clear();
            // 2. Obtengo el diametro del grafo
            dfs(mx);
            for(auto v: curr) if(V[v] > V[mx]) mx = v;
            set<int> path;
            int x = mx;
            // 3. Recupero el camino del diametro 
            while(x != -1) {
                path.insert(x);
                x = P[x];
            }
            for(auto v: curr) {
                ll cont = 0;
                for(auto w: G[v]) {
                    if(w != v and G[w].size() > 1) cont++;
                }
                // if(cont >= 3) cout<<v<<" tiene "<<cont<<" vecinos con subarboles >= 3\n";
                if(cont >= 3) imp = 1;
            }
        }
    }
    if(imp) cout<<"impossible\n";
    else cout<<"possible\n";



    return 0;
}