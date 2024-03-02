#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 5005;
// db DP[2 * mxN][2];
// 5000 * 10000 * 2 = 100000000
vector<db> P;
int n, k;

// la probabilidad de fallar es que la DP[n][x] < k
// 10^3 * 10^
// db dp(int i, int x, int b) {
//     // si me quedan x entonces he usado n - x 
//     if(i == n and n - x >= k) return 1;
//     if(i == n) return 0;
// 
//     if(DP[i][x][b] > -0.5) return DP[i][x][b];
// 
//     DP[i][x][b] = dp(i + 1, x - 1, 1) * P[i] + dp(i + 1, x + 1, 1) * (1. - P[i]);
//     if(!b) DP[i][x][b] = max(DP[i][x][b], dp(i + 1, x, b));
//     
//     return DP[i][x][b];
// }


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    P.resize(n);
    rep(i, n) cin>>P[i];
    sort(P.begin(), P.end());
    
    // rep(i, mxN) rep(x, mxN) rep(b, 2) DP[i][x][b] = -1;
    // cout<<setprecision(10)<<fixed<<dp(0, n, 0)<<'\n';


    db DP_curr[2 * mxN][2];
    rep(x, 2 * mxN) rep(b, 2) {
        DP_curr[x][b] = (x - n >= k);
    }

    for(int i = n - 1; i >= 0; i--) {
        db DP_new[2 * mxN][2];
        rep(x, 2 * mxN) rep(b, 2) if(x - 1 >= 0 and x + 1 < mxN) {
            DP_new[x][b] = DP_curr[x + 1][1] * P[i] + DP_curr[x - 1][1] * (1. - P[i]);
            if(!b) DP_new[x][b] = max(DP_new[x][b], DP_curr[x][b]);
        }
        rep(x, 2 * mxN) rep(b, 2) DP_curr[x][b] = DP_new[x][b];
    }
    cout<<setprecision(10)<<fixed<<DP_curr[n][0]<<'\n';

    return 0;
}