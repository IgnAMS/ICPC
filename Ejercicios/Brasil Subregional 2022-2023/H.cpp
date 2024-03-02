#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define rep(i, n) for(int i = 0; i<(int)n; ++i)

const int mxN = 1e4+5;
int n, m, who[mxN], in[mxN], out[mxN], minima = 0, maxima = 0, cc = 0;
vector<int> adj[mxN], adjr[mxN], adj2[mxN];
bool used[mxN];
vector<int> order, component, root_nodes;

void dfs1(int v){
    used[v] = true;
    for(auto u : adj[v]){
        if(!used[u]){
            dfs1(u);
        }
    }
    order.push_back(v);
}

void dfs2(int v){
    used[v] = true;
    component.push_back(v);
    for(auto u : adjr[v]){
        if(!used[u]){
            dfs2(u);
        }
    }
}

void dfs3(int v){
    used[v] = true;
    if(in[v] == 0){
        maxima++;
    }
    if(out[v] == 0){
        minima++;
    }
    for(auto u : adj2[v]){
        if(!used[u]){
            dfs3(u);
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    rep(i, m){
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adjr[b].push_back(a);
    }
    rep(i, n){
        if(!used[i]){
            dfs1(i);
        }
    }
    reverse(order.begin(), order.end());
    memset(used, 0, sizeof(used));
    for(int v : order){ 
        if(!used[v]){
            dfs2(v);
            int root = component.front();
            for(int u : component){
                who[u] = root;
            }
            root_nodes.push_back(root);
            component.clear();
            cc++;
        }
    }
    rep(v, n){
        for(auto u : adj[v]){
            int root_v = who[v];
            int root_u = who[u];
            if(root_v != root_u){
                in[root_u]++;
                out[root_v]++;
                adj2[root_u].push_back(root_v);
                adj2[root_v].push_back(root_u);
            }
        } 
    }
    memset(used, 0, sizeof(used));
    rep(i, n){
        if(!used[who[i]]){
            dfs3(who[i]);
        }
    }
    if(cc == 1){
        cout << "0\n";
        return 0;
    }
    cout << max(minima, maxima);
}