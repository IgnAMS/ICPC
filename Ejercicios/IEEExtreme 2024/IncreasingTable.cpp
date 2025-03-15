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

set<ll> A, B, C;
int n; 
const int mxN = 2005;
ll DP[mxN][mxN];

const ll MOD = 998244353;

ll dp(ll i, ll j) {
    if(i == 0 and j == 0) return 1;
    if(DP[i][j] != -1) return DP[i][j];

    DP[i][j] = 0;
    if(i - 1 >= j and (C.count(i + j) or A.count(i + j))) {
        DP[i][j] += dp(i - 1, j);
    }
    if(j >= 1 and (C.count(i + j) or B.count(i + j))) {
        DP[i][j] += dp(i, j - 1);
    }
    if(DP[i][j] >= MOD) DP[i][j] -= MOD;
    return DP[i][j];
} 


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    ll k1, k2;
    set<ll> S;
    cin>>k1;
    rep(i, k1) {
        ll x; cin>>x;
        A.insert(x);
        S.insert(x);
    }

    cin>>k2;
    rep(i, k2) {
        ll x; cin>>x;
        B.insert(x);
        S.insert(x);
    }

    repx(i, 1, 2 * n + 1) if(!S.count(i)) C.insert(i);

    rep(i, n + 1) rep(j, n + 1) DP[i][j] = -1;

    cout<<dp(n, n)<<'\n';


    return 0;
}