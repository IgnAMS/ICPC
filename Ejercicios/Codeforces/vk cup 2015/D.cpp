// #pragma GCC optimize("Oz")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int, int> pll;
typedef double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

const int mxN = 500010;
struct Node
{
    int v, l, r;
    Node() : v(1e6), l(0), r(0) {}
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    { v = min(a.v, b.v); }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct PST
{
    int cnt = 0, n, rc = 0;
    vector<node> st; vl rt;

    node query(int u, int a, int b, int i, int j)
    {
        if (j < a || b < i) return node();
        if (a <= i && j <= b) return st[u];
        int m = (i + j) / 2, l = st[u].l, r = st[u].r;
        return node(query(l, a, b, i, m), query(r, a, b, m + 1, j), l, r);
    }
    int update(int u, int p, node v, int i, int j)
    {
        if (j < p || p < i) return u;
        st[cnt] = st[u]; 
        int x = cnt++, m = (i + j) / 2;
        if(i == j) { st[x] = v; return x; }
        int l = st[x].l = update(st[x].l, p, v, i, m);
        int r = st[x].r = update(st[x].r, p, v, m + 1, j);
        st[x] = node(st[l], st[r], l, r); 
        return x;
    }
    int build(vector<node> &arr, int i, int j)
    {
        int u = cnt++, m = (i + j) / 2;
        if (i == j) { st[u] = arr[i]; return u; }
        int l = st[u].l = build(arr, i, m);
        int r = st[u].r = build(arr, m + 1, j);
        st[u] = node(st[l], st[r], l, r); return u;
    }

    PST(vector<node> &arr) : st(11000000), rt(mxN)
    { n = arr.size(); rt[rc++] = build(arr, 0, n - 1); }
    void update(int t, int p, node v) { rt[rc++] = update(rt[t], p, v, 0, n - 1); }
    node query(int t, int a, int b) { return query(rt[t], a, b, 0, n - 1); }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    int A[n]; rep(i, n) cin>>A[i];
    // vector<Node> V(n);
    pll Upd[n]; // {ubicacion, valor}
    rep(i, n) Upd[i] = {i, 1e6};
    map<ll, ll> mp;
    rep(i, n) {
        if(mp.count(A[i])) Upd[i] = { mp[A[i]], i - mp[A[i]] }; 
        mp[A[i]] = i;
    }
    vector<Node> V(n); rep(i, n) V[i].v = 1e6;
    PST<Node> Pst(V);
    rep(i, n) {
        Node node(Upd[i].ss);
        if(Upd[i].ss == 1e6) Pst.rt[i + 1] = Pst.rt[i], Pst.rc++;
        else Pst.update(i, Upd[i].ff, node);
    }
    rep(i, q) {
        int l, r; cin>>l>>r; l--, r--;
        Node val = Pst.query(r + 1, l, r);
        if(val.v == 1e6) cout<<"-1\n";
        else cout<<val.v<<'\n';
    }

    return 0;
}