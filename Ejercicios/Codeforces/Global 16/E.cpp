#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

vector<vector<int>> T; 
vector<vector<int>> G;
vector<bool> V;
void dfs(int u, int p){
    for(auto& v: G[u]) if(v != p) { T[u].push_back(v); dfs(v, u); } 
}


bool dfs2(int u){
    bool aux = 1;
    for(auto& v: T[u]){
        if(T[v].size() > 2) return 0;
        if(T[u].size() == 2 and T[u].size() >= 2) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        G.assign(n, vector<int>());
        T.assign(n, vector<int>());
        V.assign(n, 0);
        rep(i, n-1) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].push_back(v); G[v].push_back(u);
        }
        dfs(0, -1);
        // if(G[0].size() > 1) cout<<"2\n";
        // else{
        //     bool imp = 0;
        //     int sum = 0;
        //     repx(i, 1, n) {
        //         if(T[i].size() > 2) imp = 1;
        //         if(T[i].size() == 2) sum++;
        //     }
        //     if(imp or sum >= 2) cout<<"2\n";
        //     else cout<<"1\n";
        // }
        if(G[0].size() > 1 or !dfs2(1)) cout<<"2\n";
        else cout<<"1\n";

    }

    return 0;
}