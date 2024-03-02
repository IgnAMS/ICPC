#pragma GCC optimize("O3")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 1e6+5;

ll n, m; vl val;
vector<vector<pll>> adj;
vector<vector<pll>> adj2;
vector<vl> G;

vector<int> D, L, I, who; stack<int> S;
int id = 0, comps = 0;
void componentes(int u) {
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for(auto &v: G[u]) {
        if(D[v] == -1) { componentes(v); L[u] = min(L[v], L[u]); }
        else if(I[v]) L[u] = min(L[u], L[v]);
    }
    if(L[u] == D[u]) {
        // SCC
        while(1) {
            int x = S.top(); S.pop(); I[x] = 0;
            who[x] = comps;
            if(x == u) break;
        }
        comps++;
    }
}

void find_sccs(int n) {
    D.assign(n, -1); L.resize(n); I.assign(n, 0);
    id = 0; rep(u, n) if(D[u] == -1) componentes(u);
}

ll dp[mxN];

ll dfs3(int u){
    if(dp[u] != -1) return dp[u];
    dp[u] = val[u];
    for(auto v : adj2[u]) {
        dp[u] = max(dp[u], val[u] + v.first + dfs3(v.second));
    }
    return dp[u];
}

vl sum, sum2;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    adj.assign(n, vector<pll>());
    who.resize(n); G.assign(n, vl());
    sum.push_back(0);
    sum2.push_back(0);
    for(ll i = 1; i <= 1000002; ++i) {
        sum2.push_back(sum2.back() + (i*(i+1))/2);
        sum.push_back(sum.back() + i);
    }

    rep(i, m){
        ll a, b, c; cin >> a >> b >> c; a--, b--;
        adj[a].push_back(pll(c, b));
        G[a].push_back(b);
    }

    find_sccs(n);

    adj2.assign(comps + 2, vector<pll>());
    val.resize(comps + 2, 0);
    rep(v, n) {
        for(pll &u : adj[v]){
            int root_v = who[v];
            int root_u = who[u.second];
            if(root_u != root_v) {
                adj2[root_v].push_back({u.first, root_u});
            }
            else {
                ll id2 = prev(upper_bound(sum.begin(), sum.end(), u.ff)) - sum.begin();
                // cout<<u.ff<<' '<<id2<<' '<<sum2[id2]<<'\n';
                val[root_u] += u.first * ll(id2+1) - sum2[id2];
            }
        }
    }

    int mccari;
    cin >> mccari; --mccari;
    memset(dp, -1, sizeof(dp));
    cout << dfs3(who[mccari])<<'\n';
    return 0;
}