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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        vl A(n); rep(i, n) cin>>A[i];
        vector<vl> G(n, vl());
        rep(i, n - 1) {
            int p; cin>>p; p--;
            G[p].pb(i + 1);
        }

        ll ans = 0;
        vl L(n, 0);
        ll INF = 1e16;
        for(int u = n - 1; u >= 0; u--) {
            if(G[u].size() == 0) {
                L[u] = INF;
                continue;
            }
            ll suma = 0;
            for(auto v: G[u]) suma += A[v];

            if(suma >= A[u]) {
                L[u] = suma - A[u];
            }
            else {
                ll x = A[u] - suma;
                L[u] = 0;

                deque<pll> dq;
                dq.pb({u, 0});
                while(!dq.empty()) {
                    auto [v, d] = dq.front(); dq.pop_front();
                    ll k = min(x, L[v]);
                    x -= k, L[v] -= k;
                    ans += k * d;
                    for(auto w: G[v]) dq.pb({w, d + 1});
                }
            }
        }
        
        cout<<ans<<'\n';
    }





    return 0;
}