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
const ll mxN = 1e6+5;
const ll MOD = 1e9+7;
ll DP[mxN];
ll C[101];

ll dp(ll x) {
    if(x < 0) return 0;
    if(x == 0) return 1;

    if(DP[x] != -1) return DP[x];
    DP[x] = 0;
    rep(i, n) {
        DP[x] += dp(x - C[i]);
        if(DP[x] >= MOD) DP[x] -= MOD;
    }
    return DP[x];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    ll x; cin>>n>>x;
    rep(i, n) cin>>C[i];

    rep(i, mxN) DP[i] = -1;
    cout<<dp(x)<<'\n';


    return 0;
}