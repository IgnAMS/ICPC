#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;



ll solve(ll x) {
    ll ans = 0;
    while(x) {
        ans = max(ans, x % 10);
        x /= 10;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll la, ra, lb, rb; cin>>la>>ra>>lb>>rb;
        ll ans = 0;
        if(ra - la >= 10 or rb - lb >= 10) ans = 9;
        else {
            // caso contrario ra - la + rb - lb < 0 -> itero sobre todos los digitos xd
            for(ll a = la; a <= ra; a++) {
                for(ll b = lb; b <= rb; b++) {
                    ans = max(ans, solve(a + b));
                }
            }
        }
        cout<<ans<<'\n';
    }
    


    return 0;
}

