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
vl G[mxN], G2[mxN];
ll C[mxN];
ll P[mxN][2];

int id = 1;
void dfs(int u, int b) {
    P[u][b] = id;
    for(auto v: G[u]) if(C[v] == b and !P[v][b]) dfs(v, b);
}


ll D[mxN];
void dist_dfs(int u, int d) {
    D[u] = d;
    for(auto v: G2[u]) if(D[v] == -1) {
        dist_dfs(v, d + 1);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n) cin>>C[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    rep(b, 2) rep(u, n) {
        if(C[u] == b and !P[u][b]) dfs(u, b), id++;
    }
    rep(u, n) for(auto v: G[u]) if(C[u] != C[v]) {
        G2[P[u][C[u]]].pb(P[v][C[v]]);
    }
    rep(u, id) D[u] = -1;
    dist_dfs(1, 0);
    int mx_ind = 1;
    repx(u, 1, id) if(D[u] > D[mx_ind]) mx_ind = u;
    
    rep(u, id) D[u] = -1;
    dist_dfs(mx_ind, 0);
    repx(u, 1, id) if(D[u] > D[mx_ind]) mx_ind = u;
    
    ll d = D[mx_ind];
    cout<<(d + 1) / 2<<'\n';


    return 0;
}