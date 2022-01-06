#include<bits/stdc++.h>
using namespace std; 
#define rep(i,n) for(int i=0;i<n;i++)

vector<bool> visited;
vector<vector<int>> adj;
vector<bool> D;
int cont=0;
int maxi=1;
void backtracking(int u){
    if(visited[u]) return;
    visited[u]=true;
    unordered_set<int> s;
    for(auto v:adj[u]) s.insert(v);
    
    for(auto uu: s){
        cont=2;
        for(auto vv: adj[uu]){
            if(s.count(vv)) cont++;
        }
        maxi=max(maxi,cont);
        if(maxi>4) return;
    }
    for(auto v: s) if(!visited[v]) backtracking(v);
    return;

}

int main(){
    int t; cin>>t;
    while(t--){
        int n,b; cin>>n>>b;
        visited.assign(n,false);
        adj.assign(n,vector<int>());
        D.assign(n,false);
        cont=0;
        int u,v;

        rep(i,b) {
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        rep(i,n){
            backtracking(i);
        }
        cout<<maxi<<endl;


    }


    return 0;
}