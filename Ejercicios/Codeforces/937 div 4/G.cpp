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


vl G[20];
ll DP[65550][20];

// DP[mask][u] = 1 si es que se puede hacer una linea con u como punta
ll dp(ll mask, ll u) {
    if(DP[mask][u] != -1) return DP[mask][u];
    
    // singleton
    if((1<<u) == mask) return 1;
    
    DP[mask][u] = 0;
    for(auto v: G[u]) if(mask & (1<<v)) {
        DP[mask][u] |= dp(mask - (1<<u), v);
    }

    return DP[mask][u];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;


    while(t--) {
        int n; cin>>n;
        map<string, ll> mp1, mp2;
        vector<pll> X(n);
        rep(i, n) {
            string s1, s2; cin>>s1>>s2;
            if(!mp1.count(s1)) mp1[s1] = mp1.size();
            if(!mp2.count(s2)) mp2[s2] = mp2.size();
            X[i] = {mp1[s1], mp2[s2]};
        }
        
        rep(u, n) G[u].clear();

        rep(u, n) rep(v, n) if(u != v) {
            if(X[u].ff == X[v].ff) G[u].pb(v), G[v].pb(u);
            else if(X[u].ss == X[v].ss) G[u].pb(v), G[v].pb(u);
        }

        rep(mask, (1<<n)) rep(j, n) DP[mask][j] = -1;

        ll ans = 1;
        rep(mask, (1<<n)) {
            ll cont = 0;
            rep(i, n) {
                if(mask & (1<<i)) cont++;
            }

            rep(u, n) if(mask & (1<<u)) {
                if(dp(mask, u)) {
                    ans = max(ans, cont);
                }
            }
        }
        cout<<n - ans<<'\n';
    }

    return 0;
}