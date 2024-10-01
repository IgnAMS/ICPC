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

const int mxN = 5000 + 5;
ll DP[mxN][mxN];
ll F[mxN];
int n, comps;

ll dp(ll i, ll x) {
    if(i == comps) return 0;
    if(DP[i][x] != -1) return DP[i][x];
    DP[i][x] = dp(i + 1, x + 1);
    if(x >= F[i]) {
        DP[i][x] = max(DP[i][x], dp(i + 1, x - F[i]) + 1);
    }
    return DP[i][x];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        cin>>n;
        vl A(n);
        set<ll> S;
        rep(i, n) {
            cin>>A[i];
            S.insert(A[i]);
        }
        
        vl Compress;
        for(auto u: S) Compress.pb(u);
        sort(A.begin(), A.end());
        rep(i, n) A[i] = lower_bound(Compress.begin(), Compress.end(), A[i]) - Compress.begin();

        rep(i, n) F[i] = 0;
        rep(i, n) F[A[i]]++;
        rep(i, n) rep(j, n) DP[i][j] = -1;

        comps = S.size();
        dp(0, 0);
        cout<<comps - dp(0, 0)<<'\n';
    }


    return 0;
}