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

string a, b; 
int n, m;
ll DP[5001][5001];

ll dp(ll i, ll j) {
    if(i == n) return m - j;
    if(j == m) return n - i;
    if(DP[i][j] != -1) return DP[i][j];

    DP[i][j] = 1e10;
    DP[i][j] = min({
        DP[i][j],
        dp(i + 1, j) + 1,       // add letter to b
        dp(i, j + 1) + 1,       // add letter to a
        dp(i + 1, j + 1) + (a[i] != b[j]) // replace the letter or advance
    });
    return DP[i][j];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b;
    n = a.length(), m = b.length();

    rep(i, 5001) rep(j, 5001) DP[i][j] = -1;

    cout<<dp(0, 0)<<'\n';

    return 0;
}