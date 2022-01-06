#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;

struct LCA{
    vector<vector<int>> up;
    vector<int> D;
    int n, l;
    LCA(int a){
        n=a;
        l=log2(n)+1;
        up.assign(n,vector<int>(l));
        D.assign(n,-1 );
        dfs(0,-1,0);
        for(int e=1;e<l;e++){
            rep(u,n){
                int x=up[u][e-1];
                up[u][e]= x==-1? -1:up[x][e-1];
            }
        }
    }

    int raise(int u, int k){
        for(int e=0;k;e++,k>>=1) if (k&1) u=up[u][e];
        return u;
    }
    
    void dfs(int u,int p, int d){
        cout<<"estor exlporando a "<<u<<"\n"; 
        up[u][0]=p;
        D[u]=d;
        for(auto& v: g[u]) dfs(v,u,d+1);
    }

    int lca(int u, int v){
        if(D[u]<D[v]) swap(u,v);
        u=raise(u,D[u]-D[v]);
        if(u==v) return u;
        for(int e=l-1; e>=0;e--)
            if(up[u][e]!=up[v][e]) u=up[u][e],v=up[u][e];
        return up[u][0];
    }


};


int main(){
    int t; cin>>t;
    rep(cas,t){
        cout<<"Case "<<cas+1<<":\n";
        int n,m; cin>>n;
        g.assign(n,vector<int>());
        rep(u,n){
            cin>>m;
            int v;
            rep(j,m) {cin>>v; g[u].push_back(v-1);}
        }
        int q; cin>>q;
        LCA low=LCA(n);
        while(q--){
            int u,v; cin>>u>>v;
            cout<<low.lca(u-1,v-1)+1    <<"\n";
        }
    }




    return 0;
}