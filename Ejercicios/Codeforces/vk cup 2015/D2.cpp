// #pragma GCC optimize("O")
// #pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

const int mxN = 5e5+5;

struct Vertex {
    Vertex *l, *r;
    int mn;
    Vertex(): l(0), r(0), mn(1e6) {} 
    Vertex(int val) : l(0), r(0), mn(val) {}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), mn(1e6) {
        if (l) mn = min(mn, l->mn);
        if (r) mn = min(mn, r->mn);
    }
};

Vertex* build(vl& A, int tl, int tr) {
    if(tl == tr) return new Vertex(A[tl]);
    int tm = (tl + tr) / 2;
    return new Vertex(build(A, tl, tm), build(A, tm + 1, tr));
}

ll query(Vertex* v, int i, int j, int tl = 0, int tr = mxN) {
    // cerr<<"segmento de query: "<<i<<' '<<j<<'\n';
    // cerr<<"segmento explorando: "<<tl<<' '<<tr<<'\n';
    if(tr < i or j < tl) return 1e6;
    if(i <= tl and tr <= j) return v->mn;
    int tm = (tl + tr) / 2;
    return min(query(v->l, i, j, tl, tm), query(v->r, i, j, tm + 1, tr));
}

Vertex* update(Vertex* v, int pos, int val, int tl = 0, int tr = mxN) {
    if(tl == tr) return new Vertex(val);
    int tm = (tl + tr) / 2;
    if(pos <= tm) return new Vertex(update(v->l, pos, val, tl, tm), v->r);
    else return new Vertex(v->l, update(v->r, pos, val, tm + 1, tr));
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin>>n>>q;
    int A[n]; rep(i, n) cin>>A[i];
    vl V(n); rep(i, n) V[i] = 1e6;
    pll Upd[n]; // {ubicacion, valor}
    rep(i, n) Upd[i] = {-1, -1};
    map<ll, ll> mp;
    rep(i, n) {
        if(mp.count(A[i])) Upd[i] = { mp[A[i]], i - mp[A[i]] }; 
        mp[A[i]] = i;
    }

    
    vector<Vertex*> Roots; 
    Roots.push_back(build(V, 0, n - 1));
    rep(i, n) {
        if(Upd[i].ff != -1) Roots.push_back(update(Roots[i], Upd[i].ff, Upd[i].ss, 0, n - 1));
        else Roots.push_back(Roots[i]);
    }
    // cerr<<"Termine de hacer los nuevos nodos\n";
    rep(i, q) {
        int l, r; cin>>l>>r; l--, r--;
        // cerr<<l<<' '<<r<<'\n';
        ll val = query(Roots[r + 1], l, r, 0, n - 1);
        if(val == 1e6) cout<<"-1\n";
        else cout<<val<<'\n';
    }

    return 0;
}