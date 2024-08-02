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
//     void add(ll l, ll r, ll v) {
//         update(l, v);
//         update(r, -v);
//     }
//     void update(ll ind, ll x, ll l = 0, ll r = mxN, ll u = 0) {
//         if(l == r) T[u] += x;
//         else {
//             ll m = (l + r) / 2;
//             if(ind <= m) update(ind, x, l, m, 2 * u + 1);
//             else update(ind, x, m + 1, r, 2 * u + 2);
//             T[u] = T[2 * u + 1] + T[2 * u + 2];
//             // cout<<"actualizo el segmento "<<l<<' '<<r<<" con "<<T[u]<<'\n';
//         }
//     }

    void add2(ll i, ll j, ll v, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) {
            T[u] += v;
            return;
        }
        if(r < i or l > j) return;
        ll m = (l + r) / 2;
        add2(i, j, v, l, m, 2 * u + 1);
        add2(i, j, v, m + 1, r, 2 * u + 2);
    }
    ll query_st(ll ind, ll l = 0, ll r = mxN, ll u = 0) {
        // cout<<"pregunto por el segmento "<<l<<", "<<r<<" al hacer la query en "<<ind<<'\n';
        if(l == r) return T[u];
        ll m = (l + r) / 2;
        if(ind <= m) return T[u] + query_st(ind, l, m, 2 * u + 1);
        return T[u] + query_st(ind, m + 1, r, 2 * u + 2);
    }
} st;


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    rep(_, m) {
        ll op; cin>>op;
        if(op == 1) {
            ll l, r, v; cin>>l>>r>>v;
            st.add2(l, r - 1, v);
        }
        else {
            ll ind; cin>>ind;
            cout<<st.query_st(ind)<<'\n';
        }
    }





    return 0;
}