#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;
#define rep(i, n) for(int i = 0; i < n; i++)

const int mxN = 1e5+5, M = 1e9+7;
ll n, c[mxN], dp[mxN][2];
vector<int> adj[mxN];

void dfs(int u = 0, int p = -1){
    dp[u][c[u]] = 1;
    for(int v : adj[u]){
        if(v != p){
            dfs(v, u);
            dp[u][1] = dp[v][0]*dp[u][1] + dp[v][1]*dp[u][0];
            dp[u][1] %= M;
            dp[u][0] = dp[v][0]*dp[u][0];
            dp[u][0] %= M;
            
        }
    }
    dp[u][0] += dp[u][1];
    dp[u][0] %= M;
}

int main(){
    cin >> n;
    memset(dp, 0, sizeof(dp));
    rep(i, n-1){
        int x;
        cin >> x;
        adj[i+1].push_back(x);
        adj[x].push_back(i+1);
    }
    rep(i, n){
        cin >> c[i];
    }
    dfs();
    
    cout << dp[0][1];

}


