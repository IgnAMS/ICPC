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

ll INF = 1e13 + 30; // 10^9 * 5 * 10^3
const int mxN = 1e5+5;
ll DP[mxN][500];
ll Acc[mxN], T[mxN];

ll n, g;
ll dp(int i, int j) {
    if(i == n) return 0;
    if(DP[i][j] != -1) return DP[i][j];
    DP[i][j] = dp(i + 1, j);
    if(i + j <= n) {
        DP[i][j] = max(DP[i][j], dp(i + j, j + 1) + g - (Acc[i + j] - Acc[i]));
    }
    return DP[i][j];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>g;
    rep(i, n) cin>>T[i];
    Acc[0] = 0;
    rep(i, n) Acc[i + 1] = Acc[i] + T[i];
    // rep(i, n + 1) cout<<Acc[i]<<' '; cout<<'\n';
    

    rep(i, n + 2) rep(j, 500) DP[i][j] = -1;
    cout<<dp(0, 1)<<'\n';
    
    return 0;
}