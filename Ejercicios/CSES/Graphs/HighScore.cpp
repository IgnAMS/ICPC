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

const int mxN = 2510;
int n, m, q;
vector<array<ll, 3>> E;
vl D(mxN, 1e16);
vector<pll> G[mxN];

bool V[mxN][mxN];
void dfs(int u, int first) {
    V[first][u] = 1;
    for(auto [v, w]: G[u]) if(!V[first][v]) dfs(v, first);
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        E.pb({u, v, -w});
        G[u].pb({v, w});
    }
    rep(i, n) dfs(i, i);
    
    D[0] = 0;
    bool neg_cycle = 1;
    rep(i, n) {
        bool any = 0;
        for(auto [u, v, w]: E) if(V[0][u] and V[v][n - 1]) {
            if(D[u] < 1e16 and D[v] > D[u] + w) {
                any = 1;
                D[v] = D[u] + w;
            }
        }
        if(not any) {
            neg_cycle = 0;
            break;
        }
    }
    if(neg_cycle) cout<<"-1\n";
    else cout<<-D[n-1]<<"\n";



    return 0;
}