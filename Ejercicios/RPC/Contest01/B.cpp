#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define repx(i,a,b) for(int i = a; i < b;i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second

int main() {
    int n, m; cin>>n>>m;
    vector<vector<pll>> G(n + 2, vector<pll>());
    ll A[n];
    rep(i, n) {
        ll x; cin>>x;
        A[i] = x;
        G[n].push_back({i, x});
        G[i].push_back({n, x});
    }
    rep(i, m) {
        ll u, v, x; cin>>u>>v>>x;
        G[u].push_back({v, x});
        G[v].push_back({u, x});
    }   
    vl D(n + 2, 1e17);
    vl P(n + 2, -1);
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    set<vl> PQ;
    PQ.insert({0, n, -1});
    ll ans = 1e17;
    while(!PQ.empty()) {
        vl x = *PQ.begin(); PQ.erase(PQ.begin());
        ll u, d, p; u = x[1], d = x[0], p = x[2];
        if(D[u] < d) continue;
        // cerr<<"estoy visitando a "<<u<<" con "<<d<<' '<<ans<<'\n';
        if(u == n) P[u] = n;
        else if(p == n) P[u] = u;
        else P[u] = P[p];
        for(auto& e: G[u]) {
            // cerr<<u<<' '<<e.ff<<' '<<P[e.ff]<<' '<<P[u]<<' '<<A[e.ff]<<'\n';
            if(e.ff != n and u != n and P[e.ff] != P[u]) {
                // cerr<<u<<' '<<e.ff<<'\n';
                // cerr<<d + A[e.ff] + e.ss<<'\n';
                ans = min(ans, d + A[e.ff] + e.ss);
            }
            if(e.ff != n and u != n and P[e.ff] != -1 and P[e.ff] != P[u]) {  
                // cerr<<u<<' '<<e.ff<<' '<<P[e.ff]<<'\n';
                // cerr<<d + D[e.ff] + e.ss<<'\n';
                ans = min(ans, d + D[e.ff] + e.ss);
            }
            if(d + e.ss < D[e.ff]) {
                D[e.ff] = d + e.ss;
                PQ.insert({D[e.ff], e.ff, P[u]});
            }
        }
    }
    cout<<ans<<'\n';



    return 0;
}


