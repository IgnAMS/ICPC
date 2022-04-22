#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


vi C;
vi V;
vector<vi> G;
void dfs(ll u, int c, int n) {
    C[c] = max(C[c], u);
    V[u] = c; 
    for(auto v: G[u]) if(V[v] == -1 and v != n) dfs(v, c, n);
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    V.assign(n + 1, -1);
    G.assign(n + 1, vi());
    rep(i, m) {
        int u, v; cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vi D;
    for(auto u: G[n]) if(V[u] == -1) {
        // cout<<"ire a explorar a "<<u<<" asignandole "<<C.size()<<'\n';
        C.push_back(0);
        dfs(u, C.size() - 1, n);
        D.push_back(C.back());
    }
    if(D.size() == 1) {
        rep(i, n - 1) cout<<'B';
        cout<<'A'<<'\n'; 
    }
    else {
        ll mx = 0, mxind = -1;
        rep(i, D.size()) if(mx < D[i]) mx = D[i], mxind = i;
        // rep(i, D.size()) cout<<D[i]<<' '; cout<<'\n';
        // cout<<mxind<<'\n';
        repx(i, 1, n) cout<<(V[i] == mxind? 'B': 'A');
        cout<<'A'<<'\n';
    }






    return 0;
}