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
vl G[mxN];
int n;
ll S[mxN];
ll V[mxN];

vl B;

ll ans = 1;

void dfs(int u) {
    // cout<<"visito a "<<u<<'\n';
    V[u] = 1;
    for(auto v: G[u]) if(!V[v]) {
        ll ind = lower_bound(B.begin(), B.end(), S[v]) - B.begin();
        ll val = B[ind];
        ans = max(ans, ind + 1);
        B[ind] = S[v];
        dfs(v);
        B[ind] = val;
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>S[i];
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    rep(i, n) {
        if(G[i].size() != 1) continue;
        
        rep(j, n) V[j] = 0;
        B.assign(n + 1, mxN);
        B[0] = S[i];
        dfs(i);
    }
    cout<<ans<<'\n';

    return 0;
}