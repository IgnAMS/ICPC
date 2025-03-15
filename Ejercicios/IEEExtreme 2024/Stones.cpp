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


db DP[42][42][42][42][2];
db dp(int r1, int b1, int r2, int b2, int b) {
    if(r1 == 0 or b1 == 0) return 0.;
    if(r2 == 0 or b2 == 0) return 1.;

    if(DP[r1][b1][r2][b2][b] > -0.5) return DP[r1][b1][r2][b2][b];
    if(b) {
        db p = db(r2) / db(r2 + b2), 
           q = 1.0 - p;
        DP[r1][b1][r2][b2][b] = min(
            p * dp(r1, b1, r2 - 1, b2, 1 ^ b) + q * dp(r1 - 1, b1, r2, b2, 1 ^ b),
            q * dp(r1, b1, r2, b2 - 1, 1 ^ b) + p * dp(r1, b1 - 1, r2, b2, 1 ^ b)
        );
    }
    else {
        db p = db(r1) / db(r1 + b1), 
           q = 1.0 - p;
        DP[r1][b1][r2][b2][b] = max(
            p * dp(r1 - 1, b1, r2, b2, 1 ^ b) + q * dp(r1, b1, r2 - 1, b2, 1 ^ b),
            q * dp(r1, b1 - 1, r2, b2, 1 ^ b) + p * dp(r1, b1, r2, b2 - 1, 1 ^ b)
        );
    }
    cout<<r1<<' '<<b1<<' '<<r2<<' '<<b2<<' '<<b<<' '<<DP[r1][b1][r2][b2][b]<<'\n';
    return DP[r1][b1][r2][b2][b]; 
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll r1, r2, b1, b2; cin>>r1>>r2>>b1>>b2;
    rep(a, 42) rep(b, 42) rep(c, 42) rep(d, 42) rep(e, 2) DP[a][b][c][d][e] = -1;

    cout<<setprecision(8)<<fixed<<dp(r1, b1, r2, b2, 0)<<'\n';

    ll x = 2;
    rep(i, 29) x = 2 * x + 1;  
    cout<<x<<'\n';
    return 0;
}