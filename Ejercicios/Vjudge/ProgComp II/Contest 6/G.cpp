#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;
vector<int> D,L;
int id=0;
int root=0;
set<int> ans;

void dfs(int u, int p, int d){
    D[u]=L[u]=d;
    for(int v : g[u]){
        if(v==p) continue;
        if(D[v]==-1){
            dfs(v,u,d+1);
            if(p==-1){
                if(++root==2) ans.insert(u);
            }
            else if(L[v]>=d) ans.insert(u);
            L[u]=min(L[u],L[v]);
        }
        else if(D[v]<d) L[u]=min(L[u],D[v]);
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    while(cin>>n>>m){ 
        if(n==0 && m==0) break;
        ans.clear();
        D.assign(n,-1); L.resize(n);
        g.assign(n,{});
        rep(i,m){
            int u, v; cin>>u>>v; u--, v--;
            g[u].emplace_back(v); g[v].emplace_back(u);
        }
        rep(u,n) if(D[u]==-1) root=0, dfs(u,-1,0);

        cout<<ans.size()<<"\n";
    }




    return 0;
}