#pragma GCC optimize("Ofast")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef vector<ll> vl;
typedef vector<int> vi;
#define ff first
#define ss second
#define pb push_back
const int mxN = 2e5 + 10;
vector<int> G[mxN];
int removed[mxN], sz[mxN];

ll ans = 0, n, k1, k2;

struct Node {
    int v;
    Node() { v = 0; } // neutral element
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = a.v + b.v; }
};

// 0-indexed / inclusive - exclusive
struct ST2 {
    int n;
    Node t[2 * mxN];

    ST2(vector<Node> &arr, int N) : n(N) {
        copy(arr.begin(), arr.end(), t + n);
        for (int i = n - 1; i > 0; --i) t[i] = Node(t[i << 1], t[i << 1 | 1]);
    }

    void set(int p, const Node &value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = Node(t[p << 1], t[p << 1 | 1]);
    }

    Node query(int l, int r) {
        Node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) ansl = Node(ansl, t[l++]);
            if(r & 1) ansr = Node(t[--r], ansr);
        }
        return Node(ansl, ansr);
    }
};

int calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto v: G[u]) {
        if(v != p && !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}

int ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}

void dfs_sz(int u, int p, int d, vi& currdist, ST2& st2) {
    currdist.pb(d);
    
    // Handle out-of-bounds for query range
    ll l = max(0LL, k1 - d);
    ll r = min(n, k2 - d + 1);
    
    if(l < r) ans += st2.query(l, r).v;

    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            dfs_sz(v, u, d + 1, currdist, st2);
        }
    }
}

vi Centroid;
void build(int u) {
    int centroid = ctroid(u, calcsz(u));
    Centroid.pb(centroid);

    // Remove centroid and process its subtrees
    removed[centroid] = 1;
    for(auto v: G[centroid]) {
        if(!removed[v]) {
            build(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> k1 >> k2;

    rep(i, n - 1) {
        int u, v; cin >> u >> v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    // Initialize the segment tree
    vector<Node> aux(mxN, Node(0));
    ST2 st2(aux, mxN);

    // Set initial state for node 0
    Node uno(1);
    st2.set(0, uno);

    // Start centroid decomposition
    build(0);

    // Reset for distance accumulation and solve
    rep(i, n) removed[i] = 0;

    for(int centroid: Centroid) {
        vi CurrDist, AccDist;
        for(auto v: G[centroid]) {
            if(!removed[v]) {
                CurrDist.clear();
                dfs_sz(v, centroid, 1, CurrDist, st2);

                // Add new distances to segment tree
                for(auto d: CurrDist) {
                    AccDist.pb(d);
                    Node aux = st2.query(d, d + 1);
                    aux.v += 1;
                    st2.set(d, aux);
                }
            }
        }

        // Reset distances in segment tree
        for(auto d: AccDist) {
            Node aux = st2.query(d, d + 1);
            aux.v -= 1;
            st2.set(d, aux);
        }
        removed[centroid] = 1;
    }

    cout << ans << '\n';

  return 0;
}
