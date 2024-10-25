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
// g++ -O2 E.cpp && time ./a.out <input.txt> output.txt


ll DP[501][501];
int n, m;
const ll MOD = 998244353;

ll dp(int i, int j) {
    if(i == 0 and j == 0) return 1;
    if(DP[i][j] != -1) return DP[i][j];
    if(j) {
        DP[i][j] = dp(i - 1, j) + dp(i - 1, j - 1);
    }
    else DP[i][j] = dp(i - 1, j);
    if(DP[i][j] >= MOD) DP[i][j] -= MOD;
    // cout<<"con i, j: "<<i<<" "<<j<<", tengo "<<x + m - i - j<<" en el grupo 1 y "<<j<<" en el grupo 2"<<'\n';
    // cout<<x<<' '<<i<<' '<<j<<' '<<DP[x][i][j]<<'\n';
    return DP[i][j];
}

ll DP2[501][501];


ll dp2(int i, int j) {
    if(i == -1 and j == 0) return 1;
    if(i == -1) return 0;
    if(DP2[i][j] != -1) return DP2[i][j];

    if(i == 0) {
        for(int k = 0; k + j <= m; k++) {
            DP2[i][j] += dp2(i - 1, j + k) * dp(m, k) % MOD;
            DP2[i][j] %= MOD;
        }
    }
    else {
        for(int k = 0; k <= j; k--) {
            DP2[i][j] += dp2(i - 1, j - k) * dp(m, k) % MOD;
            DP2[i][j] %= MOD;
        }
    }
    return DP2[i][j];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i, 501) rep(j, 501) DP[i][j] = -1, DP2[i][j] = -1;
    cin>>n>>m;
    cout<<dp2(n - 1, 0)<<'\n';

    return 0;
}