#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;

vector<vector<int>> G;
vector<int> D, letra; 
vector<bool> I; 
vector<vector<int>> aux(300000, vector<int>('z' - 'a' + 1, 0));
bool inf = false;

void dfs(int u){
    if(inf) return;

    D[u] = 1, I[u] = true;
    for(auto& v: G[u]){
        if(I[v]) { inf = true; return; }
        if(D[v] == -1) dfs(v);
        rep(i, 'z' - 'a' + 1) aux[u][i] = max(aux[u][i], aux[v][i]);
    }
    aux[u][letra[u]]++;
    I[u] = false;
}

int main(){
    int n, m; cin>>n>>m;
    G.assign(n, {}); I.assign(n, false); D.assign(n, -1); letra.resize(n);
    string s; cin>>s;
    rep(i, n) letra[i] = s[i] - 'a';
    rep(i, m){
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v);
    }
    int ans = 0;
    rep(u, n){
        if(D[u] == -1) dfs(u);
        rep(i, 'z' - 'a' + 1) ans = max(ans, aux[u][i]);
    }
    if(inf) cout<<"-1\n";
    else cout<<ans<<'\n';

    return 0;
}

