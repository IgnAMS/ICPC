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
// g++ -O2 xd.cpp && time ./a.out <input.txt> output.txt

const ll mxN = 4e5 + 10;
const ll INF = 1e11;
struct Node {
    ll h, id; 
    Node(): h(-INF), id(-INF) {}
    Node(ll h, ll id): h(h), id(id) {}
    Node(Node a, Node b) {
        // me quedo con el que tiene mayor altura
        if(a.h < b.h) h = b.h, id = b.id;
        else h = a.h, id = a.id;
    }
};

struct ST {
    vector<Node> T = vector<Node>(4 * mxN);
    vector<Node> L = vector<Node>(4 * mxN);

    void put(ll l, ll r, ll u, Node &x) {
        T[u] = x;
        if(l != r) {
            L[2 * u + 1] = x; 
            L[2 * u + 2] = x;
        }
        L[u] = Node();
    }

    void reset() { rep(u, 4 * mxN) T[u] = L[u] = Node(); }

    void update(ll i, ll j, Node& x, ll l = 0, ll r = mxN, ll u = 0) {
        if(L[u].h != -INF) {
            put(l, r, u, L[u]);
        }
        if(i <= l and r <= j) {
            put(l, r, u, x);
            return;
        }
        if(r < i or j < l) return;
        ll m = (l + r) / 2;
        update(i, j, x, l, m, 2 * u + 1);
        update(i, j, x, m + 1, r, 2 * u + 2);
        T[u] = Node(T[2 * u + 1], T[2 * u + 2]);
    }

    Node query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(L[u].h != -INF) {
            put(l, r, u, L[u]);
        }
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return Node();
        ll m = (l + r) / 2;
        return Node(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;


struct DSU {
    vl p; DSU(int n): p(n, -1) {}
    ll get(ll x) { return (p[x] < 0? x: p[x] = get(p[x])); }
    ll same(ll u, ll v) { return get(u) == get(v); }
    void unite(ll u, ll v) {
        if((u = get(u)) == (v = get(v))) return;
        if(p[u] > p[v]) swap(u, v);
        p[u] += p[v];
        p[v] = u; 
    }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll L[n], R[n];
    map<ll, vector<array<ll, 3>>> H;
    set<ll> Pos;
    rep(i, n) {
        ll h;
        cin>>h>>L[i]>>R[i];
        H[h].pb({L[i], R[i], i + 1});
        Pos.insert(L[i] - h);
        Pos.insert(L[i] + h);
        Pos.insert(R[i] - h);
        Pos.insert(R[i] + h);
    }

    // indices del segment tree
    map<ll, ll> index;
    for(auto u: Pos) index[u] = index.size();
    
    vector<array<ll, 3>> Edges; // [cost, u, v]
    // Inicializo con el nodo 0 hacia abajo 
    Node zero = Node(0, 0);
    st.update(0, index.size(), zero);
    for(auto& [h, vec]: H) {
        for(auto [a, b, id]: vec) {
            Node x = st.query(index[a - h], index[b - h]);
            Edges.pb({h - x.h, x.id, id});
        }
        for(auto [a, b, id]: vec) {
            Node x = Node(h, id);
            st.update(index[a - h], index[b - h], x);
        }
    }

    // Reseteo el segment tree
    st.reset();
    st.update(0, index.size(), zero);
    for(auto& [h, vec]: H) {
        for(auto [a, b, id]: vec) {
            Node x = st.query(index[a + h], index[b + h]);
            Edges.pb({h - x.h, x.id, id});
        }
        for(auto [a, b, id]: vec) {
            Node x = Node(h, id);
            st.update(index[a + h], index[b + h], x);
        }
    }

    // Ahora debo conectar de arriba hacia abajo
    st.reset();
    for(auto it = H.rbegin(); it != H.rend(); it++) {
        auto [h, vec] = *it;
        for(auto [a, b, id]: vec) {
            // Debo revisar que lo conecto con un posible segmento y no con el techo
            Node x = st.query(index[a - h], index[b - h]);
            if(x.h != -INF) Edges.pb({-h - x.h, x.id, id});
        }
        for(auto [a, b, id]: vec) {
            Node x = Node(-h, id);
            st.update(index[a - h], index[b - h], x);
        }
    }


    st.reset();
    for(auto it = H.rbegin(); it != H.rend(); it++) {
        auto [h, vec] = *it;
        for(auto [a, b, id]: vec) {
            Node x = st.query(index[a + h], index[b + h]);
            if(x.h != -INF) Edges.pb({-h - x.h, x.id, id});
        }
        for(auto [a, b, id]: vec) {
            Node x = Node(-h, id);
            st.update(index[a + h], index[b + h], x);
        }
    }

    sort(Edges.begin(), Edges.end());
    DSU dsu(n + 1);
    ll ans = 0;
    for(auto [cost, u, v]: Edges) {
        // cerr<<cost<<" "<<u<<' '<<v<<' '<<n + 1<<'\n';
        if(!dsu.same(u, v)) {
            ans += cost;
            dsu.unite(u, v);
        }
    }
    cout<<ans<<'\n';

    return 0;
}