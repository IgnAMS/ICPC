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

ll n, m;
ll A[100005];
ll DP[100005][101];
ll MOD = 1e9+7;

ll dp(ll i, ll x) {
    if(i == n - 1 and A[i] != 0 and x == A[i]) return 1;
    if(i == n - 1 and A[i] == 0) return 1;
    
    if(A[i] != 0 and x != A[i]) return 0;
    
    if(DP[i][x] != -1) return DP[i][x];
    // cerr<<"entre con "<<i<<' '<<x<<'\n';

    DP[i][x] = 0;
    DP[i][x] += dp(i + 1, x);
    if(x < m) DP[i][x] += dp(i + 1, x + 1);
    if(x > 1) DP[i][x] += dp(i + 1, x - 1);
    
    while(DP[i][x] >= MOD) DP[i][x] -= MOD;
    // cout<<i<<' '<<x<<' '<<DP[i][x]<<'\n';
    return DP[i][x];
}



// DP[i][x] += DP[i + 1][x - 1] + DP[i + 1][x] + DP[i + 1][x + 1]

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) cin>>A[i];
    rep(i, 100005) rep(j, 101) DP[i][j] = -1;

    ll ans = 0;
    repx(i, 1, m + 1) {
        ans += dp(0, i);
        if(ans >= MOD) ans -= MOD;
    }
    cout<<ans<<'\n';

    return 0;
}