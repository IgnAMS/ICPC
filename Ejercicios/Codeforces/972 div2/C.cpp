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
ll DP[1001][1001][5];
map<char, ll> mp = {
    {'n', 0}, {'a', 1}, {'r', 2}, {'e', 3}, {'k', 4}
};
string S[1001];

const ll INF = 1e8;

ll dp(ll i, ll j, ll c) {
    if(i == n) return -2 * c;

    if(DP[i][j][c] != INF) return DP[i][j][c];
    DP[i][j][c] = -INF;
    if(j == 0) DP[i][j][c] = dp(i + 1, j, c);
    if(j == m) {
        DP[i][j][c] = max(DP[i][j][c], dp(i + 1, 0, c));
        return DP[i][j][c];
    }

    if(mp.count(S[i][j]) and mp[S[i][j]] == c) 
        DP[i][j][c] = max(DP[i][j][c], dp(i, j + 1, (c + 1) % 5) + 1);

    else if(mp.count(S[i][j]) and mp[S[i][j]] != c) {
        DP[i][j][c] = max(DP[i][j][c], dp(i, j + 1, c) - 1);
    }
    else DP[i][j][c] = max(DP[i][j][c], dp(i, j + 1, c));

    return DP[i][j][c];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n>>m;
        rep(i, n) cin>>S[i];
        rep(i, n + 1) rep(j, m + 1) rep(c, 5) DP[i][j][c] = INF;
        ll ans = 0;

        rep(i, n) ans = max(ans, dp(i, 0, 0));
        cout<<ans<<'\n';
    }


    return 0;
}