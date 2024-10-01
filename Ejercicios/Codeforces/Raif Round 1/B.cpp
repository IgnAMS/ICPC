#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<int> D,L,s,comp,S;
vector<bool> instack;
vector<vector<int>> g;
int id=0;
int numC=0;

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
            S[u]++;
            if(x==u) break;
        }
        numC++;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        D.assign(n,-1);L.resize(n);s.clear();S.assign(n,0);
        instack.assign(n,0); g.assign(n,{});
        id=0, numC=0;
        string linea; cin>>linea;
        rep(i,n){
            if(linea[i]=='>') g[i].push_back((i+1)%n);
            else if(linea[i]=='<') g[(i+1)%n].push_back(i);
            else{ g[(i+1)%n].push_back(i); g[i].push_back((i+1)%n); }
        }
        rep(i,n) if(D[i]==-1) dfs(i);
        int ans=0;
        rep(i,n) if(S[i]>1) ans+=S[i];
        cout<<ans<<"\n";
    }


}