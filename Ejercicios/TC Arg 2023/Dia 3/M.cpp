#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)
#define ll long long

int main(){
    vector<ll> a(3);
    rep(i, 3) cin >> a[i];
    ll ans = 0;
    sort(a.begin(), a.end());
    ans += a[1] - a[0];
    ans += a[2] - a[1];
    cout << ans << '\n';
}