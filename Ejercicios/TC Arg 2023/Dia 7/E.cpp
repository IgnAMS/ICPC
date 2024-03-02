#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define ff first
#define ss second
#define rep(i, n) for(int i = 0; i < n; i++)

int n, m, who[mxN];
vector<int> order, component, root_nodes;
vector<pair<ll, ll>> adj[mxN], adj_rev[mxN], adj2[mxN];
bool vis[mxN];
ll val[mxN];

void dfs1(int u){
    vis[u] = true;
    for(auto v : adj[u]){
        if(!vis[v.second]){
            dfs1(v.second);
        }
    }
    order.push_back(u);
}

void dfs2(int u){
    vis[u] = true;
    component.push_back(u);
    for(auto v : adj_rev[u]){
        if(!vis[v.second]){
            dfs2(v);
        }
    }
}

vector<ll> sum;

int main() {
    cin >> n >> m;
    sum.push_back(0);
    for(int i = 1; i<=50000){
        sum.push_back(sum.back() + (i*(i+1))/2);
    } 
    rep(i, m){
        ll a, b, c;
        cin >> a >> b >> c, --a, --b;
        adj[a].push_back({c, b});
        adj_rev[b].push_back({c, a});
    }
    rep(i, n){
        if(!vis[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(vis, 0, sizeof(vis));
    for(int v : order){
        if(!vis[v]){
            dfs2(v);
            int root = component.front();
            for(int u : component){
                who[u] = root;
            }
            root_nodes.push_back(root);
            component.clear();
        }
    }
    rep(v, n){
        for(auto u : adj[v]){
            int root_v = who[v];
            int root_u = who[u.second];
            if(root_u != root_v){
                adj2[root_v].push_back({u.first, root_u});
            }else{
                ll value = *prev(upper_bound(sum.begin(), sum.end(), u.first))
                val[root_u] +
            }
        }
    }
}