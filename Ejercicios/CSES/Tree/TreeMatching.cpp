#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<iostream>
#include<vector>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
const int mxN = 2e5 + 10;
vector<int> G[mxN];
ll DP[mxN][3];
int n;

// 0 es que no se conectará con un hijo
// 1 es que se debe conectar con un hijo
ll dp(int u, int b, int p) {
    if(DP[u][b] != -1) return DP[u][b];
    if(G[u].size() == 1 and u != 0) return 0;

    DP[u][b] = 0;
    if(b == 0) {
        for(auto v: G[u]) if(v != p) {
            DP[u][b] += max(dp(v, 0, u), dp(v, 1, u));
        }
    }
    else if(b == 1) {
        ll suma = 0;
        for(auto v: G[u]) if(v != p) {
            suma += max(dp(v, 0, u), dp(v, 1, u));
        }
        // tomo exactamente uno de los hijos :)
        for(auto v: G[u]) if(v != p) {
            DP[u][b] = max(DP[u][b], 1 + dp(v, 0, u) + suma - max(dp(v, 1, u), dp(v, 0, u)));
        }
    }
    // cout<<u<<" "<<b<<" "<<DP[u][b]<<"\n";
    return DP[u][b];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    rep(i, n+1) rep(b, 2) DP[i][b] = -1;
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    cout<<max(dp(0, 0, -1), dp(0, 1, -1))<<"\n";
    return 0;
}
