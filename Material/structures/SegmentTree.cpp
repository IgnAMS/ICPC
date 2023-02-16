#include "../template.cpp"


const int mxN = 5e5+5;

struct Node{
    ll v; 
    Node(): v(0) {}
    Node(ll v): v(v) {}
    Node(Node& a, Node& b) { v = a.v + b.v; }
};


// 0 - indexed, inclusive - inclusive
template <class node> 
struct ST {
    vector<node> t; int n;
    ST(vector<node>& A, int N): n(N), t(4 * n + 4) {
        build(0, n - 1, 0, A);
    }

    void build(int l, int r, int u = 0, vector<node>& A) {
        if(l == r) t[u] = A[l];
        else {
            int m = (l + r) / 2;
            build(l, m, 2 * u + 1, A);
            build(m + 1, r, 2 * u + 2, A);
            t[u] = node(t[2 * u + 1], t[2 * u + 2]);
        }
    }

    void update(int i, node &v, int l = 0, int r = n - 1, int u = 0) {
        int m = (l + r) / 2;
        if(i <= m) update(i, v, l, m, 2 * u + 1);
        else update(i, v, m + 1, r, 2 * u + 2);
        t[u] = node(t[2 * u + 1], t[2 * u + 2]);
    }

    node query(int i, int j, int l = 0, int r = n - 1, int u = 0) {
        if(i <= l and r <= j) return t[u];
        if(i > r or j < l) return node();
        int m = (l + r) / 2;
        return node(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
};