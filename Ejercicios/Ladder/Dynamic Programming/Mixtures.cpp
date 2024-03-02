#pragma GCC optimize("Ofast")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 101;
ll A[mxN];
int n; 

int main() {
    // ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>n) {
        rep(i, n) cin>>A[i];
        ll DP[n][n];
        ll S[n][n];
        rep(i, n) S[i][i] = A[i], DP[i][i] = 0;
        repx(len, 2, n + 1) {
            rep(i, n) {
                int j = i + len - 1;
                if(j >= n) continue;
                DP[i][j] = 1e10;
                repx(k, i, j) {
                    // cerr<<i<<' '<<k<<' '<<j<<'\n';
                    ll cost = DP[i][k] + DP[k + 1][j] + S[i][k] * S[k + 1][j];
                    if(cost < DP[i][j]) {
                        DP[i][j] = cost;
                        S[i][j] = (S[i][k] + S[k + 1][j]) % 100;
                    }
                }
            }
        }
        cout<<DP[0][n - 1]<<'\n';
    }


    return 0;
}