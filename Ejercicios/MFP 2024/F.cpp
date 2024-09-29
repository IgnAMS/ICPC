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

int n, m, s, t; 
vector<pll> G[200005];

ll V[200005];
bool reach(ll u, ll mxw) {
    if(u == t) return 1;
    // cout<<"llegue a "<<u<<" con "<<mxw<<'\n';
    V[u] = 1;
    for(auto [v, w] : G[u]) {
        if(w >= mxw and !V[v] and reach(v, mxw)) 
            return 1;
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>s>>t; s--, t--;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        G[u].pb({v, w});
    }

    ll l = -1, r = 1e9;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        rep(i, n) V[i] = 0;
        if(reach(s, m)) l = m;
        else r = m - 1;
    }
    cout<<l<<'\n';

    return 0;
}