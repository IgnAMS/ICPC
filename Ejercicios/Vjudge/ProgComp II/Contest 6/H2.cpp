#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;
vector<set<int>> G;
vector<int> D,L,s;
vector<bool> instack;
vector<int> comp;
int numC=0;
int id=0;

void dfs(int u){
    D[u]=L[u]=++id;
    instack[u]=1;
    s.push_back(u);
    for(auto& v: g[u]){ 
        if(D[v]==-1){
            dfs(v);
            L[u]=min(L[u],L[v]);
        }
        else if(instack[v]) L[u]=min(L[u],L[v]);
    }

    if(L[u]==D[u]){//componente grande
        while(1){
            int x=s.back(); s.pop_back();
            instack[x]=0;
            comp[x]=numC;
            if(x==u) break;
        }
        numC++;
    }
}

vector<int> DG;
deque<int> q;
bool topo=1;
int target=-1;

int DFS(int u){
    DG[u]=1;
    if(u==target) return DG[u]=2;
    for(auto& v: G[u]){
        if(DG[v]==-1) DG[u] = DFS(v);
        if(DG[v]==2) DG[u]=2;
    }
    if(topo) q.push_front(u);
    return DG[u];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    g.resize(n);
    comp.resize(n);
    L.resize(n);
    D.assign(n,-1);
    instack.assign(n,0);

    rep(i,m){
        int u, v; cin>>u>>v; u--,v--;
        g[u].push_back(v);
    }
    //creo la componente grande
    rep(i,n) if(D[i]==-1) dfs(i);

    G.resize(numC);
    DG.assign(numC,-1);
    
    rep(u,n)
        for(auto& v: g[u]) G[comp[u]].insert(comp[v]);

    rep(i,numC) if(DG[i]==-1) DFS(i);

    DG.assign(numC,-1);
    target=q.back(); 
    topo=0;
    bool ans=true;

    rep(i,numC) if(DFS(i)!=2) ans=false;
    vector<int> A;
    if(ans) rep(i,n) if(comp[i]==target) A.push_back(i+1);
    cout<<A.size()<<"\n";
    rep(i,A.size()) {cout<<A[i]; if(i<A.size()-1) cout<<" ";}
    if(ans) cout<<"\n";

    
    return 0;
}