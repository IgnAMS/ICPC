#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
#define pb push_back

const ll M = 1e9+7, mxN = 1e6+5;

struct DSU{
    ll cc, p[mxN], sz[mxN];
    void init(int n){
        for(int i = 0; i<n; ++i){
            p[i] = i;
            sz[i] = 1;
        }
        cc = n;
    }
    int find(int x){
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    }
    void unite(int a, int b){
        a = find(a), b = find(b);
        if(a != b){
            cc--;
            if(sz[a] > sz[b]) swap(a, b);
            sz[b] += a;
            p[a] = b;
        }
    }
} dsu;

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = (res * a) % M;
        a = (a * a) % M;
        b >>= 1;
    }
    return res;
}

int n, m;
ll V[2 * mxN];
vl G[2 * mxN];
ll bipartito(ll u, ll col) {
    V[u] = col;
    for(auto v: G[u]) {
        // cout<<u<<" tiene color "<<V[u]<<" y "<<v<<" tiene color "<<V[v]<<'\n';
        if(V[v] == -1 and !bipartito(v, !col)) return 0;
        if(V[v] == V[u]) return 0; // No es bipartito
    }
    return 1;
}

void solve(){
    cin>>n>>m;
    rep(u, 2 * n) G[u].clear(), V[u] = -1;
    dsu.init(n);
    string s[n];
    vector<int> mp[m];
    rep(i, n) {
        cin>>s[i];
        rep(j, m) if(s[i][j] == '1') {
            mp[j].pb(i);
        }
    }
    rep(i, n) {
        G[i].pb(n + i);
        G[n + i].pb(i);
    }

    bool bad = 0;
    rep(i, (m + 1) / 2) {
        if(mp[i].size() + mp[m - i - 1].size() >= 3) {
            bad = true;
            break;
        }
        else if(mp[i].size() + mp[m - i - 1].size() <= 1)  {
            continue;
        }
        else {
            if(mp[i].size() == 2) {
                dsu.unite(mp[i][0], mp[i][1]);
                
                G[mp[i][0]].pb(mp[i][1]);
                G[mp[i][1]].pb(mp[i][0]);
            }
            else if(mp[i].size() == 1) {
                dsu.unite(mp[m - i - 1][0], mp[i][0]);
                G[mp[i][0]].pb(n + mp[m - i - 1][0]);
                G[n + mp[m - i - 1][0]].pb(mp[i][0]);
            }
            else {
                dsu.unite(mp[m - i - 1][0], mp[m - i - 1][1]);
                G[n + mp[m - i - 1][0]].pb(n + mp[m - i - 1][1]);
                G[n + mp[m - i - 1][1]].pb(n + mp[m - i - 1][0]);
            }
        }
    }

    // cout<<dsu.cc<<'\n';
    rep(u, 2 * n) if(V[u] == -1) {
        bad |= !bipartito(u, 0);
    }
    if(bad) {
        cout<<0<<"\n";
        return;
    }
    cout<<binpow(2LL, dsu.cc)<<"\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }

    return 0;
}