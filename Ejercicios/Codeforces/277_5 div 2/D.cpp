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


vl G[3000], invG[3000];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(_, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        invG[v].pb(u);
    }

    ll ans = 0;
    rep(u, n) {
        vl B(n, 0);
        for(auto& v: G[u]) B[v] = 1;

        // 30000
        rep(v, n) if(v != u) {
            ll cnt = 0;
            for(auto& v2: invG[v]) cnt += B[v2];
            ans += cnt * (cnt - 1) / 2;
        }
    }

    cout<<ans<<'\n';

    return 0;
}