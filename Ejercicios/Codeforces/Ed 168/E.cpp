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

const int mxN = 2e5+10;
struct ST {
    ll T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] += x;
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
} st;


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    ll A[n]; 
    rep(i, n) cin>>A[i];
    rep(i, 2e5) st.update(i, 0);
    ll Ans[n];
    rep(i, n) {
        ll l = 0, r = 2e5 + 2;
        // maximo k tal que no vive
        while(l < r) {
            ll m = (l + r + 1) / 2;
            if(m and 1 + st.query(0, m) / m <= A[i]) r = m - 1;
            else l = m;
        }
        st.update(l + 1, 1);
        Ans[i] = l + 1;
    }

    while(q--) {
        int i, x; cin>>i>>x; i--;
        if(x < Ans[i]) cout<<"NO\n";
        else cout<<"YES\n";
    }


    return 0;
}