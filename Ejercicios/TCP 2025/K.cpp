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

const ll MOD = 1e9+7;
const int mxN = 1e6+7;
ll DP[mxN][2];

ll dp(int x, int b) {
    if(x == 0 and b == 0) return 0;
    if(x == 0) return 1;
    // if(b == 1) return F[x]; 
    if(DP[x][b] != -1) return DP[x][b];
    if(b == 0) {
        if(x == 2) DP[x][b] = (dp(x - 1, 0) + dp(x - 1, 1)) % MOD; 
        else DP[x][b] = (2LL * dp(x - 1, 0) + dp(x - 1, 1)) % MOD;
    }
    else {
        DP[x][b] = (1LL * x * dp(x - 1, 1)) % MOD;
    }
    return DP[x][b];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    rep(i, mxN) rep(b, 2) DP[i][b] = -1;
    
    int n; cin>>n;
    // rep(i, 11) cout<<dp(i, 0)<<'\n';
    cout<<dp(n, 0)<<'\n';


    return 0;
}