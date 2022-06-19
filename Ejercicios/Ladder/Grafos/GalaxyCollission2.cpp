#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

vector<vi> G;
vi V;
ll a, b;
ll dfs(ll u, bool p) {
    V[u] = 1;
    if(p) a++;
    else b++;
    ll ans = 1;
    for(auto v: G[u]) if(!V[v]) ans += dfs(v, !p);
    return ans;
}

ll dr[] = {-5, -4, -4, -4, -4, -4, -4, -4, -3, -3, -3, -3, -3, -3, -3, -3, -3, -2, -2, -2, -2, -2, -2, -2, -2, -2, -1, -1, -1, -1, -1, -1, -1, -1, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 5};
ll dc[] = {0, -3, -2, -1, 0, 1, 2, 3, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -4, -3, -2, -1, 0, 1, 2, 3, 4, -3, -2, -1, 0, 1, 2, 3, 0};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n;
    while(cin>>n) {
        vector<ii> P(n); rep(i, n) cin>>P[i].ff>>P[i].ss;
        map<vi, ll> mp;
        rep(i, n) mp[{P[i].ff, P[i].ss}] = i;

        G.assign(n, vi()); V.assign(n, 0);
        
        // 81
        rep(i, n) {
            rep(j, 81) {
                ll dx = P[i].ff + dr[j], dy = P[i].ss + dc[j]; 
                if(mp.count({dx, dy})) {
                    G[i].push_back(mp[{dx, dy}]); G[mp[{dx, dy}]].push_back(i);
                }
            }
        }

        
        ll ans = 0;
        rep(i, n) if(!V[i]) {
            a = b = 0;
            dfs(i, 0);
            ans += min(a, b);
        }
        cout<<ans<<'\n';
    }

    return 0;
}