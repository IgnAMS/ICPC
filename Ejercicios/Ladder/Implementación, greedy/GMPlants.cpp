#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(ll i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

struct Node {
    ll v, lzv = 0;
    bool lz = false;
    Node() : v(0) {}
    Node(ll x) : v(x) {}
    Node(const Node &a, const Node &b) : v(a.v + b.v) {}
    Node(ll x, ll i, ll j, const Node &b) { // revertir el rango
        v = (j - i + 1) - b.v;
    }
};

// 0 - indexed / inclusive - inclusive
template <class node>
struct STL
{
    vector<node> st; ll n;

    void push(ll u, ll i, ll j, ll x)
    {
        st[u] = node(x, i, j, st[u]);
        if (i == j) return;
        if(st[2 * u + 1].lz) st[2 * u + 1].lz = 0;
        else st[2 * u + 1].lz = 1;
        
        if(st[2 * u + 2].lz) st[2 * u + 2].lz = 0;  
        else st[2 * u + 2].lz = 1;
    }
    node query(ll a, ll b, ll u, ll i, ll j)
    {
        if (j < a || b < i) return node();
        ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (a <= i && j <= b) return st[u];
        return node(query(a, b, l, i, m), query(a, b, r, m + 1, j));
    }
    void update(ll a, ll b, ll v, ll u, ll i, ll j)
    {
        if (st[u].lz) push(u, i, j, st[u].lzv);
        if (j < a || b < i) return;
        ll m = (i + j) / 2, l = u * 2 + 1, r = u * 2 + 2;
        if (a <= i && j <= b) { push(u, i, j, v); return; }
        update(a, b, v, l, i, m); update(a, b, v, r, m + 1, j);
        st[u] = node(st[l], st[r]);
    }

    STL(ll N) : n(N), st(N * 4 + 5, Node()) {}
    node query(ll a, ll b) { return query(a, b, 0, 0, n - 1); }
    void update(ll a, ll b, ll v) { update(a, b, v, 0, 0, n - 1); }
};



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        ll nx, ny, nz, q; cin>>nx>>ny>>nz>>q;
        STL<Node> stx(nx), sty(ny), stz(nz);
        while(q--) {
            ll com; cin>>com;
            if(com == 0) {
                ll l, r; cin>>l>>r;
                stx.update(l, r, 0);
            }
            if(com == 1) {
                ll l, r; cin>>l>>r;
                sty.update(l, r, 0);
            }
            if(com == 2) {
                ll l, r; cin>>l>>r;
                stz.update(l, r, 0);
            }
            if(com == 3) {  
                ll x1, y1, z1, x2, y2, z2; cin>>x1>>y1>>z1>>x2>>y2>>z2;
                ll X1 = stx.query(x1, x2).v, Y1 = sty.query(y1, y2).v, Z1 = stz.query(z1, z2).v;
                ll X0 = (x2 - x1 + 1) - X1, Y0 = (y2 - y1 + 1) - Y1, Z0 = (z2 - z1 + 1) - Z1;
                // cout<<X1 * Y1 * Z1<<' '<<X1 * Y0 * Z0<<' '<<X0 * Y1 * Z0<<' '<<X0 * Y0 * Z1<<'\n';
                cout<<X1 * Y1 * Z1 + X1 * Y0 * Z0 + X0 * Y1 * Z0 + X0 * Y0 * Z1<<'\n';
            }
        }

    }





    return 0;
}