#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef unsigned long long ull;
 
vector<int> s,D,L;
vector<bool> instack;
vector<vector<ll>> g;
vector<ll> weight;
int n;
ll mod = 1e9+7, tcost = 0, tcant = 1;
ll id;
 
void dfs(int u, int d){
    D[u] = L[u] = id++;
    instack[u] = true;
    s.push_back(u);
    ll cost = 1e10, cant = 1;
 
    for(ll& v : g[u]) {
        if(D[v] == -1) {
            dfs(v, d + 1);
            L[u] = min(L[v], L[u]);
        }
        else if(instack[v]) L[u] = min(L[u], L[v]);
    }
 
    if(L[u] == D[u]){ //root
        cost = 1e10, cant = 1;
        while(1){
            int x = s.back(); s.pop_back();
            instack[x] = false;
            if(weight[x] < cost){
                cost = weight[x];
                cant = 1;
            }
            else if(weight[x] == cost) cant++;
 
            if(x == u){
                tcant = (tcant * cant) % mod;
                //cout<<cost<<"\n";
                tcost += cost;
                break;
            }
        }
    }
}
 
 
 
int main(){
    cin>>n;
    weight.resize(n);
    g.assign(n, vector<ll>());
    D.assign(n,-1);
    L.resize(n);
    instack.assign(n,0);
    rep(i,n) cin>>weight[i];
    
    int m; cin>>m;
    int u, v;
    rep(i,m){
        cin>>u>>v; u--, v--;
        g[u].push_back(v);
    }
    id = 0;
    rep(i,n) if(D[i] == -1) dfs(i, 0);
    cout<<tcost<<" "<<tcant<<"\n";
 
 
    return 0;
}