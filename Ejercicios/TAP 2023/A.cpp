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

const ll mxN = 1e5+5;
struct ST {
    ll T[4 * mxN + 5];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = min(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 1e10;
        ll m = (l + r) / 2;
        return min(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    ll A[n], E[m];
    rep(i, n) cin>>A[i];
    rep(i, m) {
        cin>>E[i];
        st.update(i, E[i]);
    }
    vl X = {ll(1e9+1)};
    rep(i, m) {
        if(X.back() > E[i]) X.pb(E[i]);
    }
    // for(auto u: X) cout<<u<<' '; cout<<'\n';

    rep(i, n) {
        ll x = A[i];
        ll ind = 0;
        while(ind < X.size()) {
            // cout<<"Estoy en ind: "<<ind<<'\n';
            ll l = ind, r = X.size();
            while(l < r) {
                ll m = (l + r) / 2;
                if(x >= X[m]) r = m;
                else l = m + 1;
            }
            if(l < X.size()) x = x % X[l];
            ind = l + 1;
        }
        cout<<x<<' ';
    }
    cout<<'\n';

    return 0;
}