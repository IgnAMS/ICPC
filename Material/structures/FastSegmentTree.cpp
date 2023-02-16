#include "../template.cpp"

const int mxN = 5e5+5;
ll T[4 * mnX];

// 0 - indexed, inclusive - inclusive
void update(int i, ll v, int l = 0, int r = mxN, int u = 0) {
    if(l == r) T[u] = v;
    else {
        int m = (l + r) / 2;
        if(i <= m) update(i, v, l, m, 2 * u + 1);
        else update(i, v, m + 1, r, 2 * u + 2);
        T[u] = T[2 * u + 1] + T[2 * u + 2];
    }
}

int query(int i, int j, int l = 0, int r = mxN, int u = 0) {
    if(i <= l and r <= j) return T[u];
    if(r < i or j < l) return 0;
    int m = (l + r) / 2;
    return query(i, j, l, m, 2 * u + 1) + query(i, j, m + 1, r, 2 * u + 2);
}