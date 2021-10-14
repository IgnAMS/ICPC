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
int id;
vector<vi> G;  // Directed Graph
vi D, L, I, C, ID;
stack<int> S;


void dfs(int u){
    D[u] = L[u] = id++, I[u] = 1; S.push(u);
    for (int v : G[u]){
        if (D[v] == -1) { dfs(v); L[u] = min(L[v], L[u]); }
        else if (I[v]) L[u] = min(L[v], L[u]);
    }
    if (L[u] == D[u]) {
        ID.push_back(u);
        while (1){
            int x = S.top(); S.pop(); I[x] = 0; C[x] = u;
            if (x == u) break;
        }
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<int> W(n); rep(i, n) cin>>W[i];
    int m; cin>>m;
    G.assign(n, vi()); D.assign(n, -1); L.assign(n, -1); C.resize(n); 
    I.assign(n, 0);
    rep(i, m){
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v);
    }
    id = 0;
    rep(i, n) if(D[i] == -1) dfs(i);
    map<int, int> mini, cont;
    rep(i, n){
        if(!cont.count(C[i])) {
            cont[C[i]] = 1;
            mini[C[i]] = W[i];
        }
        else{
            if(W[i] < mini[C[i]]) mini[C[i]] = W[i], cont[C[i]] = 1;
            else if(W[i] == mini[C[i]]) cont[C[i]]++;
        }
    }
    ll ans = 1, suma = 0, mod = 1000000007;
    for(int i : ID){
        cerr<<mini[i]<<' '<<cont[i]<<'\n';
        suma += mini[i];
        ans = (ans * cont[i]) % mod;
    }
    cout<<suma<<' '<<ans<<'\n';
    




    return 0;
}