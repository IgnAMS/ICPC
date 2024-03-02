#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

db DP[101][101];
int n, k;
db F[101];
db Prob(ll i, ll j) {
    if(i == 1 or j == 0) return 1;
    if(DP[i][j] >= 0) return DP[i][j];
    DP[i][j] = 0;
    repx(l, (j == n), j + 1) {
        DP[i][j] += Prob(i - 1, j - l) * F[j] / (F[l] * F[j - l]);
    }
    return DP[i][j];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    F[0] = 1;
    rep(i, 101) rep(j, 101) DP[i][j] = -1;
    repx(i, 1, 101) {
        F[i] = F[i - 1] * db(i);
    } 
    db ans = 0;
    repx(i, 1, k + 1) {
        ans += db(i) * Prob(i, n) / (pow(k, n));
    }
    cout<<setprecision(6)<<fixed<<ans<<'\n';



    return 0;
}