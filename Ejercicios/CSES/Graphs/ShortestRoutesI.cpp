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

const int mxN = 1e5+5;
int n, m;
vector<pll> G[mxN];
vl D(mxN, 1e16);


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
    }

    D[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq; 
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        for(auto [v, w]: G[u]) if(D[v] > D[u] + w) {
            D[v] = D[u] + w;
            pq.push({D[v], v}); 
        }
    }
    rep(i, n) cout<<D[i]<<" "; cout<<"\n";

    
    return 0;
}