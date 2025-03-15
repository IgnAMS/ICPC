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
ll Cont[mxN];
pll Best[mxN];
map<ll, pll> mp; // u -> [{v, ind}]
vl G[mxN];


pll init(ll u, ll d, ll p) {
    if(G[u].size() == 1) {
        D[u] = d;
        Best[u] = {u, D[u]};
        Cont[u]++;
        return {u, D[u]};
    }
    pll best = {mxN, 1e10};
    D[u] = d;
    for(auto [v, w]: G[u]) if(v != p) {
        pll op = dfs(v, d + w, u);
        op.ss -= d;
        best = min(best, op);
    }
    Best[u] = best;
    Cont[best.ff]++;
    return best;
}


pll reroot(ll u, ll d, ll p, pll prev) {
    pll best = prev;
    if(Best[u].ff != prev.ff) {
        best = min(prev, Best[u]);
    }
    else {
        for(auto v: G[u]) if(v != p) {
            if()
        }
    }
    for(auto [v, ])
    for(auto v: G[u]) if(v != p) {
        reroot(u, d, p, best);
    }
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);






    return 0;
}