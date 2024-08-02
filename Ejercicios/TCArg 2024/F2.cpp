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

string s;
int n, k;
const int mxN = 455;
int DP[2][mxN][mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    cin>>s;
    rep(b, 2) rep(j, n + 1) rep(l, n + 1) DP[b][j][l] = 1e7;
    rep(b, 2) rep(j, n + 1) DP[b][j][0] = 0;

    for(int i = n - 1; i >= 0; i--) {
        rep(p, n + 1) rep(l, n + 1) DP[0][p][l] = DP[1][p][l];
        rep(p, n + 1) {
            rep(l, n + 1) {
                if(s[i] == '1' and l >= 1) DP[1][p][l] = min(DP[0][0][l - 1], DP[0][p + 1][l] + p + 1);
                else if(s[i] == '1') DP[1][p][l] = DP[0][p + 1][l] + p + 1;
                else DP[1][p][l] = DP[0][0][l];
            }
        }
    }

    rep(i, n + 1) {
        ll val = DP[1][0][i];
        if(val <= k) {
            cout<<i<<'\n';
            return 0;
        }
    }

    return 0;
}