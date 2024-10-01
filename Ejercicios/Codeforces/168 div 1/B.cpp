#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 1e5+5;
ll V[mxN], P[mxN], N[mxN], A[mxN];
vl G[mxN];
int n;

void dfs(int u) {
    V[u] = 1;
    P[u] = 0, N[u] = 0;
    for(auto v: G[u]) if(!V[v]) {
        dfs(v);
        P[u] = max(P[u], P[v]);
        N[u] = max(N[u], N[v]); 
    }
    if(P[u] + A[u] - N[u] < 0) {
        P[u] += abs(P[u] + A[u] - N[u]);
    }
    else {
        N[u] += P[u] + A[u] - N[u];
    }
}




int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    } 
    rep(i, n) cin>>A[i];

    dfs(0);
    cout<<P[0] + N[0]<<'\n';


    return 0;
}