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

const int mxN = 2e5 + 5;
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
} st, st2;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(2 * n); rep(i, 2 * n) cin>>A[i]; 
    
    ll Ans[n + 1];
    map<ll, ll> left;
    repx(i, 1, n + 1) Ans[i] = 0;
    
    rep(i, 2 * n) {
        ll x = A[i];
        if(left.count(x)) {
            st.update(left[x], 1);
            Ans[x] += st2.query(left[x], i) - st.query(left[x], i);
        }
        else {
            left[x] = i;
            st2.update(i, 1);
        }
    }

    rep(i, 2 * n) st.update(i, 0), st2.update(i, 0);
    left.clear();
    reverse(A.begin(), A.end());
    rep(i, 2 * n) {
        ll x = A[i];
        if(left.count(x)) {
            st.update(left[x], 1);
            Ans[x] += st2.query(left[x], i) - st.query(left[x], i);
        }
        else {
            left[x] = i;
            st2.update(i, 1);
        }
    }
    repx(i, 1, n + 1) cout<<Ans[i]<<' '; cout<<'\n';

    return 0;
}