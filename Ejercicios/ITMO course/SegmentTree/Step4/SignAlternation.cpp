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
    void update(ll ind, ll v, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] = v;
        else {
            ll m = (l + r) / 2;
            if(ind <= m) update(ind, v, l, m, 2 * u + 1);
            else update(ind, v, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
        }
    }
    
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or l > j) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }

} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl A(n); 
    rep(i, n) {
        cin>>A[i];  
        if(i % 2 == 0) st.update(i, -A[i]);
        else st.update(i, A[i]);
    }
    int m; cin>>m;
    rep(_, m) {
        ll op, l, r; cin>>op>>l>>r;
        if(op == 0) {
            l--;
            if(l % 2 == 0) st.update(l, -r);
            else st.update(l, r);
        }
        else {
            l--, r--;
            cout<<(l % 2 == 0? -1LL: 1LL) * st.query(l, r)<<'\n';
        }
    }


    return 0;
}