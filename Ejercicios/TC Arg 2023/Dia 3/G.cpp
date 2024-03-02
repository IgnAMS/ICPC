#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long
#define vl vector<ll>


int main() {
    int n; cin>>n;
    vl A(n), B(n), C(n);
    rep(i, n) {
        cin>>A[i];
        
    }
    rep(i, n) {
        cin>>B[i];
        C[i] = A[i] - B[i];
    }
    sort(C.begin(), C.end());
    ll ans = 0;
    rep(i, n) {
        int ind = upper_bound(C.begin() + i + 1, C.end(), -C[i]) - C.begin();
        // cout<<C[i]<<' ';
        ans += (n - ind);
    }
    cout<<ans<<'\n';



    return 0;
}