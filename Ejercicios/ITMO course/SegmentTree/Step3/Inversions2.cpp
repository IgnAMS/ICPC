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

const int mxN = 1e5 + 5;
struct ST {
    ll T[4 * mxN];
    void update(ll ind, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = x;
        else {
            ll m = (l + r) / 2;
            if(ind <= m) update(ind, x, l, m, 2 * u + 1);
            else update(ind, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(i > r or l > j) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
    ll search(ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) return l;
        ll m = (l + r) / 2;
        if(T[2 * u + 1] >= x) return search(x, l, m, 2 * u + 1);
        else return search(x - T[2 * u + 1], m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n);
    rep(i, n) cin>>A[i];
    repx(i, 1, n + 1) st.update(i, 1);
    vl Ans(n);
    for(int i = n - 1; i >= 0; i--) {
        ll val = st.search(i + 1 - A[i]);
        Ans[i] = val;
        // cout<<i + 1 - A[i]<<' '<<val<<'\n';
        st.update(val, 0);
    }
    rep(i, n) cout<<Ans[i]<<' ';
    cout<<'\n';



    return 0;
}