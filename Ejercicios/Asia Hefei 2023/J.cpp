#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;

#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back

typedef long long ll;
typedef pair<ll, ll> pll;


const ll INF = 1e10;
const int mxN = 3e5 + 5;
vector<pll> G[mxN];

ll D[2][mxN];
ll P[2][mxN];
int n, m; 

void Dijkstra(ll s) {
    ll b = (s == n - 1);
    rep(i, n) D[b][i] = INF;
    D[b][s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0, s});
    while(!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if(D[b][u] < d) continue;
        for(auto [v, w]: G[u]) {
            if(D[b][v] > max(w, d)) if((s == 0 and v != n - 1) or (s == n - 1 and v != 0)) {
                D[b][v] = max(w, d);
                pq.push({D[b][v], v});
            }
        }
    }
}


int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    ll ans = INF;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        if(min(u, v) == 0 and max(u, v) == n - 1) {
            ans = min(ans, w);

        }
        G[u].pb({v, w}); G[v].pb({u, w});
    }

    Dijkstra(0), Dijkstra(n - 1);

    rep(u, n) {
        for(auto [v, w]: G[u]) {
            if(max(D[0][u], D[1][v]) <= w) ans = min(ans, w + max(D[0][u], D[1][v]));
            if(max(D[1][u], D[0][v]) <= w) ans = min(ans, w + max(D[1][u], D[0][v]));
        }
    }

    cout<<ans<<'\n';

    return 0;
}

