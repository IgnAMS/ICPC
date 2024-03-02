#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>


int main() {
    int n, k, a; cin>>n>>k>>a;
    int m; cin>>m;
    ll ans = -1;
    set<ll> S;
    S.insert(0); S.insert(n + 1);
    ll curr = (n + 1) / (a + 1); 
    vl A(m);
    rep(i, m) {
        cin>>A[i];
        int l = *prev(S.lower_bound(A[i]));
        int r = *S.lower_bound(A[i]);
        // cout<<curr<<' '<<l<<' '<<r<<'\n';
        curr -= (r - l) / (a + 1);
        curr += (r - A[i]) / (a + 1);
        curr += (A[i] - l) / (a + 1);
        if(curr < k) {
            ans = i + 1;
            break;
        }
        S.insert(A[i]);
    }
    cout<<ans<<'\n';

    return 0;
}