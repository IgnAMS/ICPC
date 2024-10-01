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
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


vi A;
vector<vi> G;
ll dfs(int u, int p, int c, int m) {
    if(c > m) return 0;
    ll ans = 0;
    for(auto v: G[u]) if(v != p) ans += dfs(v, u, (A[v]? c + 1: 0), m);
    if(G[u].size() == 1 and u != 0 and c <= m) return 1;
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    A.resize(n); rep(i, n) cin>>A[i];
    G.assign(n, vi());
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(v); G[v].push_back(u);
    }
    cout<<dfs(0, -1, A[0], m)<<'\n';


    return 0;
}