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


const ll mxN = 1e6+10;
vl G[mxN];
ll DP[mxN];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n, m; cin>>n>>m;
        ll suml = 0;
        rep(i, n) {
            ll l; cin>>l;
            suml += l + 3;
            vl F(l + 5, 0);
            rep(j, l) {
                ll x; cin>>x;
                if(x <= l + 4) {
                    F[x]++;
                } 
            }
            ll mex, mex2, bmex = 0;
            rep(j, l + 5) {
                if(F[j] == 0 and bmex == 0) {
                    mex = j;
                    bmex = 1;
                }
                else if(F[j] == 0 and bmex) {
                    mex2 = j;
                    break;
                }
            }
            G[mex].pb(mex2);
        }

        ll best = 0;
        for(ll u = suml; u >= 0; u--) {
            DP[u] = u;
            for(auto v: G[u]) DP[u] = max(DP[u], DP[v]);
            if(G[u].size()) best = max(u, best);
            if(G[u].size() >= 2) best = max(best, DP[u]);
        }
        
        ll ans = 0;
        rep(u, min(suml, m) + 1) {
            ans += max(DP[u], best);
        }
        if(suml < m) ans += m * (m + 1) / 2 - suml * (suml + 1) / 2;
        cout<<ans<<'\n';

        // Resteo el grafo para el sgt test case
        rep(u, suml + 5) G[u].clear();
    }

    return 0;
}