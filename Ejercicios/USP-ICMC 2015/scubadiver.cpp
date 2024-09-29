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

ll A[1001], T[1001], W[1001];
ll DP[1001][82][82];
ll INF = 1e8;
ll dp(int i, int a, int t) {
    if(i == -1 and a == 0 and t == 0) return 0;
    if(i == -1) return INF;
    if(DP[i][a][t] != -1) return DP[i][a][t];
    DP[i][a][t] = min(
        dp(i - 1, a, t), 
        dp(i - 1, max(0LL, a - A[i]), max(0LL, t - T[i])) + W[i]
    );
    // cout<<i<<' '<<a<<' '<<t<<' '<<DP[i][a][t]<<'\n';
    return DP[i][a][t];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int c; cin>>c;
    // cout<<1000 * 82 * 82<<'\n';
    while(c--) {
        int t, a; cin>>t>>a;
        int n; cin>>n;
        rep(i, n) cin>>T[i]>>A[i]>>W[i];
        rep(i, n + 1) rep(j, a + 2) rep(k, t + 2) DP[i][j][k] = -1;
        cout<<dp(n - 1, a, t)<<'\n';
    }
    return 0;
}