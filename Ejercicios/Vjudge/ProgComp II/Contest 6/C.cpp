#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;
vector<set<int>> G;
vector<ll> D,L,S,C,W,w,DP;
vector<bool> I;
int n, m, s, t, id=0, numC=0;

void dfs(int u){
    D[u]=L[u]=++id;
    I[u]=true;
    S.push_back(u);
    for(auto v: g[u]){
        if(D[v]==-1){
            dfs(v);
            L[u]=min(L[u],L[v]);
        }
        else if(I[v]) L[u]=min(L[u],L[v]);
    }
    if(L[u]==D[u]){
        W.push_back(0);
        while(1){
            int x=S.back(); S.pop_back();
            I[x]=false;
            C[x]=numC;
            W[numC]+=w[x];
            if(u==x) break;
        }
        // cout<<"la componente en "<<u<<" tiene una ganancia de "<<W[numC]<<"\n";
        numC++;
    }
}

ll dp(int u){
    if(DP[u] != -1) return DP[u];
    if(u==C[t]) return DP[u]=W[u];
    //cout<<DP[u]<<" estoy visitando a "<<u<<"\n";
    DP[u]=-2;
    for(auto v : G[u]){
        if(DP[v]==-1){
            ll op=dp(v);
            if(op!=-2) DP[u]=max(dp(v),DP[u]);
        }
        else if(DP[v]!=-2) DP[u]=max(DP[v],DP[u]);
    }
    if(DP[u]!=-2) DP[u]+=W[u];
    // cout<<DP[u]<<"\n";
    return DP[u];
}

int u, v; 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>s>>t; s--, t--;
    D.assign(n,-1); L.resize(n); I.assign(n,0);
    w.resize(n); g.resize(n); C.resize(n); 
    rep(i,n) cin>>w[i];
    rep(i,m){
        cin>>u>>v; u--,v--;
        g[u].push_back(v);
    }

    dfs(s);
    G.resize(numC);
    DP.assign(numC,-1);
    rep(u,n)
        for(auto v: g[u])
            G[C[u]].insert(C[v]);
    
    ll ans=dp(C[s]);
    cout<<ans<<"\n";
    // cout<< ll(dp(C[s])+W[C[s]]) << "\n";

    return 0;
}
