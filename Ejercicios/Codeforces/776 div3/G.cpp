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

const ll MOD = 1e9+7;
const ll INF = 1e10;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, m; cin>>n>>m;
        int s, t; cin>>s>>t; s--, t--;
        vector<vl> G(n, vl());
        rep(i, m) {
            int u, v; cin>>u>>v; u--, v--;
            G[u].pb(v); G[v].pb(u);
        }
        // rep(u, n) {
        //     cout<<"vecinos de "<<u<<": ";
        //     for(auto v: G[u]) cout<<v<<", "; cout<<'\n';
        // }


        deque<array<ll, 2>> q;
        pll D[n][2];
        rep(i, n) rep(b, 2) D[i][b] = {INF, 0};
        D[s][0] = {0, 1};
        q.push_back({s, 0}); // u, dist, cont

        while(!q.empty()) {
            auto [u, d] = q.front(); q.pop_front();
            ll cant = 0;
            if(d == D[u][0].ff + 1) cant = D[u][1].ss;
            else cant = D[u][0].ss;
            for(auto v: G[u]) {
                // Este if solo puede suceder la primera vez que entro 
                if(d + 1 < D[v][0].ff) {
                    D[v][0].ff = d + 1;
                    D[v][0].ss = D[u][0].ss;
                    q.push_back({v, D[v][0].ff}); 
                }
                // este if solo puede suceder la primera vez que entro
                else if(d + 1 == D[v][0].ff) {
                    D[v][0].ss += cant;
                    D[v][0].ss %= MOD;
                }
                // este if puede pasar cuando son paralelos o cuando tengo el delta + 1
                else if(d == D[v][0].ff) {
                    if(d + 1 < D[v][1].ff) {
                        D[v][1].ff = d + 1;
                        D[v][1].ss = cant;
                        q.push_back({v, D[v][1].ff});
                    }
                    else if(d + 1 == D[v][1].ff) {
                        D[v][1].ss += cant;
                        D[v][1].ss %= MOD;
                    }
                }
            }
        }
        ll ans = (D[t][0].ss + D[t][1].ss) % MOD;
        cout<<ans<<'\n';
    }


    return 0;
}