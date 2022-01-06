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


int id, comp = 0;
vector<vi> G, G2;  // Directed Graph
vi D, L, I, C; stack<int> S;

void dfs(int u){
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for (int v : G[u]){
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); }
        else if (I[v]) L[u] = min(L[v], L[u]);
    }
    if (L[u] == D[u] and ++comp) while (1){
        int x = S.top(); S.pop(); I[x] = 0; C[x] = u;
        if (x == u) break;
    }
}

vi ans, W2;
void dfs2(int u, int e){
    D[u] = -2;
    if(u == e) { D[u] = W2[u]; return; }
    for(auto v: G2[u]) {
        if(D[v] == -1) dfs2(v, e);
        if(D[v] == -2) continue;
        D[u] = max(D[u], D[v] + W2[u]);
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, s, t; cin>>n>>m>>s>>t; s--, t--;
    G.assign(n, vi()); D.assign(n, -1); L.assign(n, -1); C.assign(n, 0); I.assign(n, 0);
    vi W(n); rep(i, n) cin>>W[i];
    rep(i, m){
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v);
    }
    id = 0;
    D.assign(n, -1);
    rep(i, n) if(D[i] == -1) dfs(i);
    // rep(i, n) cout<<C[i]<<' '; cout<<'\n';
    
    W2.assign(n, 0); G2.assign(n, vi());
    rep(i, n){
        W2[C[i]] += W[i];
        rep(j, G[i].size()) if(C[i] != C[G[i][j]]) {
            G2[C[i]].push_back(C[G[i][j]]);
        } 
    }
    D.assign(n, -1);
    dfs2(C[s], C[t]);
    if(D[C[s]] < 0) cout<<0<<'\n';
    else cout<<D[C[s]]<<'\n';


    return 0;
}