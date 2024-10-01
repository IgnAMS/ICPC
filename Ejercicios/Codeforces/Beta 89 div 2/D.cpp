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

int n1, n2, k1, k2;
const ll MOD = 1e8;

ll DP[101][101][11][11];
ll dp(int n1, int n2, int x1, int x2) {
    if(x1 > k1 or x2 > k2) return 0;
    if(n1 == 0 and n2 == 0) return 1;
    if(DP[n1][n2][x1][x2] != -1) return DP[n1][n2][x1][x2];
    
    DP[n1][n2][x1][x2] = 0;
    if(n1) DP[n1][n2][x1][x2] += dp(n1 - 1, n2, x1 + 1, 0);
    if(n2) DP[n1][n2][x1][x2] += dp(n1, n2 - 1, 0, x2 + 1);
    
    while(DP[n1][n2][x1][x2] >= MOD) DP[n1][n2][x1][x2] -= MOD;
    return DP[n1][n2][x1][x2];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n1>>n2>>k1>>k2;
    memset(DP, -1, sizeof(DP));
    cout<<dp(n1, n2, 0, 0)<<'\n';

    return 0;
}