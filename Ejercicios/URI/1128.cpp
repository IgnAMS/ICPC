#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

vector<vector<int>> g;
vector<int> I,D,L;
stack<int> S;
int id;
int comps;

void dfs(int u){  
    D[u] = L[u] = id++; I[u]=1; S.push(u);
    for(int v: g[u]){
        if(D[v]==-1) { dfs(v); L[u]=min(L[v],L[u]); }
        else if(I[v]) L[u]=min(L[v],L[u]);
    }
    if(L[u]==D[u]){
        comps++;
        while(1){
            int x=S.top(); S.pop(); I[x]=0;
            if(x==u) break;
        }
    } 

}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,V; 
    while(cin>>n>>V && n!=0){
        g.assign(n,{}); 
        I.assign(n,0); D.assign(n,-1); L.resize(n);
        id=0, comps=0;
        rep(i,V){
            int u,v,p; cin>>u>>v>>p; u--,v--;
            g[u].push_back(v);
            if(p==2) g[v].push_back(u);
        }
        rep(u,n) if(D[u]==-1) dfs(u);
        if(comps==1) cout<<1<<"\n";
        else cout<<0<<"\n";
    }


    return 0;
}