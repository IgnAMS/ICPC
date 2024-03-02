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

const int mxN = 8;
db DP[mxN][mxN][mxN][mxN * 7];
ll Balls[mxN];
ll Acc[mxN];
db F[mxN * 7];

db dp(ll i, ll sum1, ll sum2, ll suma, ll n) {
    if(i == -1 and sum1 == sum2 and suma == n) return 1;
    if(i == -1 or suma > n) return 0;

    if(DP[i][sum1][sum2][suma] > -0.5) return DP[i][sum1][sum2][suma];
    
    DP[i][sum1][sum2][suma] = 0;
    rep(k, Balls[i] + 1) {
        ll aux1 = k > 0;
        ll aux2 = k < Balls[i];
        db comb1 = F[suma + k] / (F[k] * F[suma]);
        db comb2 = F[Acc[i] - suma + (Balls[i] - k)] / (F[Balls[i]  - k] * F[Acc[i] - suma]);
        DP[i][sum1][sum2][suma] += dp(i - 1, sum1 + aux1, sum2 + aux2, suma + k, n) * comb1 * comb2;
    }
    return DP[i][sum1][sum2][suma];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int k; cin>>k;
    rep(i, k) cin>>Balls[i];
    Acc[k - 1] = 0;
    for(int i = k - 2; i >= 0; i--) {
        Acc[i] = Acc[i + 1] + Balls[i + 1];
    }

    rep(i, mxN) rep(sum1, mxN) rep(sum2, mxN) rep(suma, 56) DP[i][sum1][sum2][suma] = -1; 
    F[0] = 1;
    repx(i, 1, 56) F[i] = db(F[i - 1]) * db(i);
    
    int n = 0;
    rep(i, k) n += Balls[i];
    n /= 2;

    db total = F[2 * n];
    rep(i, k) total /= F[Balls[i]];
    cout<<setprecision(10)<<fixed<<db(dp(k - 1, 0, 0, 0, n)) / db(total)<<'\n';


    return 0;
}