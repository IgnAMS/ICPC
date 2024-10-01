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

const int mxN = 2e5+10;
ll DP[mxN][2];
ll A[mxN][2];

ll n;
ll dp(ll i, ll b) {
    if(i == n) return 0;
    if(DP[i][b] != -1) return DP[i][b];
    DP[i][b] = 1e16;
    rep(c, 2) {
        DP[i][b] = min(
            DP[i][b],
            dp(i + 1, c) + abs(A[i][b] - A[i + 1][c]) + abs(A[i][!b] - A[i + 1][!c])
        );
    }
    return DP[i][b];
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, 2 * n) {
        ll x; cin>>x;
        if(A[x][0] == 0) A[x][0] = i + 1;
        else A[x][1] = i + 1;
    }

    rep(i, n + 1) rep(b, 2) DP[i][b] = -1;
    A[0][0] = A[0][1] = 1;
    cout<<dp(0, 0)<<'\n';




    return 0;
}