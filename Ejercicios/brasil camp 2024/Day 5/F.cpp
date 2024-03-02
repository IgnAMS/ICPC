#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 5e3+5;
vl G[mxN], Comp[mxN][2];
ll V[mxN], X[mxN];
ll cont = 0, cont0 = 0, id = 0;
ll D[mxN][2], DP[mxN][mxN];


ll dp(ll i, ll x) {
    if(x < 0) return -1;
    if(i == -1 and x == 0) return 0;
    if(i == -1) return -1;
    
    if(DP[i][x] != -2) return DP[i][x];
    
    DP[i][x] = -1;
    if(dp(i - 1, x - D[i][0]) >= 0) DP[i][x] = 0;
    if(dp(i - 1, x - D[i][1]) >= 0) DP[i][x] = 1;
    return DP[i][x];
}


bool dfs(ll u, ll p, ll x) {
    V[u] = 1;
    X[u] = x;
    cont0 += (x == 0);
    cont++;
    Comp[id][x].pb(u);
    for(auto v: G[u]) if(v != p) {
        if(!V[v]) dfs(v, u, x^1);
        if(X[v] != (x ^ 1)) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll n1, n2, n3; cin>>n1>>n2>>n3;
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }

    bool pos = 1;
    memset(V, 0, sizeof(V));
    rep(u, n) if(!V[u]) {
        cont = 0, cont0 = 0;
        if(!dfs(u, -1, 0)) pos = 0;
        else {
            D[id][0] = cont0;
            D[id][1] = cont - cont0;
            // cout<<"en el nodo "<<u<<" el color es "<<D[id][0]<<' '<<D[id][1]<<'\n';
            id++;
        }
    }
    
    rep(i, id) rep(j, n2 + 1) DP[i][j] = -2;
    if(dp(id - 1, n2) == -1 or !pos) {
        cout<<"NO\n";
        return 0;
    }
    int ind = id - 1, x = n2;
    while(ind >= 0) {
        ll col = dp(ind, x);
        for(auto u: Comp[ind][col]) X[u] = 2;
        for(auto u: Comp[ind][col ^ 1]) X[u] = 1;
        x -= D[ind][col];
        ind -= 1;
    }

    ll cont1 = 0, cont2 = 0, cont3 = 0;
    rep(u, n) {
        if(X[u] == 1 and cont1 < n1) X[u] = 1, cont1++;
        else if(X[u] == 1 and cont1 == n1) X[u] = 3, cont3++;
        else if(X[u] == 0) X[u] = 2, cont2++;
    }


    cout<<"YES\n";
    rep(u, n) cout<<X[u]; cout<<'\n';

    return 0;
}