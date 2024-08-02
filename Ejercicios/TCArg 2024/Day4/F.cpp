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

const int mxN = 1e3+5;
ll V[mxN], A[mxN], Sz[mxN], E[mxN];
vl G[mxN];

void dfs(ll u, ll comp) {
    V[u] = comp;
    Sz[comp]++;
    for(auto v: G[u]) {
        if(V[v] == -1) dfs(v, comp);
        E[comp]++;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m, k; cin>>n>>m>>k;  
    rep(i, k) cin>>A[i];
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    rep(i, n) V[i] = -1;

    ll comps = 0;
    ll greater = A[0];
    ll ans = 0;
    rep(i, k) {
        Sz[comps] = E[comps] = 0;
        A[i]--;
        dfs(A[i], comps);
        if(Sz[greater] < Sz[comps]) greater = comps;
        ans += Sz[comps] * (Sz[comps] - 1) / 2 - E[comps] / 2;
        comps++;
    }

    ans -= Sz[greater] * (Sz[greater] - 1) / 2 - E[greater] / 2;
    rep(i, n) if(V[i] == -1) {
        dfs(i, comps);
        Sz[greater] += Sz[comps];
        E[greater] += E[comps]; 
        comps++;
    }
    ans += Sz[greater] * (Sz[greater] - 1) / 2 - E[greater] / 2;
    cout<<ans<<'\n';

    return 0;
}