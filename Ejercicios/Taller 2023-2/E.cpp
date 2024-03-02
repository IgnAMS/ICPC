#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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

struct Node
{
    ll v;
    Node() { v = 0; } // neutro
    Node(ll v) : v(v) {}
    Node(const Node &a, const Node &b) { v = max(a.v, b.v); }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST
{
    vector<node> t; int n;

    ST(vector<node> &arr, int N) : n(N), t(N * 2)
    {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const node &value)
    {
        for (t[p += n] = value; p >>= 1;)
            t[p] = node(t[p << 1], t[p << 1 | 1]);
    }
    node query(int l, int r)
    {
        node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ansl = node(ansl, t[l++]);
            if (r & 1) ansr = node(t[--r], ansr);
        }
        return node(ansl, ansr);
    }
};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vl A(n); rep(i, n) cin>>A[i];
    vl B(m); rep(i, m) cin>>B[i];

    vector<Node> A2(n + 1, Node());
    rep(i, n) A2[i].v = A[i];
    ST<Node> st(A2, n + 1);
    
    
    rep(i, m) {
        ll l = 1, r = n + 1;
        while(l < r) {
            ll m = (l + r) / 2;
            if(st.query(0, m).v >= B[i]) r = m;
            else l = m + 1;
        }
        if(l == n + 1) {
            cout<<"0 "; 
            continue;
        }
        cout<<l<<' '; 
        Node x = Node(st.query(0, l).v - B[i]);
        st.set(l - 1, x);
    }
    cout<<'\n';
    
    return 0;
}