#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
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
int n, m, q;
vector<pll> G[mxN];
vector<vl> D(mxN, vl(mxN, 1e16));


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>q;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        D[u][v] = min(D[u][v], w);
        D[v][u] = min(D[v][u], w);
    }
    rep(i, n) D[i][i] = 0;

    rep(k, n) rep(i, n) rep(j, n) {
        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
    }
    
    
    while(q--) {
        int u, v; cin>>u>>v; u--, v--;
        cout<<(D[u][v] == 1e16? -1: D[u][v])<<"\n";

    }

    return 0;
}