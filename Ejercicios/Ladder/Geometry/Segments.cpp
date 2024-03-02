#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=(int)a; i<(int)b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct Segment {
    int a, b, h;
};

bool bellmanFord(vector<vector<pll>>& G, int start) {
    int n = G.size();
    int D[n];
    rep(u, n) D[u] = 1e9;
    D[start] = 0;
    rep(i, n - 1) rep(u, n) for(auto e: G[u]) {
        int v = e.ff, w = e.ss;
        D[v] = min(D[v], D[u] + w);
    }
    bool negative = 0;
    rep(u, n) for(auto e: G[u]) {
        int v = e.ff, w = e.ss;
        if(D[v] > D[u] + w) negative = 1;
    }
    return !negative;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    Segment X[n];
    rep(i, n) cin >> X[i].a >> X[i].b >> X[i].h;
    set<ll> S;
    rep(i, n) {
        S.insert(X[i].a);
        S.insert(X[i].b);
    }
    map<ll, ll> mp;
    for(auto u: S) {
        mp[u] = mp.size() + 1;
    }
    
    rep(i, n) {
        X[i].a = 2 * mp[X[i].a], X[i].b = 2 * mp[X[i].b] - 1;
    }

    int M = mp.size() + 2;
    int l = 0, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        vector<vector<pll>> G(2 * M + 1, vector<pll>());
        
        rep(i, 2 * M) G[0].pb({i + 1, 0});
        repx(i, 1, 2 * M) G[i + 1].pb({i, 0});
        rep(i, n) G[X[i].a].pb({X[i].b, m});
        rep(i, n) G[X[i].b].pb({X[i].a, -1});
        
        if(bellmanFord(G, 0)) r = m;
        else l = m + 1;
    }
    cout<<l<<'\n';
    return 0;
}