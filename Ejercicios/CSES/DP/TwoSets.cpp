#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const ll mxSum = 125251 + 500;
// const ll mxSum = 500;

int DP[501][mxSum];
const ll MOD = 1000000007;

ll dp(ll i, ll x) {
    if(i == 0 and x == 0) return 1;
    if(i == 0) return 0;
    if(x < 0) return 0;
    // if(x > i * (i + 1) / 2) return 0;
    if(x >= mxSum) return 0;

    if(DP[i][x] != -1) return DP[i][x];
    
    DP[i][x] = dp(i - 1, x + i) + dp(i - 1, abs(x - i));
    if(DP[i][x] >= MOD) DP[i][x] -= MOD;

    return DP[i][x];
}

ll binpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll n; cin>>n;

    memset(DP, -1, sizeof(DP));

    rep(i, 125251) DP[0][i] = 0;
    DP[0][0] = 1;
    
    repx(i, 1, 501) {
        rep(x, mxSum)  {
            if(x > i * (i + 1) / 2) {
                DP[i][x] = 0;
            }
            else {
                DP[i][x] = DP[i - 1][abs(x - i)];
                if(x + i < mxSum) DP[i][x] += DP[i - 1][x + i];
                
                if(DP[i][x] >= MOD) DP[i][x] -= MOD;
            }
        }
    }
    
    cout<<(dp(n, 0) * binpow(2, MOD - 2)) % MOD<<'\n';



    return 0;
}