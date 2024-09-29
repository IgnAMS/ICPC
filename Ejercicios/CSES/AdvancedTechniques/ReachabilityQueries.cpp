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
    int n, m, q; cin>>n>>m>>q;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
    }

    // 1. Hacer SCC
    // 2. Hacer el dfs en el nuevo DAG del SCC
    // 3. Calcular la respuesta :)

    while(q--) {
        int u, v; cin>>u>>v; u--, v--;
        cout<<(ans[u][v]? "YES": "NO")<<'\n';
    }

    return 0;
}