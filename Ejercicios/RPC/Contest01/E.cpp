#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef vector<ll> vl;
#define repx(i,a,b) for(int i = a; i < b;i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second

int main() {
    int n; cin>>n;
    vl A(n); rep(i, n) cin>>A[i];
    vector<pll> E;
    ll ans = 0;
    rep(i, n) {
        while(!E.empty() and E.back().ff < A[i]) E.pop_back();
        if(!E.empty() and E.back().ff == A[i]) ans += i - E.back().ss - 1;
        E.push_back({A[i], i});
    }
    cout<<ans<<'\n';

    return 0;
}