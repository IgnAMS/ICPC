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


ll DP[51][51];

ll dp(int i, int x) { 
    if(i == x or x == 0) return 0;
    if(DP[i][x] != -1) return DP[i][x];

    DP[i][x] = 51;
    // j <= x
    // j <= j
    // x - k <= i - j -> x - i + j <= k
    repx(j, 1, i) {
        ll estrat = 0;
        repx(k, max(0, x - i + j), min(x, j) + 1) {
            estrat = max(estrat, 1 + dp(j, k) + dp(i - j, x - k));
        }
        DP[i][x] = min(DP[i][x], estrat);
    }
    // repx(j, max(0, x - i + m), min(x, m) + 1) {
    //     DP[i][x] = max(DP[i][x], 1 + dp(m, j) + dp(i - m, x - j));
    // }
    return DP[i][x];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    rep(i, 51) rep(j, 51) DP[i][j] = -1;
    int n, x; cin>>n>>x;
    cout<<dp(n, x)<<'\n';

    // rep(i, 51) {
    //     cout<<i<<'\n';
    //     rep(j, i + 1) cout<<dp(i, j)<<' '; cout<<'\n';
    // }y
    return 0;
}