#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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


// 8 9
// 1 2
// 1 3
// 2 4
// 3 5
// 3 6
// 4 7
// 5 7
// 5 8
// 6 8


// DP[i][j] = 1 si puedo de ir de j a 0 sin haber pasado por i
const int mxN = 1e3+5;
ll DP[mxN][mxN];
vl G[mxN];

ll dp(ll i, ll j) {
    if(i == 0 or j == 0) return 1;
    if(i == j) return 0;

    if(i > j) swap(i, j);

    if(DP[i][j] != -1) return DP[i][j];

    DP[i][j] = 0;
    for(auto v: G[j]) if(dp(i, v)) {
        DP[i][j] = 1;
        break;
    }
    return DP[i][j];  
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m;
    while(cin>>n>>m) {
        rep(i, n) rep(j, n) DP[i][j] = -1;

        rep(i, m) {
            int u, v; cin>>u>>v; u--, v--;
            G[v].pb(u);
        }

        ll ans = 0;
        rep(i, n) repx(j, i + 1, n) {
            // cout<<i<<' '<<j<<' '<<dp(i, j)<<'\n';
            if(dp(i, j)) ans++;
        }

        rep(i, n) G[i].clear();

        cout<<ans<<'\n';
    }

    return 0;
}