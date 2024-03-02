#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll, ll> pll;
#define rep(i, n) for(int i = 0; i < n; i++)
#define repx(i, a, b) for(int i = a; i < b; i++)
#define ff first
#define ss second

const int mxN = 2e5+5, LG = 22;

struct RT {
    ll n, par[2*mxN], sp[LG+1][2*mxN], val[2*mxN], rid[2*mxN];
    ll T, st[2*mxN], en[2*mxN];
    vector<int> g[mxN];
    int find(int x) {
        if(par[x] == x) return x;
        return par[x] = find(par[x]);
    }
    void dfs(int u){
        st[u] = T+1;
        for(int v : g[u]){
            sp[0][v] = u;
            dfs(v);
        }
        if(st[u] == T+1){
            rid[T+1] = u;
            T++;
        }
        en[u] = T;
    }

    void build(vector<array<ll, 3>> e) { // {w, u, v}
        in tn = e.size() + 1;
        sort(e.begin(), e.end());
        for(int x = 1; x<2*n; x++) {
            par[x] = x;
            g[x].clear();
            val[x] = 0;
            sp[0][x] = 0;
        }
        for(int i = 0; i+1<n; ++i) {
            int u = e[i][1], v = e[i][2];
            ll w = e[i][0];
            u = find(u), v = find(v);
            int id = n+i+1;
            par[u] = par[v] = id;
            val[id] = w;
            g[id].push_back(u);
            g[id].push_back(v);
        }
        val[0] = 1e18;
        T = 0;
        dfs(2*n-1);
        for(int k = 1; k<=LG; ++k){
            for(int u = 1; u<2*n; ++u){
                sp[k][u] = sp[k-1][sp[k-1][u]];
            }
        }
    }
    ll lift(int u, ll x){
        for(int k = LG; k>=0; --k) if(val[sp[k][u]] <= x) u = sp[k][u];
        return u;
    }
} rt;

int main() {
    
}