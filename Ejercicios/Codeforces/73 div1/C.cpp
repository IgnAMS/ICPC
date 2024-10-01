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

const int mxN = 1e5+10;
struct ST {
    ll T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] ^ T[2 * u + 2];
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) ^ query(i, j, m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll acc = 1;
    vector<pll> X[n + 2];
    repx(l, 2, n + 1) if(acc <= n) {
        acc += l;
        ll s = 1;
        // cerr<<acc<<'\n';
        for(ll j = acc; j <= n; j += l) if(j <= n and s + l - 1 <= n) {
            X[j].pb({s, s + l - 1});
            s++;
        }
    }

    ll ans = 1e7;
    rep(i, n + 1) {
        // cout<<"Vecinos de "<<i<<'\n';
        set<ll> S;
        for(auto [a, b]: X[i]) {
            if(i == n) {
                // cout<<a<<' '<<b<<' '<<b - a + 1<<' '<<st.query(a, b)<<'\n';
                if(st.query(a, b) == 0) ans = min(ans, b - a + 1);
            }
            S.insert(st.query(a, b));
            // cout<<a<<' '<<b<<'\n';
        }
        ll mex = 0;
        for(auto u: S) {
            if(u == mex) mex++;
            else break;
        }
        // cout<<"el G de "<<i<<" es "<<mex<<'\n';
        st.update(i, mex);
    }
    if(st.query(n, n) == 0) cout<<"-1\n";
    else {
        cout<<ans<<'\n';
        // cout<<st.query(n, n)<<'\n';
    }

    return 0;
}