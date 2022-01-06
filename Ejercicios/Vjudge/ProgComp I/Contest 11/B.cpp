#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;

map<string, vector<string>> G;
set<string> V;
vector<string> ans;
void dfs(string u){
    // cerr<<u<<"\n";
    V.insert(u);
    // ans.push_back(u);
    for(string v: G[u]) if(!V.count(v)){
        dfs(v);
    }
    ans.push_back(u);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string linea; getline(cin, linea);
    int n = stoi(linea);
    rep(_, n){
        string v = "", u = "";
        getline(cin, linea);
        int i = 0; 
        while(linea[i] != ':') v += linea[i++];
        vector<string> U;
        for(i += 2; i<linea.length(); i++){
            if(linea[i] == ' ') { 
                U.push_back(u); u = ""; 
            }
            else u += linea[i];
        }
        if(u != "") U.push_back(u);
        for(string u_ : U){
            // cerr<<u_<<"\n";
            if(!G.count(u_)) G[u_] = vector<string>();
            G[u_].push_back(v);
        }
    }
    string root; 
    cin>>root; 
    dfs(root);
    // queue<string> q; q.push(root);
    // V.insert(root); 
    // while(!q.empty()){
    //     string u = q.front(); q.pop();
    //     for(auto& v: G[u]) if(!V.count(v)){
    //         // cerr<<"vistitare a "<<v<<"\n";
    //         ans.push_back(v);
    //         V.insert(v);
    //         q.push(v);
    //     }
    // }
    rep(i, ans.size()) cout<<ans[ans.size() - i - 1]<<'\n';
    // for(string u: ans) cout<<u<<'\n';

    return 0;
}