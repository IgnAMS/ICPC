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

int n, h, q; 

struct Node {
    int P[20];
    Node() { rep(i, 20) P[i] = i; }
    void update(int i, int j) { swap(P[i], P[j]); }
    Node(Node a, Node b) {
        rep(i, 20) P[i] = b.P[a.P[i]];
    }
};

const int mxN = 2e5 + 5;
struct ST {
    Node T[4 * mxN];
    void update(ll h, ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(l == r) T[u].update(i, j);
        else {
            int m = (l + r) / 2;
            if(h <= m) update(h, i, j, l, m, 2 * u + 1);
            else update(h, i, j, m + 1, r, 2 * u + 2);
            T[u] = Node(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    Node query(ll i, ll j, ll l = 0, ll r = mxN, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return Node();
        int m = (l + r) / 2;
        return Node(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }
} st;

struct DSU {
    vl p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y)
    {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>h>>q;
    while(q--) {
        int y, x1, x2; cin>>y>>x1>>x2; y--, x1--, x2--;
        st.update(y, x1, x2);
        Node X = st.query(0, h);
        // rep(i, n) cout<<X.P[i]<<' '; cout<<'\n';
        DSU dsu(n);
        rep(i, n) dsu.unite(i, X.P[i]);
        set<ll> S;
        rep(i, n) S.insert(dsu.get(i));
        cout<<n - S.size()<<'\n';
    }

    return 0;
}