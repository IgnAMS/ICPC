#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)

void solve(){
    int n; 
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    ll ans = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<n; ++j){
            ans = max(ans, a.back()*(a.back()-a[i]-a[j]) + a[i]*a[i] + a[j]*a[j] - a[i]*a[j]);
        }
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    solve();

    return 0;
}

