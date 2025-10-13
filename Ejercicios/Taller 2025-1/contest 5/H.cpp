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
ll C[mxN];
vl G[mxN];
vl G2[mxN];
ll V[mxN];
ll P[mxN];

void dfs(int u, int c, int p) {
    V[u] = 1;
    P[u] = p;
    for(auto v: G[u]) if(C[v] == c and !V[v]) dfs(v, c, p);
}


vl D(mxN, -1);
void dist(int u, int d) {
    // cout<<"vistio a "<<u<<" con dist "<<d<<'\n';
    D[u] = d;
    for(auto v: G2[u]) if(D[v] == -1) dist(v, d + 1);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    
    rep(i, n) cin>>C[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    rep(i, n) if(!V[i]) { 
        // Comprimo el arbol ya que es mas facil trabajar sobre el arbol comprimido
        dfs(i, C[i], i);
    }

    rep(u, n) {
        for(auto v: G[u]) if(P[v] != P[u]) {
            G2[P[u]].pb(P[v]);
            G2[P[v]].pb(P[u]);
        }
    }
    rep(i, n) V[i] = 0;

    dist(P[0], 0);
    ll farest = P[0];
    rep(i, n) if(D[farest] < D[P[i]]) farest = P[i];
    // cout<<"parto un dfs desde "<<farest<<'\n';
    rep(i, n) D[i] = -1;
    dist(farest, 0);
    rep(i, n) if(D[farest] < D[P[i]]) farest = P[i];

    // cout<<farest<<' '<<D[farest]<<'\n';
    cout<<(D[farest] + 1) / 2<<'\n';


    return 0;
}