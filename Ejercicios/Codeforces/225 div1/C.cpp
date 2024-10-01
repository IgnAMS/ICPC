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
    Node(const Node &a, const Node &b) { v = a.v + b.v; }
};

// 0 - indexed / inclusive - exclusive
template <class node>
struct ST {
    vector<node> t; int n;

    ST(int N) : n(N), t(N * 2, node(0)) {
        // copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = node(t[i << 1], t[i << 1 | 1]);
    }
    void update(int p, const node &value) {
        t[p + n].v += value.v;
        for (p += n; p >>= 1;)
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

template <class ST, class node>
class HLD {
    ST st;
    vl A, H, D, R, P;
    int dfs(vector<vl> &G, int u) {
        int ans = 1, M = 0, s;
        for(auto v : G[u]) if (v != A[u]) {
            A[v] = u, D[v] = D[u] + 1;
            s = dfs(G, v), ans += s;
            if (s > M) H[u] = v, M = s;
        }
        return ans;
    }

public:
    HLD(vector<vl> &G, int n) : A(n), st(n), D(n), R(n), P(n) {
        H.assign(n, -1); A[0] = -1, D[0] = 0; dfs(G, 0); int p = 0;
        rep(i, n) if (A[i] == -1 || H[A[i]] != i)
            for (int j = i; j != -1; j = H[j]) R[j] = i, P[j] = p++;
    }
    void update(int v, const node &x) { 
        int par = (D[v] & 1);
        if(par) st.update(P[v], x);
        else {
            node y = x;
            y.v *= -1;
            st.update(P[v], y); // impar asignar con negativo 
        }
    }
    ll query(int u) {
        int par = (D[u] & 1);
        ll ans = 0;
        for(; R[u] != 0; u = A[R[u]]) ans += st.query(P[R[u]], P[u] + 1).v;
        ans += st.query(P[0], P[u] + 1).v;
        if(par) return ans;
        return -ans;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<Node> A(n);
    rep(i, n) cin>>A[i].v;
    vector<vl> G(n, vl());
    rep(i, n - 1) {
        int u, v; cin>>u>>v, u--, v--;
        G[u].pb(v); G[v].pb(u);
    }
    HLD<ST<Node>, Node> hld(G, n);
    // rep(i, n) hld.update(i, A[i]);
    while(m--) {
        int com; cin>>com;
        if(com == 1) {
            ll u, val; cin>>u>>val; u--;
            hld.update(u, val);
        }
        else {
            ll u; cin>>u; u--;
            cout<<hld.query(u) + A[u].v<<'\n';
        }
    }


    return 0;
}