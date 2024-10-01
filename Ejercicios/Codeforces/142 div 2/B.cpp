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

struct Edge {
    ll v, c;
};

const int mxN = 1e5+5;
vector<Edge> G[mxN];
const ll INF = 1e15;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        ll u, v, c; cin>>u>>v>>c; u--, v--;
        G[u].pb({v, c}); G[v].pb({u, c});
    }

    set<ll> S[n];
    rep(i, n) {
        int k; cin>>k;
        while(k--) {
            ll t; cin>>t;
            S[i].insert(t);
        }
    }

    vl D(n, INF);
    D[0] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        
        while(S[u].count(d)) d++;
        for(auto [v, w]: G[u]) if(D[v] > w + d) {
            D[v] = w + d;
            pq.push({D[v], v});
        }
    }
    if(D[n - 1] == INF) { 
        cout<<"-1\n";
    }
    else cout<<D[n - 1]<<'\n';




    return 0;
}