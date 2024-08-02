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
// g++ -O2 FixedLengthPathII.cpp && time ./a.out <input.txt> output.txt

const int mxN = 3e5 + 10;
vector<int> G[mxN];
int removed[mxN], sz[mxN];

ll ans = 0, n, k1, k2;
int Acc[mxN];

struct Node {
    int v;
    Node() { v = 0; } // neutro
    Node(int v) : v(v) {}
    Node(const Node &a, const Node &b) { v = a.v + b.v; }
};

// 0 - indexed / inclusive - exclusive
struct ST2 {
    vector<Node> t; int n;

    ST2(vector<Node> &arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for (int i = n - 1; i > 0; --i) t[i] = Node(t[i << 1], t[i << 1 | 1]);
    }
    void set(int p, const Node &value) {
        for (t[p += n] = value; p >>= 1;)
            t[p] = Node(t[p << 1], t[p << 1 | 1]);
    }
    Node query(int l, int r) {
        Node ansl, ansr;
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = Node(ansl, t[l++]);
            if (r & 1) ansr = Node(t[--r], ansr);
        }
        return Node(ansl, ansr);
    }
};


ll calcsz(int u, int p = -1) {
    sz[u] = 1;
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            sz[u] += calcsz(v, u);
        }
    }
    return sz[u];
}

ll ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}

void dfs_sz(int u, int p, int d, vl& currdist, ST2& st2) {
    currdist.pb(d);
    if(k2 - d >= 0) ans += st2.query(max(k1 - d, 0LL), k2 - d + 1).v;    
    for(auto v: G[u]) if(v != p and !removed[v]) dfs_sz(v, u, d + 1, currdist, st2);
}

vl Centroid;
void build(int u) {
    int centroid = ctroid(u, calcsz(u));
    Centroid.pb(centroid);

    // Obtengo las distancias y obtengo la respuesta
    Acc[0] = 1;

    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k1>>k2;
    
    // cout<<2e5 * log2(2e5) * log2(2e5)<<'\n';

    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }
    vector<Node> aux(mxN, 0);
    aux[0].v++;
    ST2 st2(aux, mxN);

    // st.upd(0, 1);
    
    build(0);

    rep(i, n) removed[i] = 0;

    for(ll centroid: Centroid) {
        // Itero y obtengo las distancias
        vl CurrDist, AccDist;
        for(auto v: G[centroid]) if(!removed[v]) {
            CurrDist.clear();
            dfs_sz(v, centroid, 1, CurrDist, st2);
            
            // Anado distancias nuevas
            for(auto d: CurrDist) {
                AccDist.pb(d);

                Node aux = st2.query(d, d + 1);
                aux.v += 1;
                st2.set(d, aux);
            }
        }
        // Reseteo las distancias
        for(auto d: AccDist) {
            Node aux = st2.query(d, d + 1);
            aux.v -= 1;
            st2.set(d, aux);
        }
        removed[centroid] = 1;
    }

    
    cout<<ans<<'\n';

    return 0;
}