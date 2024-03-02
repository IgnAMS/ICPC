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


// DP[i][j] = max_{0 <= k <= j} dp(i + 1, k) + Acc[k]
const int mxN = 1e3+5;
vector<vl> DP, Acc, A;
const ll INF = 1e13;

int n;
ll dp(ll i, ll j) {
    if(i == n) return 0;
    if(DP[i][j] != INF) return DP[i][j];

    DP[i][j] = 0;
    rep(k, min(j + 1, n - i + 1)) {
        DP[i][j] = max(DP[i][j], dp(i + 1, k) + Acc[i][k]);
    }
    return DP[i][j];
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    A.assign(mxN, vl());
    DP.assign(mxN, vl());
    Acc.assign(mxN, vl());
    rep(i, mxN) {
        A[i].assign(i + 3, 0); 
        DP[i].assign(mxN - i + 3, 0);
        Acc[i].assign(mxN - i + 4, 0);
    }

    while(cin>>n and n) {
        ll ans = 0;
        rep(i, n + 1) {
            rep(j, i) {
                cin>>A[i][j];
                // DP[i][j] = DP[i - 1][j] + A[i][j];
                // if(j >= 1) DP[i][j] += DP[i - 1][j - 1];
                // if(i >= 2 and j >= 1) DP[i][j] -= DP[i - 2][j - 1];
                Acc[j][i - j] = A[i][j] + Acc[j][i - j - 1];
            }
        }
        rep(i, n + 1) {
            rep(j, n - i + 3) DP[i][j] = INF;
        }

        ans = dp(0, n + 1);
        cout<<ans<<'\n';
        
        // rep(i, n + 1) {
        //     for(int j = i - 1; j >= 0; j--) {
        //         for(int k = i - 1; k >= j + 1; k--) {
        //             DP[i][j] = max(
        //                 DP[i][j],
        //                 DP[i][j] + DP[i][k] - DP[i - (k - j)][j]
        //             );
        //             ans = max(ans, DP[i][j]);   
        //         }
        //         ans = max(ans, DP[i][j]);
        //     }
        // }
        // cout<<ans<<'\n';

    }





    return 0;
}