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
// g++ -std=c++17 A.cpp -o a && ./a <input.txt> output.txt   
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
int n, m;
vector<vl> D(mxN, vl(2, 1e16));
vector<pll> G[mxN];



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
    }

    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
    D[0][0] = 0;
    pq.push({0, 0, 0});
    while(!pq.empty()) {
        auto [d, u, t] = pq.top(); pq.pop();
        if(D[u][t] < d) continue;
        for(auto [v, w]: G[u]) {
            if(t == 0 and D[v][1] > D[u][0] + (w / 2)) {
                D[v][1] = D[u][0] + (w / 2);
                pq.push({D[v][1], v, 1});
            }
            if(D[v][t] > D[u][t] + w) {
                D[v][t] = D[u][t] + w;
                pq.push({D[v][t], v, t});
            }
        }
    }
    cout<<D[n-1][1]<<"\n";

    return 0;
}