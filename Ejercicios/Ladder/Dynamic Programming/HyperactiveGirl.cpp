#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
const int mxN = 102; 
const ll MOD = 1e8;
ll DP[mxN][2 * mxN][2 * mxN];
// 200 * 100 * 100 = 2 * 10^6

vector<pll> A(mxN); 

ll dp(ll i, ll l, ll r) {
    if(r == m) return 1;
    if(i == n) return 0;
    if(A[i].ff > r + 1) return 0;

    if(DP[i][l][r] != -1) return DP[i][l][r];

    if(A[i].ss > r and A[i].ff > l) {
        // Puedo tomar el segmento
        DP[i][l][r] = dp(i + 1, r + 1, A[i].ss) + dp(i + 1, l, r);
        if(DP[i][l][r] >= MOD) DP[i][l][r] -= MOD;    
    }
    else {
        // A[i].ss <= r por lo que no es un segmento minimal y no lo puedo tomar
        DP[i][l][r] = dp(i + 1, l, r);
    }
    // cout<<i<<' '<<l<<' '<<r<<' '<<A[i].ff<<' '<<A[i].ss<<' '<<DP[i][l][r]<<'\n';

    return DP[i][l][r];
}

// 0,2
// 1,3 3
// 4,6 4
// 5,8
// 
// 0,2
// 2,5 3 4
// 5,8
// 
// 0,2
// 3,6 3 4
// 5,8
// 
// 0,3
// 3,6 4
// 5,8
// 
// 0,3
// 2,5 4
// 5,8
// 
// 0,3
// 4,6 4
// 5,8


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>m>>n and n) {
        rep(i, n) {
            cin>>A[i].ff>>A[i].ss;
        }
        sort(A.begin(), A.begin() + n);
        
        set<ll> S;
        rep(i, n) {
            S.insert(A[i].ff);
            S.insert(A[i].ss);
        }
        
        int ind = 1;
        map<ll, ll> mp;
        for(auto u: S) mp[u] = ind++;

        rep(i, n) rep(j, 2 * n + 2) rep(k, 2 * n + 2) DP[i][j][k] = -1;

        rep(i, n) {
            A[i].ff = mp[A[i].ff], A[i].ss = mp[A[i].ss];
        }
        
        if(mp.count(m)) {
            m = mp[m];
            cout<<dp(0, 0, 0)<<'\n';
        }
        else cout<<0<<'\n';
        
    }

    ll aux = 1'000'000;
    cout<<aux<<'\n';

    return 0;
}