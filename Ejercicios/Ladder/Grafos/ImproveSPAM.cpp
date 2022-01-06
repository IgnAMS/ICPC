#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;

int n, l; 
//https://matcomgrader.com/problem/9643/improve-spam/

vector<vector<int>> G;
vector<ll> D;
ll A = 0;
ll mod = 1e9+7;


ll dfs1(int u){
    D[u] = 0;
    for(auto& v: G[u]){
        if(D[v] == -1) {
            D[u] = (D[u] + dfs1(v))%mod;
        }
        else {
            D[u] = (D[u] + D[v])%mod;
        }
    }
    if(G[u].size() == 0) { A++; D[u] = 1; }
    return D[u];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l;
    G.assign(n, {}); D.assign(n, -1);
    
    rep(i, l) {
        int k; cin>>k;
        rep(j, k) {
            int h; cin>>h; G[i].push_back(h - 1);
        }
    }
    cout<<dfs1(0)<<" "<<A<<"\n";



    return 0; 
}
