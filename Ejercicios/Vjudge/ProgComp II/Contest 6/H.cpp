#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> g;
vector<int> D,L,s;
vector<bool> instack;
vector<int> comp;
deque<int> q;
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
        q.push_back(u);
        numC++;
    }
}

int DFS(int u){
    D[u]=1;
    int ans=1;
    for(auto& v: g[u]){
        if(D[v]==-1) ans+=DFS(v);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    g.resize(n);
    comp.resize(n);
    L.resize(n);
    D.assign(n,-1);
    instack.assign(n,0);

    rep(i,n){
        int aux=-1;
        while(cin>>aux){
            if(aux==0) break;
            g[i].push_back(aux-1);
        }
    }
    //creo la componente grande
    rep(i,n) if(D[i]==-1) dfs(i);

    D.assign(n,-1);
    int compans= DFS(q.back())==n? comp[q.back()]:-1;
    //cout<<q.back()<<"\n";

    rep(u,n) if(comp[u]==compans) cout<<u+1<<" ";
    cout<<"0\n";




    return 0;
}