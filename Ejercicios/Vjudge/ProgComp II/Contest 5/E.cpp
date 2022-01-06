#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<ll,ll> ii;
#define ff first
#define ss second

vector<vector<ii>> g;
struct edge{
    ll u,v,w;
    edge(ll u,ll v,ll w): u(u),v(v),w(w){}
};
vector<ll> ans;

struct MST{
    ll n;
    ll m;
    vector<int> p,size;
    int l;
    MST(vector<edge>&A, int a){
        n=a;
        m=A.size();
        p.resize(n);
        rep(i,n) p[i]=i;
        size.assign(n,1);
        g.assign(n,vector<ii>());
        ans.assign(m,0);
        l=log2(n)+1;
        for(auto& u: A) join(u);
        dfs(0,-1,-1,0);
        check();
        
    }
    int find(int u){
        return p[u]==u? u:p[u]=find(p[u]);
    }

    void join(edge& ed){
        int u=find(ed.u), v=find(ed.v);
        if(u==v) return;
        if(size[v]>size[u]) swap(v,u);
        size[u]+=size[v];
        //cout<<"uno el nodo "<<u<<" con el nodo "<<v<<"\n";
        g[ed.u].emplace_back(ed.v,ed.w);
        g[ed.v].emplace_back(ed.u,ed.w);
        p[v]=u;
    }

    ll dfs(int u, int p, int d, ll prof){
        ll acc=0;
        for(auto& v: g[u]) if(v.ff!=p){
            acc+=dfs(v.ff,u,v.ss,prof+1)+1;
        }
        
        if(d!=-1) ans[d]=(acc+1)*(n-acc-1);
        return acc;
    }

    void check(){
        rep(i,ans.size()){
            if(i==ans.size()-1 && ans[i]>1){
                ans.push_back(0);
            }
            if(i<ans.size()-1){
                ans[i+1]+=(ans[i])/2;
                ans[i]=ans[i]%2;
            }
        }
    }
};



int main(){
    int n, m; cin>>n>>m;
    vector<edge> A;
    ll u,v,w;
    rep(i,m) {cin>>u>>v>>w; A.emplace_back(u-1,v-1,w);}
    sort(A.begin(),A.end(),[&](const edge& a, const edge& b){
        return a.w<b.w;
    });
    MST mst=MST(A,n);

    bool start=0;
    for(int i=ans.size()-1;i>=0;i--){
        if(ans[i]==1) start=true;
        if(start) cout<<ans[i];
    }
    cout<<"\n";



    return 0;
}