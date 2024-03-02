#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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
struct P {
    ll x, y; 
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll c) const { return P(x * c, y * c); }
    P operator/(const ll c) const { return P(x / c, y / c); }
};

ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

ll sign(ll x) { 
    if(x == 0) return 0;
    if(x > 0) return 1;
    return -1;
}

bool properInter(P& a, P& b, P& c, P& d) {
    ll ta = turn(a, c, d), tb = turn(b, c, d), 
        tc = turn(c, a, b), td = turn(d, a, b);
    if(sign(ta) * sign(tb) < 0 and sign(tc) * sign(td) < 0) return true;

    return false;
}

bool pointInter(P& a, P& b, P& c) {
    return turn(a, b, c) == 0 and ((a - c) * (b - c)) <= 0;  
}

bool inter(P& a, P& b, P& c, P& d) {
    if(properInter(a, b, c, d)) return true; 
    if(pointInter(a, b, c)) return true;
    if(pointInter(a, b, d)) return true;
    if(pointInter(c, d, a)) return true;
    if(pointInter(c, d, b)) return true;
    return false;
}

bool above(P &a, P& p) { return p.y >= a.y; }

bool crossesRay(P& a, P& p, P& q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

string inPolygon(vector<P>& Poly, P& p) {
    int c = 0, n = Poly.size();
    rep(i, n) {
        if(pointInter(Poly[i], Poly[(i + 1) % n], p)) return "BOUNDARY";
        c += crossesRay(p, Poly[i], Poly[(i + 1) % n]);
    }
    if(c & 1) return "INSIDE";
    return "OUTSIDE";
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<P> Pol(n);
    rep(i, n) cin>>Pol[i].x>>Pol[i].y;
    while(m--) {
        P p; cin>>p.x>>p.y;
        cout<<inPolygon(Pol, p)<<'\n';
    }
    
    return 0;
}