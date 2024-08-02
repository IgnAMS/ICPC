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

vl G[200005], G2[200005];

bool V[200005];
void dfs_tree(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) {
        G2[u].pb(v);
        dfs_tree(v);
    }
}

set<pll> dfs(int u = 0, int d = 0) {
    if(G2[u].size() == 0) {
        set<pll> aux; aux.insert({d, u});
        return aux;
    }
    if(G2[u].size() == 1) {
        set<pll> aux = dfs(G2[u][0], d + 1);
        vector<pll> E;
        for(auto& u: aux) if(u.ff > d + 1) E.pb(u);
        for(auto& e : E) aux.erase(e);
        
        aux.insert({d, u});
        return aux;
    }
    // two sons
    set<pll> aux1 = dfs(G2[u][0], d + 1), aux2 = dfs(G2[u][1], d + 1);

    ll mx = min(aux1.rbegin()->ff, aux2.rbegin()->ff);
    vector<pll> E;
    for(auto& u: aux1) if(u.ff > mx + 1) E.pb(u);
    for(auto& e: E) aux1.erase(e);
    E.clear();

    for(auto& u: aux2) if(u.ff > mx + 1) E.pb(u);
    for(auto& e: E) aux2.erase(e);

    if(aux1.size() < aux2.size()) swap(aux1, aux2);
    for(auto u: aux2) aux1.insert(u);

    aux1.insert({d, u});
    return aux1;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    } 

    dfs_tree(0);
    set<pll> ans = dfs(0, 0);
    cout<<n - ans.size()<<'\n';


    return 0;
}