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


const int mxN = 1e6+5;
int DP[10][mxN];
int P[10][mxN];
int A[10];

int dp(ll i, ll x) {
    if(i == -1) return 0;
    if(DP[i][x] != -1) return DP[i][x];
    DP[i][x] = dp(i - 1, x);
    P[i][x] = -1;
    if(x >= A[i] and dp(i, x - A[i]) + 1 >= DP[i][x]) {
        DP[i][x] = dp(i, x - A[i]) + 1;
        P[i][x] = i;
    }
    return DP[i][x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    ll v; cin>>v;
    rep(i, 9) cin>>A[i];
    rep(i, 10) rep(j, mxN) DP[i][j] = -1;
    dp(8, v);
    string s = "";
    int ind = 8;
    while(ind >= 0) {
        if(P[ind][v] >= 0) {
            s += char(P[ind][v] + 1 + '0');
            v -= A[P[ind][v]];
        }
        else ind--;
    }
    if(s == "") cout<<"-1\n";
    else cout<<s<<'\n';





    return 0;
}