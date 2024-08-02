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
const int INF = 1e7;

struct Node {
    int u, d;
    Node(): u(INF), d(INF) {}
    Node(int u, int d): u(u), d(d) {}
    Node(const Node &a, const Node &b) { 
        if(a.d < b.d) u = a.u, d = a.d;
        if(a.d > b.d) u = b.u, d = b.d;
        if(a.d == b.d) u = min(a.u, b.u), d = a.d;
    }
    bool operator<(const Node& x) {
        return d < x.d or (d == x.d and u < x.u);
    }
};

// 0 - indexed / inclusive - exclusive
struct ST2 {
    vector<Node> t; int n;

    ST2(vector<Node> &arr, int N) : n(N), t(N * 2) {
        copy(arr.begin(), arr.end(), t.begin() + n);
        for(int i = n - 1; i > 0; --i) t[i] = Node(t[i << 1], t[i << 1 | 1]);
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

void dfs_sz(int u, int p, int d, vector<pll>& CurrDist) {
    CurrDist.pb({u, d});
    for(auto v: G[u]) if(!removed[v] and v != p) dfs_sz(v, u, d + 1, CurrDist);
}


ll ctroid(int u, int tree_sz, int p = -1) {
    for(auto v: G[u]) {
        if(v != p and !removed[v]) {
            if(sz[v] * 2 > tree_sz) return ctroid(v, tree_sz, u);
        }
    }
    return u;
}

vl Centroid;
void build(int u) {
    int centroid = ctroid(u, calcsz(u));
    Centroid.pb(centroid);

    removed[centroid] = 1;
    for(auto v: G[centroid]) if(!removed[v]) {
        build(v);
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;

    rep(i, n - 1) {
        int u, v; cin>>u>>v; u--, v--;
        G[u].pb(v), G[v].pb(u);
    }

    vector<Node> Ans(n);
    rep(i, n) Ans[i] = Node(i, INF);
    ST2 st2(Ans, n);
    
    rep(i, n) removed[i] = 0;
    build(0);

    rep(i, n) removed[i] = 0;

    for(ll centroid: Centroid) {
        // cerr<<"estoy en el centroide "<<centroid<<'\n';
        // Itero y obtengo las distancias
        vector<pll> CurrDist, AccDist;
        AccDist.pb({centroid, 0});
        Node aux(centroid, 0);
        st2.set(centroid, aux);

        for(auto v: G[centroid]) if(!removed[v]) {
            CurrDist.clear();
            dfs_sz(v, centroid, 1, CurrDist);
            
            // Anado distancias nuevas
            for(auto [u, d]: CurrDist) {
                AccDist.pb({u, d});
                Node aux(u, d);
                st2.set(u, aux);
            }
        }
        
        // Calculo la respuesta del nodo actual
        Node curr = st2.query(centroid + 1, n);
        if(curr < Ans[centroid]) Ans[centroid] = curr;

        for(auto v: G[centroid]) if(!removed[v]) {
            CurrDist.clear();
            dfs_sz(v, centroid, 1, CurrDist);
            // Desmarco las distancias
            for(auto [u, d]: CurrDist) {
                Node aux(u, INF);
                st2.set(u, aux);
            }
            // calculo las respuestas
            for(auto [u, d]: CurrDist) {
                Node curr = st2.query(u + 1, n);
                curr.d += d;
                if(curr < Ans[u]) Ans[u] = curr;
            }


            // Vuelvo a marcar las distancias
            for(auto [u, d]: CurrDist) {
                Node aux(u, d);
                st2.set(u, aux);
            }
        }

        // Reseteo las distancias a infinito
        for(auto [u, d]: AccDist) {
            Node aux = Node(u, INF);
            st2.set(u, aux);
        }
        removed[centroid] = 1;
    }

    rep(i, n) cout<<Ans[i].u + 1<<' '; cout<<'\n';

    return 0;
}