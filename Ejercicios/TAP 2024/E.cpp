#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
#define pb push_back
#define ff first
#define ss second

const int mxN = 1e5+10;
pair<ll, bitset<200>> DP[mxN];

int n; 
ll P;
ll A[mxN], B[mxN], C[mxN];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>P;
    rep(i, n) cin>>A[i]>>B[i]>>C[i];
    vector<array<ll, 3>> X;
    rep(i, n) X.pb({A[i], B[i], C[i]});
    sort(X.begin(), X.end(), [&](const array<ll, 3>& a, const array<ll, 3>& b) {
        if(a[1] * (1 - b[0]) == b[1] * (1 - a[0])) return a[1] < b[1];
        return ll(a[1]) * (1LL - b[0]) < ll(b[1]) * (1LL - a[0]); 
    });
    reverse(X.begin(), X.end());

    rep(i, n) {
        A[i] = X[i][0], B[i] = X[i][1], C[i] = X[i][2];
    }
    
    ll DP[P + 1];
    rep(i, P + 1) DP[i] = -1e15;

    DP[0] = 0;
    ll ans = 0;
    for(auto [a, b, c]: X) {
        for(ll x = P; x >= 0; x--) if(x - b >= 0) {
            DP[x] = max(DP[x], DP[(x - b) / a] + c);
            ans = max(ans, DP[x]);
        }
    }
    cout<<ans<<'\n';

    return 0;
}

