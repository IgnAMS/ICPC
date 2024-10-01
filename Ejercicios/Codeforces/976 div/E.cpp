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

ll binpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

const ll inv1e4 = binpow(10000, MOD - 2);


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n], P[n]; 
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>P[i], P[i] = P[i] * inv1e4 % MOD;

        ll DP[1024][2];
        rep(i, 1024) rep(b, 2) DP[i][b] = 0;
        DP[0][0] = 1;
        rep(i, n) {
            ll p = P[i], q = (1 - P[i] + MOD) % MOD;
            rep(j, 1024) DP[j][1] = (DP[j ^ A[i]][0] * p + DP[j][0] * q) % MOD;
            rep(j, 1024) DP[j][0] = DP[j][1];
        }
        ll ans = 0;
        rep(i, 1024) {
            ans += DP[i][0] * (i * i % MOD) % MOD;
            ans %= MOD; 
        }
        cout<<ans<<'\n';
    }

    return 0;
}