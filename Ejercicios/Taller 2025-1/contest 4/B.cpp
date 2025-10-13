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



void solve() {
    int n, m; cin>>n>>m;
    vector<vl> G(n);
    rep(i, m) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    deque<ll> q = {0};
    vl V(n, 0), C(n, 0);
    V[0] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop_front();
        ll cont = 0;
        for(auto v: G[u]) {
            cont += C[v];
            if(!V[v]) {
                V[v] = 1;
                q.push_back(v);
            }
        }
        if(cont == 0) C[u] = 1;
    }
    ll cont = 0;
    rep(i, n) cont += C[i];
    if(cont > n / 2) {
        rep(i, n) C[i] = 1 - C[i];
        cont = n - cont;
    }

    cout<<cont<<'\n';
    rep(i, n) if(C[i]) cout<<i + 1<<' '; cout<<'\n';
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        solve();
    }


    return 0;
}