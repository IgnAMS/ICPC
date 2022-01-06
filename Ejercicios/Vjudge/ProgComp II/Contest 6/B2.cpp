#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;
typedef unsigned long long ull;

vector<int> s,D,L,comp;
vector<bool> instack;
vector<vector<ll>> g;
vector<ll> weight;
int n,numC=0;
ll mod=1e9+7;
ll tcost=0;
ull tcant=1;
int id=0;

void dfs(int u){
    D[u]=L[u]=++id;
    instack[u]=true;
    s.push_back(u);
    ull cant=1;

    for(ll& v : g[u]){
        if(D[v]==-1)
            dfs(v), L[u]=min(L[v],L[u]);
        
        else if(instack[v]) L[u]=min(L[u],L[v]);
    }

    if(L[u]==D[u]){ //root
        ll cost=1e10;
        while(1){
            int x = s.back(); s.pop_back();
            instack[x]=false;
            comp[x]=numC;
            if(x==u){
                break;
            }
        }
        numC++;
    }
}



int main(){
    cin>>n;
    weight.resize(n);
    g.assign(n, vector<ll>());
    D.assign(n,-1);
    L.resize(n);
    comp.resize(n);
    instack.assign(n,0);
    rep(i,n) cin>>weight[i];
    
    int m; cin>>m;
    int u, v;
    rep(i,m){
        cin>>u>>v; u--, v--;
        g[u].push_back(v);
    }
    rep(i,n) if(D[i]==-1) dfs(i);
    vector<int> mini(n,1e10), cant(n);
    rep(i,n){
        if(weight[i]<mini[comp[i]]){
            mini[comp[i]]=weight[i];
            cant[comp[i]]=1;
        }
        else if(weight[i]==mini[comp[i]]){
            cant[comp[i]]++;
        }
    }
    rep(i,numC){
        tcost+=mini[i];
        tcant= (tcant*cant[i])%mod;
    }
    cout<<tcost<<" "<<tcant<<"\n";


    return 0;
}