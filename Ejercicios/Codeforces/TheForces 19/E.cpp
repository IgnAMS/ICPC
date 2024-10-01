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

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        ll A[n], B[n];
        rep(i, n) cin>>A[i];
        rep(i, n) cin>>B[i];


        ll L[2][n + 1], R[2][n + 1];
        ll suma1 = 0, suma2 = 0;
        rep(i, n) suma1 += A[i], suma2 += B[i];
        rep(b, 2) L[b][0] = 0, R[b][n] = 0;

        rep(i, n) L[0][i + 1] = A[i] + max(0LL, L[0][i]);
        for(int i = n - 1; i >= 0; i--) R[0][i] = A[i] + max(0LL, R[0][i + 1]);

        rep(i, n) L[1][i + 1] = B[i] + max(0LL, L[1][i]);
        for(int i = n - 1; i >= 0; i--) R[1][i] = B[i] + max(0LL, R[1][i + 1]);

        
        ll ans = -1e18;
        rep(i, n + 1) {
            ans = max({
                ans, 
                L[0][i] + R[1][i],
                L[1][i] + R[0][i],
                suma1 + L[1][i],
                suma1 + R[1][i],
                suma2 + L[0][i],
                suma2 + R[0][i],
            });
            if(i) {
                ans = max({
                    ans,
                    L[0][i],
                    L[1][i]
                });
            }
            if(i < n) {
                ans = max({
                    ans,
                    R[0][i],
                    R[1][i]
                });
            }
        }
        // cout<<R[1][0]<<' '<<L[0][n]<<'\n';
        ans = max({
            ans,
            L[0][n] + R[1][0],
            L[1][n] + R[0][0]
        });
        cout<<ans<<'\n';

    }



    return 0;
}