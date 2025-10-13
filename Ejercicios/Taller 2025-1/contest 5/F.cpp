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

const int mxN = 2e5+5;
vl G[mxN];
ll A[mxN], C[mxN];
ll ans = 0;

void dfs(int u) {
    if(G[u].size() == 0) {
        ans = max(ans, A[u]);
        C[u] = 1;
    }
    for(auto v: G[u]) {
        dfs(v);
        A[u] += A[v];
        C[u] += C[v];   
    }
    ans = max(ans, (A[u] + C[u]  - 1) / C[u]);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n - 1) {
        int p; cin>>p; p--;
        G[p].pb(i + 1);
    }
    rep(i, n) cin>>A[i];

    dfs(0);
    cout<<ans<<'\n';




    return 0;
}