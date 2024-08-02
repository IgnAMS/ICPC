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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, m; cin>>n>>m;
    vector<pll> E;
    vl G[n];
    vl In(n, 0);
    rep(i, m) {
        int u, v; cin>>u>>v; u--,v--;
        G[u].pb(v); G[v].pb(u);
        In[u]++, In[v]++;
    }

    set<ll> S[n];
    // rep(i, n) cout<<i<<' '<<In[i]<<'\n';
    rep(i, n) S[In[i]].insert(i);
    ll ans = 0, erased = 0;
    for(int i = n - 1; i >= 1; i--) {
        if(S[i].empty()) continue;
        while(!S[i].empty()) {
            ll u = *S[i].begin(); 
            S[i].erase(u);
            // cout<<"evaluo a "<<u<<' '<<i<<' '<<erased<<' '<<n - erased<<'\n';
            erased++;
            if(i == n - erased) ans++;
            for(auto v: G[u]) if(S[In[v]].count(v)) {
                S[In[v]].erase(v);
                In[v]--;
                S[In[v]].insert(v);
            }
        }
    }
    cout<<ans<<'\n';

    return 0;
}