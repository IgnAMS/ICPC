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

struct Node {   
    ll sum, prefix, suffix, mx;
    Node(): sum(0), prefix(0), suffix(0), mx(0) {}
    Node(ll x): sum(x), prefix(x), suffix(x), mx(x) {}
    Node(Node a, Node b) {
        sum = a.sum + b.sum;
        prefix = max(a.prefix, a.sum + b.prefix);
        suffix = max(b.suffix, a.suffix + b.sum);
        mx = max({a.mx, b.mx, a.suffix + b.prefix});
    }
};

const int mxN = 2e5+5;
struct ST {
    Node T[4 * mxN];
    void update(ll i, ll x, ll l = 0, ll r = mxN, ll u = 0) {
        // cerr<<i<<' '<<x<<' '<<l<<' '<<r<<'\n';
        if(l == r) T[u] = Node(x);
        else {
            ll m = (l + r) / 2;
            if(i <= m) update(i, x, l, m, 2 * u + 1);
            else update(i, x, m + 1, r, 2 * u + 2);
            T[u] = Node(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    Node query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(i > r or l > j) return Node();
        ll m = (l + r) / 2;
        return Node(query(i, j, l, m, 2 * u +1), query(i, j, m + 1, r, 2 * u + 2)); 
    }
} st;



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vl A(n); rep(i, n) cin>>A[i];
    rep(i, n) {
        st.update(i, A[i]);
    }
    // cout<<st.query(0, n - 1).mx<<'\n';
    rep(_, m) {
        ll ind, x; cin>>ind>>x;
        ind--;
        st.update(ind, x);
        cout<<st.query(0, n - 1).mx<<'\n';
    }


    return 0;
}