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


ll n;
ll DP[1000][1000];
string M[1000];
ll MOD = 1e9+7;

ll dp(ll i, ll j) {
    if(M[i][j] == '*') return 0;
    if(i == n - 1 and j == n - 1) return 1;
    if(DP[i][j] != -1) return DP[i][j];
    
    // cerr<<"entre con "<<i<<' '<<j<<'\n';

    DP[i][j] = 0;
    if(i < n - 1) DP[i][j] += dp(i + 1, j);
    if(j < n - 1) DP[i][j] += dp(i, j + 1);
    if(DP[i][j] >= 2 * MOD) DP[i][j] -= MOD;
    if(DP[i][j] >= MOD) DP[i][j] -= MOD;
    return DP[i][j];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>M[i];

    rep(i, n) rep(j, n) DP[i][j] = -1;
    cout<<dp(0, 0)<<'\n';     




    return 0;
}