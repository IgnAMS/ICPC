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
    void add(ll l, ll r, ll v) {
        update(l, v);
        update(r, -v);
    }
    void update(ll ind, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] += x;
        else {
            ll m = (l + r) / 2;
            if(ind <= m) update(ind, x, l, m, 2 * u + 1);
            else update(ind, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2];
            // cout<<"actualizo el segmento "<<l<<' '<<r<<" con "<<T[u]<<'\n';
        }
    }

    ll query(ll ind) {
        return query(0, ind) - query(0, ind - 1);
    }

    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or l > j) return 0;
        ll m = (l + r) / 2;
        // cout<<"el segmento "<<l<<' '<<r<<" da "<<T[u]<<'\n';
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(_, m) {
        ll op; cin>>op;
        if(op == 1) {
            ll l, r, v; cin>>l>>r>>v;
            st.add(l, r - 1, v);
        }
        else {
            ll ind; cin>>ind;
            cout<<st.query(ind)<<'\n';
        }
    }


    return 0;
}