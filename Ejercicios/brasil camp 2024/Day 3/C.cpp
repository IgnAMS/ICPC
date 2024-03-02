#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

ll INF = 1e16;
vector<pll> G[100005];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    ll A[n]; rep(i, n) cin>>A[i];

    rep(i, m) {
        ll u, v, d; cin>>u>>v>>d; 
        u--, v--;
        G[u].pb({v, d});
        G[v].pb({u, d});
    }
    
    vl D(n, INF), C(n, 0);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    rep(i, n) if(A[i] == 1) {
        D[i] = 0, C[i] = i + 1;
        pq.push({0, i});
    }
    
    while(!pq.empty()) {
        ll u = pq.top().ss, d = pq.top().ff; 
        // cout<<u<<' '<<d<<'\n';
        pq.pop();
        if(D[u] < d) continue;
        for(auto e: G[u]) {
            ll v = e.ff, w = e.ss;
            if(D[v] > D[u] + w) {
                C[v] = C[u];
                D[v] = D[u] + w;
                pq.push({D[v], v});
            }
        }
    }
    
    ll ans = INF;
    set<ll> S;
    rep(u, n) for(auto e: G[u]) {
        ll v = e.ff, w = e.ss;
        if(C[u] != 0 and C[v] != 0 and C[u] != C[v] and ans > D[u] + w + D[v]) {
            ans = D[u] + w + D[v];
            S.clear();
            S.insert(C[u]); S.insert(C[v]);
        }
        // else if(C[u] != 0 and C[v] != 0 and C[u] != C[v] and ans == D[u] + w + D[v]) {
        //     S.insert(C[u]); S.insert(C[v]);
        // }
    }

    if(ans == INF) cout<<"No luck at all\n";
    else {
        cout<<ans<<'\n';
        for(auto u: S) cout<<u<<' '; cout<<'\n';
    }


    return 0;
}