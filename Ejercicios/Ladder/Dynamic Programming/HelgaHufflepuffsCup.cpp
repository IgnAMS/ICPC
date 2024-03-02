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

const int mxN = 1e5+5;
const ll MOD = 1e9+7;
ll DP[mxN][11][3];
ll V[mxN];
vl G[mxN];
ll n, m, k, x;

void dp(ll u, ll parent) {
    if(V[u]) return;
    V[u] = 1;

    DP[u][0][0] = k - 1; 
    DP[u][1][1] = 1; 
    DP[u][0][2] = m - k;

    for(auto v: G[u]) if(v != parent) {
        dp(v, u);
        ll newDP[11][3]; 
        memset(newDP, 0, sizeof(newDP));
        
        // i + j <= 10 -> j <= 10 - i
        rep(i, 10 + 1) rep(j, 10 - i + 1) {
            // si soy menor a k puedo transicionar a cualquiera
            newDP[i + j][0] += DP[u][i][0] * (DP[v][j][0] + DP[v][j][1] + DP[v][j][2]) % MOD;
            newDP[i + j][0] %= MOD;
            
            // si soy igual a k solo puedo transicionar a los que son menores a k
            newDP[i + j][1] += DP[u][i][1] * (DP[v][j][0]) % MOD;
            newDP[i + j][1] %= MOD;

            // si soy mayor a k entonces solo puedo transicionar a mayores o menores, no puedo transicionar a iguales
            newDP[i + j][2] += DP[u][i][2] * (DP[v][j][0] + DP[v][j][2]) % MOD;
            newDP[i + j][2] %= MOD;
        }
        rep(i, 11) rep(j, 3) DP[u][i][j] = newDP[i][j];
    }
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v);
        G[v].pb(u);
    }
    cin>>k>>x;

    ll ans = 0;
    dp(0, -1);

    rep(i, x + 1) rep(j, 3) ans += DP[0][i][j];
    ans %= MOD;
    cout<<ans<<'\n';

    return 0;
}