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

int n, m, k;
ll DP[501][501][20];
ll H[501][501], V[501][501];


ll dp(ll i, ll j, ll k) {
    if(k == 0) return 0;
    if(DP[i][j][k] != -1) return DP[i][j][k];

    DP[i][j][k] = 1e9;
    if(i >= 1) DP[i][j][k] = min(DP[i][j][k], dp(i - 1, j, k - 1) + V[i - 1][j]);
    if(j >= 1) DP[i][j][k] = min(DP[i][j][k], dp(i, j - 1, k - 1) + H[i][j - 1]);
    if(i + 1 < n) DP[i][j][k] = min(DP[i][j][k], dp(i + 1, j, k - 1) + V[i][j]);
    if(j + 1 < m) DP[i][j][k] = min(DP[i][j][k], dp(i, j + 1, k - 1) + H[i][j]);
    return DP[i][j][k];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    rep(i, n) rep(j, m - 1) cin>>H[i][j];
    rep(i, n - 1) rep(j, m) cin>>V[i][j];
    if(k & 1) {
        rep(i, n) {
            rep(j, m) cout<<"-1 "; cout<<'\n';
        }
        return 0;
    }

    k /= 2;

    rep(i, n) rep(j, m) rep(l, k + 1) DP[i][j][l] = -1;
    // for(int l = 1; l <= k; l++) {
    //     rep(i, n) rep(j, m) {
    //         DP[i][j][l] = 1e9;
    //         if(i >= 1) DP[i][j][l] = min(DP[i][j][l], DP[i - 1][j][l - 1] + V[i - 1][j]);
    //         if(j >= 1) DP[i][j][l] = min(DP[i][j][l], DP[i][j - 1][l - 1] + H[i][j - 1]);
    //         if(i + 1 < n) DP[i][j][l] = min(DP[i][j][l], DP[i + 1][j][l - 1] + V[i][j]);
    //         if(j + 1 < m) DP[i][j][l] = min(DP[i][j][l], DP[i][j + 1][l - 1] + H[i][j]);
    //         // cout<<"tengo que "<<i<<' '<<j<<' '<<l<<" tiene su optimo en "<<DP[i][j][l]<<'\n';
    //     }
    // }

    rep(i, n) {
        rep(j, m) cout<<2 * dp(i, j, k)<<' '; cout<<'\n';
    }




    return 0;
}