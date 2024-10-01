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

    int n; cin>>n;
    ll A[n]; rep(i, n) cin>>A[i];

    vector<pll> S; S.pb({n + 1, n});
    vl DP(n, 0);
    ll ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        ll curr = 0;
        while(S.back().ff < A[i]) {
            curr += 1 + max(0LL, DP[S.back().ss] - curr - 1);
            DP[i] = max(DP[i], curr);
            ans = max(ans, DP[i]);
            S.pop_back();
        }
        S.pb({A[i], i});
        // cout<<"i: "<<i<<", DP: "<<DP[i]<<'\n';
    }
    cout<<ans<<'\n';

    return 0;
}