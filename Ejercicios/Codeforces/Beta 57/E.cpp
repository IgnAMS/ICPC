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


const int mxN = 1e6+5;
struct ST {
    vl T;
    ST() {
        T.assign(4 * mxN + 4, 0);
    }
    ll query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(l > j or r < i) return 0;
        ll m = (l + r) / 2;
        return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
    }
    void update(ll ind, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u] += x;
        else {
            ll m = (l + r) / 2;
            if(ind <= m) update(ind, x, l, m, 2 * u + 1);
            else update(ind, x, m + 1, r, 2 * u + 2);
            T[u] = T[2 * u + 1] + T[2 * u + 2]; 
        }
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    // st.query(A[i] + 1, n) = # j < k  A[j] > A[k]
    int n; cin>>n;
    ll A[n]; 
    set<ll> CompressSet;

    rep(i, n) {
        cin>>A[i];
        CompressSet.insert(A[i]);
    }
    vl Compress;
    for(auto u: CompressSet) Compress.pb(u);
    rep(i, n) {
        A[i] = lower_bound(Compress.begin(), Compress.end(), A[i]) - Compress.begin();
    }


    ll ans = 0;
    ST st1, st2;
    rep(i, n) {
        ll val2 = st1.query(A[i] + 1, n);
        ll val3 = st2.query(A[i] + 1, n);
        ans += val3;
        st1.update(A[i], 1);
        st2.update(A[i], val2);
    }   
    cout<<ans<<'\n';



    return 0;
}