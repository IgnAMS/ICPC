#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second
typedef pair<ll,ll> ii;

vector<vector<ii>> g;

struct edge{
    ll u,v,w;
    edge(ll u,ll v,ll w): u(u), v(v), w(w){}
};

struct MST{
    int n; 
    vector<int> p,size;
    vector<ll> weight;
    ll w=0;

    MST(vector<edge>& A, int a){
        n=a;
        p.resize(n); size.assign(n,1);
        weight.resize(n);
        rep(i,n) p[i]=i;
        for(auto&v: A) join(v);
    }
    int find(int u){
        return p[u]==u? u:p[u]=find(p[u]);
    }
    void join(edge& e){
        int u=find(e.u), v=find(e.v);
        if(u==v) return;
        if(size[v]>size[u]) swap(u,v);
        w+=e.w;
        g[e.u].emplace_back(e.v,e.w);
        g[e.v].emplace_back(e.u,e.w);
        size[u]+=size[v];
        p[v]=u;
    }
    ll query(edge& e){
        return w-max(weight[e.u],weight[e.v])+e.w;
    }

};

struct LCA{
    vector<vector<int>> up;
    vector<int> D;
    vector<vector<ll>> maxw;
    int l;
    int n;
    LCA(int a){
        n=a;
        l=log2(n)+1;
        D.resize(n);
        maxw.assign(n,vector<ll>(l,0));
        up.assign(n,vector<int>(l));
        dfs(0,-1,0,0);
        for(int e=1; e<l;e++){
            rep(u,n){
                int a=up[u][e-1];
                if(a!=-1){
                    up[u][e]=up[a][e-1];
                    maxw[u][e]=max(maxw[a][e-1],maxw[u][e-1]);
                }
                else{
                    up[u][e]=-1;
                }
            }
        }
    }

    void dfs(int u, int p, int d, ll w){
        D[u]=d;
        up[u][0]=p;
        maxw[u][0]=w;
        for(auto& v : g[u]) if(v.ff!=p) dfs(v.ff,u,d+1,v.ss);
    }

    ll maxi(int u, int v){
        if(D[u]>D[v]) swap(u,v);
        ll maxW=0;
        for(int e=l-1;e>=0;e--){
            if(up[v][e]!=-1 && D[up[v][e]]>=D[u]){
                maxW=max(maxW,maxw[v][e]);
                v=up[v][e];
            }
        }
        if(v==u) return maxW;
        for(int e=l-1; e>=0;e--){
            if(up[u][e]!=up[v][e]){
                maxW=max({maxW,maxw[v][e],maxw[u][e]});
                v=up[v][e], u=up[u][e];
            }
        }
        maxW=max({maxw[u][0],maxw[v][0],maxW});
        return maxW;
        
    }
    

};

ll dist(edge& e,MST& m, LCA& lc){
    return m.w-lc.maxi(e.u,e.v)+e.w;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<edge> A,B;
    g.assign(n,vector<ii>());
    int u,v; ll w;

    rep(i,m){
        cin>>u>>v>>w;
        A.emplace_back(u-1,v-1,w);
        B.emplace_back(u-1,v-1,w);
    }

    sort(A.begin(),A.end(),[&](const edge&a, const edge&b){
        return a.w<b.w;
    });
    MST mst=MST(A,n);
    //cerr<<mst.w<<"\n";
    LCA lca=LCA(n);
    for(edge& e : B){
        cout<<dist(e,mst,lca)<<"\n";
    }


}