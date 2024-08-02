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

const int mxN = 4e2+5;
ll DP[mxN][mxN];
ll Calc[mxN][mxN];
int n;
ll dp(ll i, ll x) {
    if(DP[i][x] != -1) return DP[i][x];
    if(i >= n - 1) return 0;
    DP[i][x] = dp(i + 1, x);
    repx(k, 1, x + 1) if(i + 2 * k <= n) {
        DP[i][x] = max(
            DP[i][x],
            dp(i + 2 * k, x - k) + Calc[i][k]
        );
    }
    return DP[i][x];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>n>>k;
    vl A(n); rep(i, n) cin>>A[i];
    sort(A.begin(), A.end());

    rep(i, n + 1) Calc[i][0] = 0;
    repx(largo, 1, n / 2 + 1) rep(i, n - 2 * largo + 1) {
        // i + 2 * largo - 1 <= n - 1
        // i <= n - 2 * largo 
        Calc[i][largo] = Calc[i + 1][largo - 1] + A[i + 2 * largo - 1] - A[i];
    }
    rep(i, n) rep(j, n) DP[i][j] = -1;

    cout<<dp(0, k)<<'\n';

    return 0;
}