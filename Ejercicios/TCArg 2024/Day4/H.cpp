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

const int mxN = 100;
vl G[mxN][mxN]; // nodo, color
ll V[mxN][mxN];


ll comp = 0;
void dfs(ll u, ll color) {
    V[u][color] = comp;
    for(auto v: G[u][color]) if(V[v][color] == -1) dfs(v, color);
}




int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        ll u, v, c; cin>>u>>v>>c; u--, v--, c--;
        G[u][c].pb(v); G[v][c].pb(u);
    }
    rep(i, n) rep(c, m) V[i][c] = -1;

    rep(i, n) rep(c, m) {
        if(V[i][c] == -1) {
            dfs(i, c);
            comp++;
        }
    }
    int q; cin>>q;
    while(q--) {
        int u, v; cin>>u>>v; u--, v--;
        ll ans = 0;
        rep(c, m) if(V[u][c] == V[v][c]) ans++;
        cout<<ans<<'\n';
    }




    return 0;
}