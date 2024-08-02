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


struct DSU {
    vl p; 
    DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};


struct Edge {
    ll u, v, w;
    bool operator<(const Edge& e) { return w < e.w; }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vl Q(n); rep(i, n) cin>>Q[i];

    int m; cin>>m;
    vector<Edge> E;
    rep(i, m) {
        ll u, v, w; cin>>u>>v>>w; u--, v--;
        E.pb({u, v, w});
    }
    
    sort(E.begin(), E.end());
    
    DSU dsu(n);
    ll ans = 0;
    vl V(n, 0);
    for(auto& e: E) {
        // cerr<<"proceso "<<e.u<<' '<<e.v<<' '<<e.w<<'\n';
        if(V[e.v]) continue;
        V[e.v] = 1;
        dsu.unite(e.u, e.v);
        ans += e.w;
    }

    if(dsu.size(0) < n) cout<<"-1\n";
    else cout<<ans<<'\n';

    return 0;
}