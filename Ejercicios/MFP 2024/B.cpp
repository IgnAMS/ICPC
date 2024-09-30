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
ll A[mxN];
vl G[mxN];
vector<pll> X;

ll dfs(ll m, ll u, ll p) {
    vector<pll> E;
    for(auto& v: G[u]) if(v != p) E.pb({dfs(m, v, u), v});
    sort(E.begin(), E.end());
    ll curr = A[u];
    for(auto& [val, v]: E) {
        if(curr + val > m) X.pb({u, v});
        else curr += val;
    }
    return curr;
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>A[i]; 
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v); G[v].pb(u);
    }

    ll l = *max_element(A, A + n), r = 1LL * mxN * 1e9;
    // 0, 0, 0, 0, 0, 1, 1, 1, 1
    while(l < r) {
        ll m = (l + r) / 2;
        X.clear();
        dfs(m, 0, -1);
        if(X.size() <= k) r = m;
        else l = m + 1;
    }
    X.clear();
    dfs(l, 0, -1);
    cout<<X.size()<<'\n';
    for(auto [a, b]: X) cout<<a + 1<<' '<<b + 1<<'\n';

    return 0;
}