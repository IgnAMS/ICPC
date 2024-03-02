#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

ll T[1005], A[1005], W[1005];
int n;

// ll DP[1005][35][85];
// ll dp(ll i, ll a, ll b) {
//     if(i == n and (a > 0 or b > 0)) return 1e6;
//     if(i == n) return 0;
//     if(a == 0 and b == 0) return 0;
// 
//     if(DP[i][a][b] != -1) return DP[i][a][b];
// 
//     DP[i][a][b] = min({
//         dp(i + 1, max(a - T[i], 0LL), max(b - A[i], 0LL)) + W[i],
//         dp(i + 1, a, b)
//     });
//     return DP[i][a][b];
// }

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int t, a; cin>>t>>a;
        cin>>n;
        rep(i, n) cin>>T[i]>>A[i]>>W[i];
        
        
        ll DP[60][160];
        // memset(DP, 10000000, sizeof(DP));
        rep(i, 60) rep(j, 160) DP[i][j] = 10000000;
        DP[0][0] = 0;
        
        rep(i, n) {
            for(int j = 59; j >= 0; j--) for(int k = 159; k >= 0; k--) {
                DP[j][k] = min(
                    DP[j][k], 
                    DP[max(j - T[i], 0LL)][max(k - A[i], 0LL)] + W[i]
                );
                // cout<<"entre aca con "<<j<<' '<<k<<'\n';
                // cout<<DP[max(j - T[i], 0LL)][max(k - A[i], 0LL)] + W[i]<<'\n';
            }
        }
        ll ans = 1e6;
        repx(j, t, 60) repx(k, a, 160) ans = min(ans, DP[j][k]);
        cout<<ans<<'\n';
        
        // memset(DP, -1, sizeof(DP));
        // rep(i, n) rep(j, t + 1) rep(k, a + 1) DP[i][j][k] = -1;
        // cout<<dp(0, t, a)<<'\n';
    }

    return 0;
}