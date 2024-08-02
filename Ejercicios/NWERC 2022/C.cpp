#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double db;
#define repx(i, a, b) for(int i = (int)a; i < (int)b; i++)
#define rep(i, n) repx(i, 0, n)
#define ff first
#define ss second
typedef pair<ll, ll> pll;
typedef vector<ll> vl;


const double PI = acos(-1.0L);

const int mxN = 4e5+5, M = 1e9+7;

int main(){
    cout << fixed << setprecision(10);
    ll s;
    cin >> s;
    db l = 1, r = 2e5;
    rep(_, 400) {
        ll cnt = 0;
        db mid = (l + r) * 0.5;
        for(ll x = 1; x <= mid; ++x) {
            cnt += ll(sqrt(mid * mid - x * x));
        }
        if(cnt * 4 >= s) r = mid;
        else l = mid;
    }

    // ll cnt = 0;
    // db mid = 2e5;
    // for(ll x = 1; x <= mid; ++x) {
    //     cnt += ll(sqrt(mid * mid - x*x + 1e-12));
    // }
    
    // cout<<sqrt(1 * 1 + 1 * 1)<<'\n';
    // cout<<sqrt(1 * 1 + 2 * 2)<<'\n';
    // cout<<sqrt(2 * 2 + 2 * 2)<<'\n';
    // cout<<sqrt(1 * 1 + 3 * 3)<<'\n';
    // cout<<sqrt(2 * 2 + 3 * 3)<<'\n';
    // cout<<sqrt(3 * 3 + 3 * 3)<<'\n';
    // cout<<sqrt(1 * 1 + 4 * 4)<<'\n';
    // cout<<sqrt(2 * 2 + 6 * 6)<<'\n';

    cout << (l+r)*0.5 << "\n";
}

