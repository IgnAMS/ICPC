#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> G;
vector<int> D;

int maxd=-1;

void dfs(int u, int d){
    D[u]=d;
    maxd=max(maxd, d);
    for(auto& v: G[u]){
        if(D[v]==-1) dfs(v,d+1);
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); 
    int n, m; cin>>n>>m;
    G.assign(n,{}); D.assign(n,-1);
    bool pos=1;
    rep(i,m){
        int u,v; cin>>u>>v;
        G[u-1].push_back(v-1); G[v-1].push_back(u-1);
        if(G[u].size()==3) pos=0;
    }
    if(!pos) { cout<<-1<<"\n"; return 0; }
    rep(i,n){
        maxd=-1;
        if(D[i]==-1 && G[i].size()) dfs(i,1);
    }
    vector<int> A,B;
    rep(i,n) {
        cout<<"D[i]: "<<D[i]<<"\n";
        if(D[i]==0) continue;
        else if(D[i]%2==0) A.push_back(i+1);
        else if(D[i]!=-1) B.push_back(i+1);
    }
    cout<<A.size()<<"\n";
    rep(i,A.size()) cout<<A[i]<<" ";
    cout<<"\n";
    cout<<B.size()<<"\n";
    rep(i,B.size()) cout<<B[i]<<" ";

    





    return 0;
}