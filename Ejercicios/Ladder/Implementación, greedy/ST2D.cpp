#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second

struct Node {
    ll x, y, v;
    Node() { x = -1, y = -1, v = -1; }
    Node(ll x, ll y, ll v): x(x), y(y), v(v) {}
    Node(Node a, Node b) {
        // cerr<<"debo mezclar "<<a.x<<' '<<a.y<<' '<<a.v<<" con "<<b.x<<' '<<b.y<<' '<<b.v<<'\n'; 
        if(a.v > b.v) x = a.x, y = a.y, v = a.v;
        else x = b.x, y = b.y, v = b.v;
    }
};

vector<vector<Node>> T(2010, vector<Node>(2010));

void update(ll x, ii& pos, ll ir = 0, ll jr = r - 1, ll ic = 0, ll jc = c - 1, ll u = 1, ll v = 1) {
    // cerr<<"hago update en el rango ["<<ir<<", "<<jr<<"] x ["<<ic<<", "<<jc<<"]\n";
    ll mr = (ir + jr) / 2;
    ll mc = (ic + jc) / 2;
    if(ir == jr){
        if(ic == jc) {
            T[u][v].x = pos.ff, T[u][v].y = pos.ss;
            T[u][v].v = x;
        }
        else {
            if(pos.ss <= mc) update(x, pos, ir, jr, ic, mc, u, 2 * v);
            else update(x, pos, ir, jr, mc + 1, jc, u, 2 * v + 1);
            T[u][v] = Node(T[u][2 * v], T[u][2 * v + 1]);
        }
    }
    else {
        if(pos.ff <= mr) update(x, pos, ir, mr, ic, jc, 2 * u, v);
        else update(x, pos, mr + 1, jr, ic, jc, 2 * u + 1, v);
        rep(i, c) T[u][i] = Node(T[2 * u][i], T[2 * u + 1][i]);
        // T[u][v] = Node(T[2 * u][v], T[2 * u + 1][v]);
    }
}

Node query(ii &x0, ii &x1, ll ir = 0, ll jr = r - 1, ll ic = 0, ll jc = c - 1, ll u = 1, ll v = 1) {
    // cerr<<"query en el rango: ["<<ir<<", "<<jr<<"] x ["<<ic<<", "<<jc<<"]\n";
    ll mr = (ir + jr) / 2;
    ll mc = (ic + jc) / 2;
    if(x0.ff <= ir and jr <= x1.ff){
        if(x0.ss <= ic and jc <= x1.ss) return T[u][v];
        if(x0.ss > jc or x1.ss < ic) return Node();
        Node L = query(x0, x1, ir, jr, ic, mc,     u, 2 * v);
        Node R = query(x0, x1, ir, jr, mc + 1, jc, u, 2 * v + 1);
        return Node(L, R);
    }
    else {
        if(x1.ff < ir or x0.ff > jr) return Node();
        Node L = query(x0, x1, ir, mr,     ic, jc, 2 * u, v);
        Node R = query(x0, x1, mr + 1, jr, ic, jc, 2 * u + 1, v);
        return Node(L, R);
    }
}