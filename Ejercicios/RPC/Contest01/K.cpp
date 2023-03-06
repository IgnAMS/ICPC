#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 2e5+5, M = 1e9+7;
ll n, m, up[20][mxN], d[mxN];
vector<ll> adj[mxN];
priority_queue<ar<ll, 3>, vector<ar<ll, 3>>, greater<ar<ll, 3>>> pq;
bool vis[mxN];

int lca(int a, int b){
    if(d[a]<d[b]) swap(a, b);
    int diff = d[a]-d[b];
    for(int i = 0; i<20; ++i){
        if(diff & (1<<i)){
            a = up[i][a];
        }
    }
    if(a == b){
        return a;
    }
    for(int i = 19; i>=0; --i){
        if(up[i][a] != up[i][b]){
            a = up[i][a];
            b = up[i][b];
        }
    }
    return up[0][a];
}

ll dist(ll a, ll b){
    return d[a]+d[b]-2*d[lca(a, b)];
}

int main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
    
    memset(d, 0x3f, sizeof(d));
    memset(up, -1, sizeof(up));
    cin >> n >> m;
    rep(i, m){
        ll a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int act = 0;
    ll ans = 0;
    pq.push({0, 0, 0});
    d[0] = 0;
    //cout << act << " ";
    while(pq.size()){
        ar<ll, 3> u = pq.top();
        pq.pop();
        if(vis[u[1]]) continue;
        vis[u[1]] = true;
        d[u[1]] = u[0];
        
        up[0][u[1]] = u[2];
        for(int i = 1; i<20; ++i){
            up[i][u[1]] = up[i-1][up[i-1][u[1]]];
        }
        //cout << dist(act, u[1]) << " " << act << " " << u[1] << " " << lca(act, u[1]) << '\n';
        ans += dist(act, u[1]);
        act = u[1];
        //cout << act << " ";
        for(int v : adj[u[1]]){
            pq.push({d[u[1]]+1, v, u[1]});
        }
    }
    //ans += dist(act, 0);
    cout << ans << "\n";

}