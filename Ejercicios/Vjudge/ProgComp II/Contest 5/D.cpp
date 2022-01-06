#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

struct edge{
    ll u,v,w;
    edge(ll u, ll v, ll w): u(u), v(v), w(w) {}
};

struct MST{
    ll cost;
    vector<int> p,size;
    int n;
    MST(vector<edge>& A, int a){
        cost=0;
        n=a;
        p.resize(a);
        size.assign(a,1);
        rep(i,n) p[i]=i;
        for(auto& u:A) join(u);
    }
    
    int find(int u){
        return p[u]==u? u:p[u]=find(p[u]);
    }

    void join(edge& ver){
        int u=find(ver.u), v=find(ver.v);
        if(u==v) return; 
        cost+=ver.w;
        if(size[v]>size[u]) swap(v,u);
        size[u]+=size[v];
        p[v]=u;
    }

};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    vector<edge> aristas;
    ll u,v,w;
    rep(i,m) {
        cin>>u>>v>>w; 
        aristas.emplace_back(u-1,v-1,w);
    }
    
    sort(aristas.begin(),aristas.end(),[&](const edge& a, const edge& b){
        return a.w < b.w;
    });
    
    MST mst=MST(aristas, n);
    cout<<mst.cost<<"\n";






    return 0;
}