#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int n,m;
vector<vector<int>> G;
vector<int> D;

bool backtrack(int k, int u){
    if(u==n-1){
        rep(i,k){
            bool flag=1;
            for(int& v: G[u]){
                if(D[v]==i) flag=0;
            }
            //es posible, devuelvo 1
            if(flag) return 1;
        } 
        //no retorno, por ende devuelvo 0
        return 0;
    }

    bool ans=0;
    rep(i,k){
        bool flag=1;
        //chequeo si es posible
        for(int& v: G[u]) if(v<u && D[v]==i) flag=0;
        
        if(flag){
            //es posible, marco el color y llamo al siguiente
            D[u]=i;
            ans = ans || backtrack(k, u+1);
        }
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        cin>>n>>m; 
        G.assign(n,{});
        D.assign(n,-1);
        rep(i,m){
            int u,v; cin>>u>>v; 
            G[u].push_back(v); G[v].push_back(u);
        }
        int ans=-1;
        rep(i,4){
            if(backtrack(i+1, 0)) { ans = i+1; break; }
        }
        if(ans==-1) cout<<"many\n";
        else cout<<ans<<"\n";
    }





    return 0;
}
