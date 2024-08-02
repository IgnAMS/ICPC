#pragma GCC optimize("Ofast")
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


const int mxN = 2e5+5;
vl G[mxN];

int rc = 0;
vl Puentes;
ll D[mxN], L[mxN];
vl Comps;
void dfs(int u, int p, int d) {
    D[u] = L[u] = d;
    Comps.pb(u);
    for(auto v: G[u]) if(v != p) {
        if(D[v] == -1) dfs(v, u, d + 1);
    }
}



ll V[mxN];
vector<pll> Ans;

void dfs2(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) {
        Ans.pb({u, v});
        dfs2(v);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin>>n>>m>>k;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    if(G[0].size() < k) {
        cout<<"NO\n";
        return 0;
    }

    rep(u, n) D[u] = -1, L[u] = 0; 
    D[0] = 0;
    rep(u, n) if(u != 0) {
        if(D[u] == -1) {
            Comps.clear();
            dfs(u, -1, 0);
            bool ready = 0;
            for(auto v: Comps) {
                for(auto xd: G[v]) if(xd == 0) {
                    Puentes.pb(v);
                    ready = 1;
                    break;
                }
                if(ready) break;
            }
        }
    }

    // cout<<Puentes.size()<<'\n';
    if(Puentes.size() > k) {
        cout<<"NO\n";
        return 0;
    }
    set<ll> S;

    V[0] = 1;
    // Visito los puentes
    for(auto v: Puentes) {
        S.insert(v);
        Ans.pb({0, v});
        V[v] = 1;
        k--;
    }
    // Completo hasta llegar a k
    for(auto v: G[0]) if(!S.count(v) and k > 0) {
        V[v] = 1;
        Ans.pb({0, v});
        S.insert(v);
        k--;
    }
    // Hago dfs desde todos mis nodos :)
    for(auto s: S) dfs2(s);

    cout<<"YES\n";
    for(auto [a, b]: Ans) cout<<a + 1<<' '<<b + 1<<'\n';





    return 0;
}