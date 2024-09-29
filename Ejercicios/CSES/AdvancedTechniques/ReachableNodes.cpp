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

vl G[50005];
ll V[50005];
bitset<50005> ans[50005];

vl X;
void dfs(int u) {
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) dfs(v);
    X.pb(u);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
    }

    rep(u, n) if(!V[u]) dfs(u);

    // X esta ordenado por orden de salida
    // Por lo que lo optimo es simplemente iterar sobre X y calcular la respuesta
    for(auto u: X) {
        ans[u][u] = 1;
        for(auto v: G[u]) {
            ans[u] |= ans[v]; 
        }
    }
    rep(u, n) cout<<ans[u].count()<<' '; cout<<'\n';


    return 0;
}