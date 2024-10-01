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

vl G[102][102];
ll Comp[102][102]; // Comp[u][c] = component of the node u in the color c

void dfs(ll u, ll c, ll comp) {
    // cout<<"asigno el nodo "<<u<<" con color "<<c<<" de la componente "<<comp<<'\n'; 
    Comp[u][c] = comp;
    for(auto v: G[u][c]) if(!Comp[v][c]) dfs(v, c, comp); 
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        ll u, v, c; cin>>u>>v>>c;
        G[u][c].pb(v);
        G[v][c].pb(u);
    } 

    rep(c, m + 1) {
        ll comp = 0;
        rep(u, n + 1) if(!Comp[u][c]) dfs(u, c, comp), comp++;
    }

    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v;
        ll ans = 0;
        rep(c, m + 1) ans += Comp[u][c] == Comp[v][c];
        cout<<ans<<'\n';
    }


    return 0;
}