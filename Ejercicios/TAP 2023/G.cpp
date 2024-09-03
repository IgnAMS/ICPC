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

const ll mxN = 4e5 + 10;
const ll N = (1<<20);
const ll INF = 1e11;
struct Node {
    ll h, id; 
    Node(): h(-INF), id(-INF) {}
    Node(ll h, ll id): h(h), id(id) {}
    Node(const Node &a, const Node &b) {
        // me quedo con el que tiene mayor altura
        if(a.h < b.h) h = b.h, id = b.id;
        else h = a.h, id = a.id;
    }
};

struct ST {
    Node T[2 * N];
    Node L[N];
    // vector<Node> T = vector<Node>(4 * mxN);
    // vector<Node> L = vector<Node>(4 * mxN);

    void apply(ll p, const Node &value) {
        T[p].h = value.h;
        T[p].id = value.id;
        if (p < N) L[p] = value;
    }

    void push(ll p) {
        for (ll s = 20; s > 0; --s) { 
            ll i = p >> s;
            if (L[i].h != -INF) {
                apply(2 * i, L[i]);
                apply(2 * i + 1, L[i]);
                L[i] = Node();  
            }
        }
    }

    void pull(ll p) {
        while (p > 1) {
            p >>= 1;
            if (L[p].h != -INF) {
                apply(2 * p, L[p]);
                apply(2 * p + 1, L[p]);
                L[p] = Node();  
            }
            T[p] = Node(T[2 * p], T[2 * p + 1]);
        }
    }

    void update(ll l, ll r, const Node &x) {
        l += N;
        r += N + 1;
        ll l0 = l, r0 = r - 1;
        while (l < r) {
            if (l & 1) apply(l++, x);
            if (r & 1) apply(--r, x);
            l >>= 1;
            r >>= 1;
        }
        pull(l0);
        pull(r0);
    }

    // Query range [l, r]
    Node query(ll l, ll r) {
        l += N;
        r += N + 1;
        push(l);
        push(r - 1);
        Node resL, resR;
        while (l < r) {
            if (l & 1) resL = Node(resL, T[l++]);
            if (r & 1) resR = Node(T[--r], resR);
            l >>= 1;
            r >>= 1;
        }
        return Node(resL, resR);
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



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    ll L[n], R[n];
    cerr<<(1<<18)<<'\n';
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
    unordered_map<ll, ll> index;    
    index.reserve(Pos.size());
    for(auto& u: Pos) index[u] = index.size();
    
    vector<array<ll, 3>> Edges; // [cost, u, v]
    // Inicializo con el nodo 0 hacia abajo 
    Node zero = Node(0, 0);
    st.update(0, index.size(), zero);
    for(auto& [h, vec]: H) {
        for(auto& [a, b, id]: vec) {
            Node x = st.query(index[a - h], index[b - h]);
            Edges.pb({h - x.h, x.id, id});
            x = st.query(index[a - h], index[a - h]);
            Edges.pb({h - x.h, x.id, id});
            x = st.query(index[b - h], index[b - h]);
            Edges.pb({h - x.h, x.id, id});
        }
        for(auto& [a, b, id]: vec) {
            Node x = Node(h, id);
            st.update(index[a - h], index[b - h], x);
        }
    }

    // Reseteo el segment tree
    // st.reset();
    st.update(0, index.size(), zero);
    for(auto& [h, vec]: H) {
        for(auto& [a, b, id]: vec) {
            Node x = st.query(index[a + h], index[b + h]);
            Edges.pb({h - x.h, x.id, id});
            x = st.query(index[a + h], index[a + h]);
            Edges.pb({h - x.h, x.id, id});
            x = st.query(index[b + h], index[b + h]);
            Edges.pb({h - x.h, x.id, id});
        }
        for(auto& [a, b, id]: vec) {
            Node x = Node(h, id);
            st.update(index[a + h], index[b + h], x);
        }
    }

    // Ahora debo conectar de arriba hacia abajo
    // st.reset();
    // soft update
    Node reset_node = Node(-INF + 1, -INF + 1);
    st.update(0, index.size(), reset_node);
    for(auto it = H.rbegin(); it != H.rend(); it++) {
        auto& [h, vec] = *it;
        for(auto& [a, b, id]: vec) {
            // Debo revisar que lo conecto con un posible segmento y no con el techo
            Node x = st.query(index[a - h], index[b - h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
            x = st.query(index[a - h], index[a - h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
            x = st.query(index[b - h], index[b - h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
        }
        for(auto& [a, b, id]: vec) {
            Node x = Node(-h, id);
            st.update(index[a - h], index[b - h], x);
        }
    }


    // soft update
    st.update(0, index.size(), reset_node);
    for(auto it = H.rbegin(); it != H.rend(); it++) {
        auto& [h, vec] = *it;
        for(auto& [a, b, id]: vec) {
            Node x = st.query(index[a + h], index[b + h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
            x = st.query(index[a + h], index[a + h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
            x = st.query(index[b + h], index[b + h]);
            if(x.h != -INF + 1) Edges.pb({-h - x.h, x.id, id});
        }
        for(auto& [a, b, id]: vec) {
            Node x = Node(-h, id);
            st.update(index[a + h], index[b + h], x);
        }
    }

    sort(Edges.begin(), Edges.end());
    DSU dsu(n + 1);
    ll ans = 0;
    for(auto& [cost, u, v]: Edges) {
        // cerr<<cost<<" "<<u<<' '<<v<<' '<<n + 1<<'\n';
        if(!dsu.same(u, v)) {
            ans += cost;
            dsu.unite(u, v);
        }
    }
    cout<<ans<<'\n';

    return 0;
}