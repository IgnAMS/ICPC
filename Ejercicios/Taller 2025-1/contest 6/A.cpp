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

const int mxN = 1e5+5;
vector<pll> G[mxN];
vl D(mxN, 1e15);
vl P(mxN, -1);

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(i, m) {
        int u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
        G[v].pb({u, w});
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, 0});
    D[0] = 0;
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[u] < d) continue;
        for(auto [v, w]: G[u]) if(D[v] > D[u] + w) {
            D[v] = D[u] + w;
            P[v] = u;
            pq.push({D[v], v});
        }
    }
    if(D[n - 1] == 1e15) {
        cout<<"-1\n";
        return 0;
    }
    
    int curr = n - 1;
    vl X;
    while(curr != 0) {
        X.pb(curr);
        curr = P[curr];
    }
    X.pb(0);
    reverse(X.begin(), X.end());
    for(auto u: X) cout<<u + 1<<' '; cout<<'\n';



    return 0;
}