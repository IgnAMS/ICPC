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

ll n0, n;
int A[200005];


const ll MOD = 998244353;
ll binpow(ll a, ll b) {
    ll res = 1; 
    while(b) {
        if(b & 1) res = (res * a) % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

ll inv(ll x) {
    return binpow(x, MOD - 2);
}

ll DP[200005];
ll dp(ll x) {
    if(x == n0) return 0;
    if(DP[x] != -1) return DP[x];

    ll moves = n * (n - 1) / 2;
    ll m0 = (n0 - x) * (n0 - x);

    DP[x] = (((dp(x + 1) * (m0 % MOD) % MOD + moves) % MOD) * inv(m0 % MOD)) % MOD;
    return DP[x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        rep(i, n) cin>>A[i];
        rep(i, n + 1) DP[i] = -1;
        
        n0 = 0;
        rep(i, n) n0 += (A[i] == 0);
        ll x = 0;
        rep(i, n0) x += (A[i] == 0);
        cout<<dp(x)<<'\n';
    }


    return 0;
}