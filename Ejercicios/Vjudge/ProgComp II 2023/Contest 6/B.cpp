#pragma GCC optimize("O2")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 1e4+5;
vector<vl> G;

vector<pll> S;
int D[mxN], L[mxN];
vector<vl> G2;
void tarjan(int u, int p, int d) {
    D[u] = L[u] = d;
    for(int v : G[u]) if (v != p) {
        if (D[v] == -1) {
            S.push_back({u, v}); tarjan(v, u, d + 1);
            // Cut Edge
            if(L[v] > D[u]) {
                // cout<<"conecto los nodos "<<u<<' '<<v<<'\n';
                G2[u].pb(v);
                G2[v].pb(u);
            }
            // Componente biconexa
            if(p == -1 or L[v] >= d) {
                int nodocb = G2.size();
                G2.pb(vl());
                set<ll> nodos;
                int cont = 0;
                while(1) {
                    pll e = S.back(); S.pop_back();
                    cont++;
                    if(e == pll(u, v)) break;
                    nodos.insert(e.ff); nodos.insert(e.ss);
                }
                for(auto k: nodos) {
                    // cout<<"anado la arista "<<nodocb<<' '<<k<<'\n';
                    G2[nodocb].pb(k), G2[k].pb(nodocb);
                }
                // Val.pb(cont);
            }
            L[u] = min(L[u], L[v]);
        }
        else if (D[v] < d) { S.push_back({u, v}); L[u] = min(L[u], D[v]); }
    }
}


bool dfs(int u, int p, int t, int r, bool comp) {
    if(u >= r) comp = 1;
    if(u == t) return !comp;
    for(auto v: G2[u]) if(v != p) {
        if(dfs(v, u, t, r, comp)) return true;
    }
    // cout<<"salgo de "<<u<<'\n';
    return false;
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int r, c, q; 
    while(cin>>r>>c>>q and r) {
        G.assign(r, vl()); G2.assign(r, vl());
        // memset(D, -1, sizeof(D));
        rep(i, r) D[i] = -1;
        rep(i, c) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].pb(v);
            G[v].pb(u);
        }
        rep(i, r) if(D[i] == -1) tarjan(i, -1, 0);
        rep(i, q) {
            int u, v; cin>>u>>v; u--, v--;
            if(dfs(u, -1, v, r, 0)) cout<<"Y\n";
            else cout<<"N\n";
        }
        cout<<"-\n";
        
    }

    return 0;
}