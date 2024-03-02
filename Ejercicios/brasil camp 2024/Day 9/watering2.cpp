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
    vl p; DSU(int N) : p(N, -1) {}
    int get(int x) { return p[x] < 0 ? x : p[x] = get(p[x]); } 
    bool sameSet(int a, int b) { return get(a) == get(b); }
    int size(int x) { return -p[get(x)]; }
    void unite(int x, int y) {
        if ((x = get(x)) == (y = get(y))) return;
        if (p[x] > p[y]) swap(x,y);
        p[x] += p[y], p[y] = x;
    }
};



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vl> Edges;
    rep(i, n) {
        ll w; cin>>w;
        Edges.pb({w, 0, i + 1});
    }
    rep(i, n) rep(j, n) {
        ll w; cin>>w;
        Edges.pb({w, i + 1, j + 1});
    }
    sort(Edges.begin(), Edges.end());
    
    ll total = 0;
    DSU dsu(n + 1);
    for(auto vec: Edges) {
        ll w = vec[0], u = vec[1], v = vec[2];
        if(dsu.sameSet(u, v)) continue;
        total += w;
        dsu.unite(u, v);
    }
    cout<<total<<'\n';

    return 0;
}