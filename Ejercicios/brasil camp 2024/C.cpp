#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define ar array
#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define int long long
 
const int mxN = 5010, M = 1e9+7;
ll dp[mxN][mxN/2], dp2[mxN][mxN/2];
const ll INF = 1e17;
 
signed main(){
#ifdef _DEBUG
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", " w", stdout);
#endif
    std::ios_base::sync_with_stdio(false); std::cin.tie(0); std::cout.tie(0);
 
    
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n){
        cin >> a[i];
    }

    rep(i, mxN) rep(j, mxN / 2) dp[i][j] = INF, dp2[i][j] = INF;
    for(int i = 0; i<n; ++i) {
        ll val1 = 0, val2 = 0;
        if(i) val1 += max(0LL, (a[i-1]+1)-a[i]);
        if(i < n - 1) val2 += max(0LL, (a[i+1]+1)-a[i]);
        dp[i][1] = val1+val2;
        dp2[i][1] = val1+val2;
        if(i) {
            dp2[i][1] = min(dp2[i-1][1], dp2[i][1]);
        }
    }
    for(int k = 2; k<=(n+1)/2; ++k){
        for(int i = 2; i<n; ++i){
            ll val1 = 0, val2 = 0;
            if(i) val1 += max(0LL, (a[i-1]+1)-a[i]);
            if(i < n - 1) val2 += max(0LL, (a[i+1]+1)-a[i]);
            ll ansdp = dp[i-2][k-1] + max(0LL, a[i-2]-a[i]);
            // dp2[i - 2][k - 1]?
            // if(k == 3 && i == 4){
            //     cout << seg[k-1].qry(i-2, i-2, 0, n-1, 1) << " " << val2 << "\n\n\n";
            //     cout << seg[k-1].qry(0, i-3, 0, n-1, 1) << " " << val1 << " " << val2 << "\n\n";
            // }
            ll ansfinal1 = ansdp + val2, ansfinal2 = 1e17;
            if(i > 2) {
                ansfinal2 = dp2[i-3][k-1] + val1 + val2;
            }
            dp[i][k] = min(ansfinal1, ansfinal2);
            dp2[i][k] = min({dp2[i-1][k], dp[i][k]});
        }
    }
    for(int k = 1; k<=(n+1)/2; ++k) {
        ll ans = 1e17;
        rep(i, n){
            ans = min(ans, dp[i][k]);
        }
        cout << ans << " ";
    }
 
 
}