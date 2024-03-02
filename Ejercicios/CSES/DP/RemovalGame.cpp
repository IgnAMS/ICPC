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


int n;
const int mxN = 5005;

ll A[mxN];
ll DP[mxN][mxN][2];
ll INF = 1e15;


// 0 -> jugador, 1 -> jugador contrario
ll dp(ll a, ll b, ll s) {
    if(a == b) return (s? 0: A[a]);
    if(DP[a][b][s] != INF) return DP[a][b][s];
    
    if(s) {
        DP[a][b][s] = min(dp(a + 1, b, !s), dp(a, b - 1, !s));
    }
    else {
        DP[a][b][s] = max(dp(a + 1, b, !s) + A[a], dp(a, b - 1, !s) + A[b]);
    }

    return DP[a][b][s];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin>>A[i];

    rep(i, mxN) rep(j, mxN) rep(k, 2) DP[i][j][k] = INF;
    cout<<dp(0, n - 1, 0)<<'\n';

    return 0;
}