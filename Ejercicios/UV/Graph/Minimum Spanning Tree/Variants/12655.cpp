#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ii pair<int,int>
#define ff first
#define ss second
typedef vector<ii> vii;

struct edge{
    int u, v, w;
    edge(int u,int v,int w): u(u), v(v), w(w) {}
};

int l,n,timer,root;
vector<int> tin,tout,dist;
vector<vii> adj;
vector<vector<int>> up;

void dfs(int u, int p){
    tin[u]= ++timer;
    up[u][0]=p;
    for(int i=1;i<=l;i++) up[u][i]=up[up[u][i-1]][i-1];
    for(auto &v: adj[u]){
        if(v.ff!=p) dfs(v.ff,u);
    }
    tout[u]= ++timer;
    return;
}


void preprocess(int n,int r){
    root=r;
    tin.resize(n); tout.resize(n);
    timer=0;
    l=ceil(log2(n));
    up.assign(n,vector<int>(l+1));
    dfs(root,root);
    return;
}

bool ancestor(int u,int v){
    return tin[u]<=tin[v] && tout[v]<=tout[u];
}

int lca(int u, int v){
    if(ancestor(u,v)) return u;
    if(ancestor(v,u)) return v;
    for(int i=l;i>=0;--i){
        if(!ancestor(up[u][i],v)){
            u=up[u][i];
        }
    }
    return up[u][0];
}

vector<edge> edges;
map<ii,int> mapa;
struct MST{
    vector<int> parent;
    int n;
    MST(int n){
        this->n=n;
        parent.assign(n,-1);
    }
    int find(int u){
        int root=u;
        while(parent[root]>=0){
            root=parent[root];
        }
        return root;
    }
    void Union(edge &e){
        if(find(e.u)==find(e.v)) return;
        int u=find(e.u), v=find(e.v);
        if(-parent[u] < -parent[v]) swap(u,v);
        //los conecto
        adj[u].push_back(ii(v,e.w));
        adj[v].push_back(ii(u,e.w));
        mapa.insert(make_pair(ii(u,v),e.w));
        mapa.insert(make_pair(ii(v,u),e.w));
        parent[u]+=parent[v];
        parent[v]=u;
        return;
    }
};



int main(){
    int m,s;
    while(cin>>n>>m>>s){
        int u,v,w;
        mapa.clear();
        edges.clear();
        rep(i,m) {cin>>u>>v>>w; edges.push_back(edge(u-1,v-1,w));}
        //for(auto &x : edges) cin>>x.u>>x.v>>x.w;
        sort(edges.begin(),edges.end(),[&](const edge &a, const edge &b){
            return a.w>b.w;
        });

        adj.assign(n,vii());
        MST tree=MST(n);
        for(auto &x: edges) tree.Union(x);
        preprocess(n,0);
        rep(i,s){
            cin>>u>>v;
            u--,v--;
            int low=lca(u,v);
            int maxi=1e8;
            while(u!=low){
                maxi=min(mapa[ii(u,up[u][0])],maxi);
                u=up[u][0];
            }
            while(v!=low){
                maxi=min(mapa[ii(v,up[v][0])],maxi);
                v=up[v][0];
            }
            cout<<maxi<<endl;
        }
    }


    return 0;
}