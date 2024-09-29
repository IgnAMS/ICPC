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


ll k, n;
const int mxN = 5e4+5;
ll A[mxN], P[mxN];
vl G[mxN];


vector<pll> X;
ll V[mxN], Curr[mxN];

ll dfs(ll m, ll u, ll p) {
    vector<pll> E;
    // cerr<<"visito a "<<u<<' '<<p<<'\n';
    for(auto& v: G[u]) if(v != p) {
        // cerr<<"ire a "<<v<<" desde "<<u<<'\n';
        E.pb({dfs(m, v, u), v});
    }
    sort(E.begin(), E.end());
    ll curr = A[u];
    for(auto& [val, v]: E) {
        if(curr + val > m) X.pb({u, v});
        else curr += val;
    }
    return curr;
}

bool solve(ll m) {
    X.clear();
    // cerr<<"entre con "<<m<<'\n';
    dfs(m, 0, -1);

//     rep(u, n) V[u] = Curr[u] = 0;
//     queue<ll> q;
//     // parto desde las hojas hacia arriba
//     rep(u, n) if(G[u].size() == 1 and u != 0) {
//         q.push(u), V[u] = 1;
//     }
// 
//     while(!q.empty()) {
//         int u = q.front(); q.pop();
//         Curr[u] = A[u];
//         
//         vector<pll> xd;
//         for(auto v: G[u]) if(v != P[u]) xd.push_back({Curr[v], v});
//         sort(xd.begin(), xd.end());
// 
//         for(auto [val, v]: xd) {
//             if(Curr[u] + val > m) X.pb({u, v});
//             else Curr[u] += val;
//         }
// 
//         if(!V[P[u]]) {
//             V[P[u]] = 1;
//             q.push(P[u]);
//         }
//     }
    if(X.size() > k) return 0;
    return 1;
}



void set_p(int u, int p) {
    P[u] = p;
    for(auto v: G[u]) if(P[v] == -2) set_p(v, u);
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>A[i]; 
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    rep(u, n) P[u] = -2;
    set_p(0, -1);

    ll l = *max_element(A, A + n), r = 1LL * mxN * 1e9;
    // 0, 0, 0, 0, 0, 1, 1, 1, 1
    while(l < r) {
        ll m = (l + r) / 2;
        ll val = solve(m);
        // cout<<val<<" con valor de "<<m<<'\n';
        if(val) r = m;
        else l = m + 1;
    }
    solve(l);
    cout<<X.size()<<'\n';
    for(auto [a, b]: X) cout<<a + 1<<' '<<b + 1<<'\n';

    return 0;
}