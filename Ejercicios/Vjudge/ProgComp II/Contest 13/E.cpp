#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;
vector<ll> dp;
int n,l; 
int mod=1e9+7;

ll dfs(int u){
    //cerr<<u<<"\n";
    if(dp[u]!=-1) return dp[u];
    if(u>=l) return dp[u]=1;
    dp[u]=0;
    for(auto& v: g[u]) dp[u]= ((dp[u]+dfs(v))%mod+mod)%mod;
    cerr<<u<<" "<<dp[u]<<"\n";
    return dp[u];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>l;
    
    g.assign(n,{}); dp.assign(n,-1);
    rep(i,l){
        int k; cin>>k;
        rep(j,k){    
            int u; cin>>u; u--;
            g[i].push_back(u);
        }
    }
    ll ans=dfs(0);
    ll ans2=0;
    rep(i,n-l) ans2+= dp[i+l]!=-1? 1:0; 
    cout<<ans<<" "<<ans2<<"\n";



    return 0;
}