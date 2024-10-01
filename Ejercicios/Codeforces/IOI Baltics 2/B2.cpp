#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

vector<vector<int>> adj;
vector<int> nums;
vector<int> nodos;
int cont=0;

void dfs(int u, int p){
    for(auto v:adj[u]){
        if(v!=p){
            if(adj[v].size()==1){
                swap(nums[v],nums[u]);
                cont+=2;
            }
            dfs(v,u);
        }
    }
    return;
}

void check(int u, int p){
    bool cambiado= nums[u]==u? false:true;
    for(auto v: adj[u]){
        if(v!=p){
            if(nums[u]==u && nums[v]==v){
                cambiado=true;
                swap(nums[u],nums[v]);
                cont+=2;
            }
            dfs(v,u);
        }
    }
    if(nums[u]==u){
        swap(nums[u],nums[adj[u][0]]);
        cont+=2;
    }
    return;
}


int main(){
    int n; cin>>n;
    adj.assign(n,vector<int>());
    nums.resize(n);
    
    rep(i,n) nums[i]=i;
    
    int u,v; 
    rep(i,n-1) {
        cin>>u>>v;
        adj[u-1].push_back(v-1);
        adj[v-1].push_back(u-1);
    }
    dfs(0,-1);
    check(0,-1);
    
    cout<<cont<<endl;
    rep(i,n) cout<<nums[i]<<" ";
    cout<<endl;


}