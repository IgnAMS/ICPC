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


ll DP[505][505];
ll dp(ll n, ll x) {
    if(n == 0) return 1;
    if(DP[n][x] != -1) return DP[n][x];
    DP[n][x] = 0;
    for(int i = x + 1; i <= n; i++) DP[n][x] += dp(n - i, i);
    // cout<<n<<' '<<x<<' '<<DP[n][x]<<'\n';
    return DP[n][x];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    rep(i, n + 1) rep(j, n + 1) DP[i][j] = -1;
    cout<<dp(n, 0) - 1<<'\n';


    return 0;
}