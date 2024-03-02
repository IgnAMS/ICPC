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


unordered_map<ll, ll> DP[22][22];
ll DP2[22][22][64][2];

ll n, m, k;
ll A[22][22];

// 20 * 20 * 2 * 64
ll dp2(ll i, ll j, ll bit, ll x) {
    if(i == 0 and j == 0 and x == bool(k & (1LL<<bit))) {
        return 1;
    }
    if(i == n - 1 and j == m - 1) return 0;
    if(DP2[i][j][bit][x] != -1) return DP2[i][j][bit][x];

    DP2[i][j][bit][x] = 0;
    if(i < n - 1) DP2[i][j][bit][x] |= dp2(i + 1, j, bit, x ^ ((A[i + 1][j] & (1LL<<bit))) / (1LL<<bit));
    if(j < m - 1) DP2[i][j][bit][x] |= dp2(i, j + 1, bit, x ^ ((A[i][j + 1] & (1LL<<bit))) / (1LL<<bit));
    return DP2[i][j][bit][x];
}


ll dp(ll i, ll j, ll x) {
    if(i == n - 1 and j == m - 1 and x == k) return 1;
    if(i == n - 1 and j == m - 1) return 0;
    if(DP[i][j].count(x)) return DP[i][j][x];
    // cout<<"Entre con "<<i<<' '<<j<<' '<<x<<'\n';
    DP[i][j][x] = 0;
    if(i < n - 1) {
        bool pos = 1;
        rep(bit, 60) {
            ll aux = ((x & (1LL<<bit)) ^ ((A[i + 1][j] & (1LL<<bit)))) / (1LL<<bit);
            if(!dp2(i + 1, j, bit, aux)) {
                pos = 0;
                break;
            }
        }
        if(pos) DP[i][j][x] += dp(i + 1, j, x ^ A[i + 1][j]);
        // else cout<<"no puedo ir a "<<i + 1<<' '<<j<<'\n';
    }
    if(j < m - 1) {
        bool pos = 1;
        rep(bit, 60) {
            ll aux = ((x & (1LL<<bit)) ^ ((A[i][j + 1] & (1LL<<bit)))) / (1LL<<bit);
            if(!dp2(i, j + 1, bit, aux)) {
                pos = 0;
                break;
            }
        }
        if(pos) DP[i][j][x] += dp(i, j + 1, x ^ A[i][j + 1]);
    }
    return DP[i][j][x];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i, n) rep(j, m) cin>>A[i][j];
    // 10^7 / (400) = 10^4
    rep(i, n) rep(j, m) DP[i][j].reserve(1000);
    rep(i, n) rep(j, m) rep(bit, 64) rep(x, 2) DP2[i][j][bit][x] = -1;

    cout<<dp(0, 0, A[0][0])<<'\n';

    return 0;
}