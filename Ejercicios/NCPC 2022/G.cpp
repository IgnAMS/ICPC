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


int n, k;
db P[5001];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    rep(i, n) cin>>P[i];
    sort(P, P + n);
    db DP[10001][2];
    rep(i, 10001) rep(b, 2) DP[i][b] = 0;
    DP[n][0] = 1;
    db ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 2 * n; j++) {
            DP[j][1] = DP[j + 1][0] * P[i] + (j > 0? DP[j - 1][0] * (1 - P[i]): 0);
        }
        db curr = 0;
        rep(j, 2 * n + 1) {
            DP[j][0] = DP[j][1];
            if(j <= n - k) curr += DP[j][0]; 
        }
        ans = max(ans, curr);
    }
    cout<<setprecision(8)<<fixed<<ans<<'\n';

    return 0;
}