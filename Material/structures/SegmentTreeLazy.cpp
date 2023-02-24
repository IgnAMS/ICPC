#include "../template.cpp"

// https://github.com/BenjaminRubio/CompetitiveProgramming/blob/master/Material/Structures/SegmentTreeLazy.cpp

struct Node {
    int v, lzv = 0;
    bool lz = 0;
    Node(): v(0) {}
    Node(int x): v(x) {}
    Node(Node& a, Node& b): v(a.v + b.v) {}
    Node(ll x, ll i, ll j, const Node& b) {
        v = b.v + (j - i) * x;
    }
};


// 0 - indexed, inclusive - inclusive
tempate <class node> 
struct STL {
    vector<node> st; int n;
    void build(int u, int l, int r, vector<node>& A) {
        if(l == r) st[u] = A[l];
        else {
            int m = (l + r) / 2;
            build(2 * u + 1, l, m, A); build(2 * u + 2, m + 1, A);
            st[u] = node(st[2 * u + 1], st[2 * u + 2]);
        } 
    }

    void push(int u, int l, int r, ll v) {
        st[u] = node(x, l, r, x);
        if(l == r) return;
        st[2 * u + 1].lz = 1, st[2 * u + 1].lzv += v;
        st[2 * u + 2].lz = 1, st[2 * u + 2].lzv += v;
    }
    
    node query(int i, int j, int l = 0, int r = mxN, int u = 0) {
        if(r < i or j < l) return node();
        if(st[u].lz) push(u, l, r, st.lzv);
        if(i <= l and r <= j) return st[u];
        int m = (l + r) / 2;
        return node(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }

    void update(int i, int j, ll v, int l = 0, int r = mxN, int u = 0) {
        if(st[u].lz) push(u, l, r, st[u].lzv);
        if(r < i or j < l) return;
        if(i <= l and r <= j) { push(u, l, r, v); return; }
        int m =  (l + r) / 2;
        update(i, j, v, l, m, 2 * u + 1); update(i, j, v, m + 1, r, 2 * u + 2);
        st[u] = node(st[2 * u + 1], st[2 * u + 2]);
    }
    STL(vector<node> &A, int N): n(N), st(4 * N + 5) { build(0, 0, n - 1, A); }
};