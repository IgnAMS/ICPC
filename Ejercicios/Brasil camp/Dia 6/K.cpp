#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct Node
{
    ll l, r;
    vi v;
    Node() : v(0), l(0), r(0) {}
    Node(int v_) { v = {v_}; }
    Node(const Node &a, const Node &b, int l, int r) : l(l), r(r)
    { 
        while(a[i].begin() < )
    }
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
    ll query(int l, int r, int x)
    {
        ll ans = 0;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1)
        {
            if (l & 1) ans += t[l++].v.lower_bound(x);
            if (r & 1) ans = t[--r].v.lower_bound(x);
        }
        return ans;
    }
};

template <class ST, class node>
class HLD
{
    ST st;
    vi A, H, D, R, P;

    int dfs(vector<vi> &G, int u)
    {
        int ans = 1, M = 0, s;
        for (int v : G[u]) if (v != A[u])
        {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }
    template <class OP>
    void path(int u, int v, OP op)
    {
        for (; R[u] != R[v]; v = A[R[v]])
        {
            if (D[R[u]] > D[R[v]]) swap(u, v);
            op(P[R[v]], P[v] + 1);
        }
        if (D[u] > D[v]) swap(u, v);
        op(P[u], P[v] + 1);
    }

public:
    HLD(vector<vi> &G, vector<node> X, int n) : A(n), st(X), D(n), R(n), P(n) {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    node query(int u, int v, int x)
    {
        node ans = node();
        path(u, v, [this, &ans](int l, int r) { 
            ans = node(ans, st.query(l, r, x)); 
        });
        return ans;
    }
};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vi A(n);
    rep(i, n) cin>>A[i];
    vector<vi> G(n, vi());
    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].push_back(u); 
        G[v].push_back(v);
    }
    HLD<PST, Node> hld;


    rep(_, m) {
        int u, v, k; cin>>u>>v>>k; u--, v--, k--;
        int l = 1, r = 1e9;
        while(l < r) {
            int m = (l + r + 1) / 2;
            if(hld.query(u, v, m) >= k) l = m;
            else r = m - 1;
        }
    }




    return 0;
}