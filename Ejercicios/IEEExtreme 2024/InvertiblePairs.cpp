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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll n; cin>>n;
        ll A[n]; rep(i, n) cin>>A[i];

        vl P(n / 2, 0), S(n / 2, 0 ); 
        P[0] = max(
            abs(A[0] + A[1]),
            abs(A[0])
        );
        S[0] = max(
            abs(A[0] + A[1]),
            abs(A[1])
        );

        ll ans = max(P[0], S[0]);
         
        repx(i, 1, n / 2) {
            S[i] = max(
                abs(A[2 * i] + A[2 * i + 1]) + S[i - 1],
                abs(A[2 * i + 1])
            );
            P[i] = max(
                abs(A[2 * i] + A[2 * i + 1]) + S[i - 1],
                abs(A[2 * i]) + S[i - 1]
            );
            ans = max({ans, S[i], P[i]});
        }
        cout<<ans<<'\n';
    }

    return 0;
}