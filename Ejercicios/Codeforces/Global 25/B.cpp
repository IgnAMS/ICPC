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
    ll v;
    Node() { v = 0; } // neutro
    Node(ll v) : v(v) {}
    Node(const Node &a, const Node &b) { v = max(a.v, b.v); }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST {
    vector<node> t; int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r) {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        int n, k; cin>>n>>k; k--;
        vl A(n); rep(i, n) cin>>A[i];

        vector<Node> N;
        rep(i, n) N.pb(Node(A[i]));

        ST<Node> st(N, n);
        ll ans = 0;
        rep(i, n) {
            ll l = i, r = n;
            st.set(i, N[k]);
            st.set(k, N[i]);
            while(l < r) {
                int m = (l + r) / 2;
                if(st.query(0, m + 1).v > A[k]) r = m;
                else l = m + 1;
            }
            st.set(i, N[i]);
            st.set(k, N[k]);

            if(i != 0 and l > i) ans = max(ans, l - i);
            else ans = max(ans, l - i - 1);
        }
        cout<<ans<<'\n';
    }


    return 0;
}