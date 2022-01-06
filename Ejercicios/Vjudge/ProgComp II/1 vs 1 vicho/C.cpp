#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef pair<int,int> ii;
#define ff first
#define ss second


ii DP[2*int(1e5)+2]; // out, in 
vector<vector<int>> g;
vector<bool> in;
vector<queue<int>> q;
ii f(int u, int p){
    cerr<<u<<" "<<p<<"\n";
    if(DP[u]!=ii(-1,-1)) return DP[u];
    DP[u]={0,0};
    in[u]=0;
    for(int& v: g[u]) 
        if(!in[v]){
            DP[u].ff= max(DP[u].ff, f(v,u).ff+1);
        }
        else{
            q[v].push(u);
        }
    
    in[u]=0;
    cout<<u<<" "<<(DP[u].ff)<<" "<<(DP[u].ss)<<"\n";
    return DP[u];
}





int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m; cin>>n>>m;
    g.assign(n,{}); in.assign(n,0); q.resize(n);
    rep(i,2*1e5) DP[i]={-1,-1}; 
    rep(i,m){
        int u,v; cin>>u>>v; u--,v--;
        g[u].push_back(v);
    }
    cerr<<"asdasd\n";
    rep(i,n) if(DP[i]== ii(-1,-1)) f(i,-1);




    return 0;
}