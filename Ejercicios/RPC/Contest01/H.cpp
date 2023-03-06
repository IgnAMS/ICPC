#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define repx(i,a,b) for(int i = a; i < b;i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second

const int mxn = 3e5+10;
vl L;
ll D[mxn], I[mxn];
vl G[mxn];
void dfs(ll u, ll d, ll pos) {
    // cerr<<"estoy visitando a "<<u<<' '<<d<<'\n';
    D[u] = d;
    I[u] = pos;
    rep(i, G[u].size()) dfs(G[u][i], (d * ll(G[u].size()) > mxn? mxn: d * G[u].size()), pos + d * i);
    if(G[u].size() == 0) L.push_back(u);
}
//

int main() {
    int n, q; cin>>n>>q;
    rep(i, n - 1) {
        int p; cin>>p;
        G[p].push_back(i + 1);
    }
    dfs(0, 1, 0);
    ll Ans[q];
    for(auto u: L) {
        for(int i = 0; I[u] + i * D[u] < q; i++) Ans[I[u] + i * D[u]] = u;
    }
    // for(auto u: L) cout<<u<<' '<<I[u]<<' '<<D[u]<<'\n'; cout<<'\n';
    rep(i, q) cout<<Ans[i]<<'\n';
}