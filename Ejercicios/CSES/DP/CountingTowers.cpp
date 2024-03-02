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

// dp(i) = sum dp(i - x) + dp2(x) * dp2(x)
// dp2(i) = sum dp2(i - x)


const ll mxN = 1e6+5;
const ll MOD = 1e9+7;

ll DP[mxN][2];


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    
    rep(i, mxN) DP[i][0] = DP[i][1] = 0;
    DP[1][0] = 1, DP[1][1] = 1;
    repx(i, 2, mxN) {
        DP[i][0] = (2 * DP[i - 1][0] + DP[i - 1][1]) % MOD;
        DP[i][1] = (4 * DP[i - 1][1] + DP[i - 1][0]) % MOD;
    }


    while(t--) {
        int n; cin>>n;
        cout<<(DP[n][0] + DP[n][1]) % MOD<<'\n';
    }


    return 0;
}