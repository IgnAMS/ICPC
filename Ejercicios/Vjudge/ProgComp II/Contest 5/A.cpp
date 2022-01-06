#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
#define ff first
#define ss second


int n, m;

struct edge{
    int u,v,w,i;
    edge(int u, int v, int w, int i): u(u), v(v), w(w), i(i){}
};


struct MST{
    vector<int> p,size; 
    MST(vector<edge>&A){
        p.assign(n,-1);
    }
    int find(int u){ return p[u]<0? u:p[u]=find(p[u]);}
    void join(int u, int v){
        u=find(u), v=find(v);
        if(u == v) return;
        if(p[v]>p[u]) swap(u,v);
        p[u]+=p[v], p[v]=u;
        return;
    }
};

map<int,vector<pair<int,int>>> G; //ff es nodo, ss es id
vector<int> L,D,A;

void dfs(int u, int p, int d){
    D[u]=d, L[u]=d;
    for(auto& e: G[u]) if(e.ss!=p){
        if(D[e.ff]==-1){
            dfs(e.ff,e.ss,d+1);
            if(L[e.ff]>D[u]) A[e.ss]=2;
            L[u]=min(L[u],L[e.ff]);
        }
        L[u]=min(L[u],L[e.ff]);
    }
}


int main(){
    cin>>n>>m;
    vector<edge> E;
    int u,v,w;
    rep(i,m) {
        cin>>u>>v>>w;
        E.emplace_back(u-1,v-1,w,i);
    }
    sort(E.begin(),E.end(),[&](const edge& a, const edge& b){
        return a.w<b.w;
    });

    MST mst= MST(E);
    int i=0, j=0;
    A.assign(n,1); D.assign(n,-1); L.assign(n,-1);
    while((i=j)<m){
        while(j<m && E[i].w == E[j].w) j++;
        
        G.clear();
        for(int k=i; k<j; k++){
            u=mst.find(E[k].u), v=mst.find(E[k].v);
            cerr<<u<<" "<<v<<"\n";
            if(v==u){
                A[E[k].i]=0;
                continue;
            }
            D[u] = D[v] = L[u] = L[v] = -1;
            G[u].emplace_back(v,E[k].i), G[v].emplace_back(u,E[k].i);
        }

        for(int k=i;k<j;k++){
            u=mst.find(E[k].u);
            if(D[u]==-1) dfs(u,-1,0);
        }

        for(int k=i;k<j;k++) mst.join(E[k].u,E[k].v);
    }

    rep(i,m){
        if(A[i]==0) cout<<"none\n";
        if(A[i]==1) cout<<"at least one\n";
        if(A[i]==2) cout<<"any\n";
    }


    return 0;
}