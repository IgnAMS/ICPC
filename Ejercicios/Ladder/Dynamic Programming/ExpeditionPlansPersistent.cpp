#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include<iostream>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
// typedef vector<ll> vl;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 3e3+5;
ll DP[mxN][mxN][2];
ll D[mxN], F[mxN], S[mxN], Acc[mxN];

ll cost(int i, int j) { return Acc[j] - Acc[i]; }

int n;

ll dp(int i, int j, int u)  {
    if(i == j) return F[i];
    if(DP[i][j][u] != -1) return DP[i][j][u];
    DP[i][j][u] = 1e18;
    if(u == 0) {
        for(int k = i; k < j; k++) {
            DP[i][j][u] = min(DP[i][j][u], cost(i, k) + D[k] + max(dp(i, k, 1), dp(k + 1, j, 0) + (k + 1 != j) * cost(k, k + 1)));
        }
    }
    else {
        for(int k = i; k < j; k++) {
            DP[i][j][u] = min(DP[i][j][u], cost(k, j) + D[k] + max(dp(i, k, 1), dp(k + 1, j, 0) + (k + 1 != j) * cost(k, k + 1)));
            // cerr<<"cost, D, maxdp: "<<cost(k, j)<<' '<<D[k]<<' '<<max(dp(i, k, 1), dp(k + 1, j, 0))<<" aaaa\n\n";
        }
    }
    // cerr<<"DP: "<<i<<' '<<j<<' '<<u<<' '<<DP[i][j][u]<<'\n';
    return DP[i][j][u];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n - 1) cin>>S[i];
    rep(i, n) cin>>D[i];
    rep(i, n + 1) cin>>F[i];
    Acc[0] = 0;
    rep(i, n - 1) Acc[i + 1] = Acc[i] + S[i];
    Acc[n] = Acc[n - 1];
    D[n] = 0;
    int opt[n + 1][n + 1][2];
    // memset(DP, -1, sizeof(DP));
    rep(i, n + 1) rep(j, n + 1) rep(u, 2) DP[i][j][u] = -1; 
    // DP[i][j] = min {i<=k<j} (cost(i, k) + max(dp(i, k), dp(k + 1, j)))
    for (int i = 0; i <= n; i++) {
        opt[i][i][0] = opt[i][i][1] = i;
        // Initialize dp[i][i] according to the problem
        DP[i][i][0] = DP[i][i][1] = F[i];
    }
    int margin = 80;
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j <= n; j++) {
            for(int u = 0; u < 2; u++){ 
                ll mn = 1e18;
                for (int k = max(i, opt[i][j-1][u] - margin); k <= min(j - 1, opt[i+1][j][u] + margin); k++) {
                    ll costo = (u == 0 ? cost(i, k): cost(k, j)) + D[k] + max(DP[i][k][1], DP[k + 1][j][0] + (k + 1 != j) * cost(k, k + 1)); 
                    if (mn >= costo) {
                        opt[i][j][u] = k;   
                        mn = costo;
                    }
                }
                DP[i][j][u] = mn; 
            }
        }
    }
    cout<<DP[0][n][0]<<'\n';
    // cout<<dp(0, n, 0)<<'\n';

    return 0;
}