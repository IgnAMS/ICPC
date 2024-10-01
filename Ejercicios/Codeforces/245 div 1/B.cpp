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

int n, m; 
ll A[1001][1001];


// 0: (0, 0)         -> (n - 1, m - 1)
// 1: (n - 1, m - 1) -> (0, 0)
// 2: (0, m - 1)     -> (n - 1, 0)
// 3: (n - 1, 0)     -> (0, m - 1)
ll DP[1001][1001][4];
pll fin[] = {{n - 1, m - 1}, {0, 0}, {n - 1, 0}, {0, m - 1}};
pll d[4][2] = {
    {{1, 0}, {0, 1}},
    {{-1, 0}, {0, -1}},
    {{1, 0}, {0, -1}},
    {{-1, 0}, {0, 1}}
};

ll dp(int i, int j, int k) {
    if(i == fin[k].ff and j == fin[k].ss) return A[i][j];
    if(DP[i][j][k] != -1) return DP[i][j][k];

    DP[i][j][k] = A[i][j];
    rep(h, 2) {
        int di = i + d[k][h].ff, dj = j + d[k][h].ss;
        if(0 <= di and di < n and 0 <= dj and dj < m) {
            DP[i][j][k] = max(DP[i][j][k], dp(di, dj, k) + A[i][j]);
        }
    }
    return DP[i][j][k];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    rep(i, n) rep(j, m) cin>>A[i][j];
    ll ans = 0;
    memset(DP, -1, sizeof(DP));
    repx(i, 1, n - 1) repx(j, 1, m - 1) {
        ll val = dp(i + 1, j, 0) + dp(i - 1, j, 1) + dp(i, j - 1, 2) + dp(i, j + 1, 3);
        ll val2 = dp(i, j + 1, 0) + dp(i, j - 1, 1) + dp(i + 1, j, 2) + dp(i - 1, j, 3);
        ans = max({ans, val, val2});
    }
    cout<<ans<<'\n';


    return 0;
}