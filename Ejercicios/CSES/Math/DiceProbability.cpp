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

db DP[601][601];

db dp(ll i, ll j) {
    if(j == 0) return 0;
    if(j == 1 and 1 <= i and i <= 6) return DP[i][j] = 1;
    if(DP[i][j] != -1) return DP[i][j];
    DP[i][j] = 0;
    repx(l, max(0LL, i - 6), i) DP[i][j] += dp(l, j - 1);
    return DP[i][j];
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll n, a, b; cin>>n>>a>>b;
    rep(i, 601) DP[i][1] = 0;
    repx(i, 1, 7) DP[i][1] = 1;
    repx(i, 2, 101) {
        rep(j, 600) {
            repx(k, max(0, j - 6), j) DP[j][i] += DP[k][i - 1];

        }
    }
    db ans = 0;
    db cont = 0;
    repx(i, 0, 601) {
        if(a <= i and i <= b) ans += DP[i][n];
        cont += DP[i][n];
    }


    cout<<setprecision(6)<<fixed<<ans / cont<<'\n';

    return 0;
}