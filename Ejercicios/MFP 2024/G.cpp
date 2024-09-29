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


// 3 4
// 2, 1, 2 -> [2, 2], [2, 1, 2]

// 3 3
// 2, 1, 2 -> [2, 1], [2, 2]


// 4 5 
// 2 1 2 3 -> [2, 1, 2], [2, 1, 3], [2, 2, 3], [2, 3]

// 4 5
// 2 3 2 1 -> [2, 2, 1]

// 5 14
// 9 2 3 12 12 -> [9, 2, ]


ll N, X;
ll A[1505];
ll MOD = 1e9+7;
ll DP[1505][1505];

ll dp(int i, int x) {
    if(x >= X) return 1;
    if(i == N and x >= X) return 1;
    if(i == N) return 0;

    if(DP[i][x] != -1) return DP[i][x];
    
    DP[i][x] = dp(i + 1, x) + (x >= A[i]? dp(i + 1, x + A[i]): 0LL);

    if(DP[i][x] >= MOD) DP[i][x] -= MOD;
    // cout<<i<<' '<<x<<' '<<DP[i][x]<<'\n';
    return DP[i][x];
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>N>>X;
    rep(i, N) cin>>A[i];
    sort(A + 1, A + N);
    rep(i, N + 1) rep(j, X + 1) DP[i][j] = -1;
    cout<<dp(1, A[0])<<'\n';

    return 0;
}