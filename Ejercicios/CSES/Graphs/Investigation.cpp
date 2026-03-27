#pragma GCC optimize("Ofast")
#include<string.h>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<iostream>
#include <algorithm>
#include<set>
#include<array>
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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 Investigation.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vector<pll> G[mxN];
ll P[mxN];
ll D[mxN];
ll DP[3][mxN];
const ll INF = 1e7;
const ll MOD = 1e9+7;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
    }

    priority_queue<pll, vector<pll>, greater<pll>> pq;
    rep(i, n) {
        D[i] = 1e16;
        // DP[0]: cantidad de caminos para llegar a u
        // DP[1]: Minima cantidad de caminos para llegar a u con costo mínimo
        // DP[2]: Máxima cantidad de caminos para llegar a u con costo máximo
        DP[0][i] = 1;
        DP[1][i] = 0;
        DP[2][i] = 0;
    }
    D[0] = 0;
    pq.push({D[0], 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        for(auto [v, w]: G[u]) {
            if(D[v] > D[u] + w) {
                D[v] = D[u] + w;
                DP[0][v] = DP[0][u];
                DP[1][v] = DP[1][u] + 1;
                DP[2][v] = DP[2][u] + 1;
                pq.push({D[v], v});
            }
            else if(D[v] == D[u] + w) {
                DP[0][v] += DP[0][u];
                if(DP[0][v] >= MOD) DP[0][v] -= MOD;
                DP[1][v] = min(DP[1][v], DP[1][u] + 1);
                DP[2][v] = max(DP[2][v], DP[2][u] + 1);
            }
        }
    }
    cout<<D[n-1]<<" "<<DP[0][n-1]<<" "<<DP[1][n-1]<<" "<<DP[2][n-1]<<"\n";


    return 0;
}