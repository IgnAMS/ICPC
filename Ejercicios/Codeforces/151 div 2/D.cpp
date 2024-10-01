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

int n, m; 
vl G[100005];
ll C[100005];
vl X[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) {
        cin>>C[i];
        X[C[i]].pb(i);
    }

    rep(_, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); 
        G[v].pb(u);
    }

    ll best = -1, ans = 1;
    repx(k, 1, 100004) {
        set<ll> S;
        for(auto u: X[k]) {
            for(auto v: G[u]) if(C[v] != k) S.insert(C[v]);
        }
        if(X[k].size() and S.size() > best) best = S.size(), ans = k; 
    }
    cout<<ans<<'\n';

    return 0;
}