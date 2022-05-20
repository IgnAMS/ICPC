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
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
//  g++ -O2 D.cpp && time ./a.out < input.txt > output.txt


const db PI = acos(-1.0L);
const db EPS = 1e-12;

// POINT 2D

typedef db T; struct P
{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const
    {
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator<(const P &p) const
    {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    db ang()
    {
        db a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(db a){ return rot(P(sin(a), cos(a))); }
};
P polar(db r, db a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p)
{
    return s << '(' << p.x << ", " << p.y << ')';
}

struct Circ {
    P center; db r;
    Circ(P center, db r): center(center), r(r) {}
};

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }



P perp(db ang) { return P(-sin(ang), cos(ang)); }

bool inCirc(Circ &C, P &p) { return (p - C.center).norm2() <= C.r + EPS; }

db bsr(db ang, P &p, db l, db r) {
    rep(i, 100) {
        db m = (l + r) * 0.5;
        Circ C(perp(ang) * m, m);
        if(inCirc(C, p)) l = m;
        else r = m;
    }
    return (l + r) * 0.5;
}


pair<P, P> Tangent(Circ &C, P &p) {

}


db f(db ang, db v, db w, P &p) {
    db t0 = ang / w, t1, t2;
    Circ C(perp(ang) * v / w, v / w);
    if(inCirc(C, p)) {
        db r = bsr(ang, p, 0, v / w);
        db ang1 = (p - perp(ang) * r).ang();
        db ang2 = (P(0, 0) - perp(ang) * r).ang();
        t1 = min(ang1 - ang2, 2 * PI - (ang1 - ang2)) / w;
        t2 = 0;
    }
    else {

    }
}



db ts(P &p, db v, db w) {
    rep(i, 300) {
        
    }
}



int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    P p; cin>>p;
    db v, w; cin>>v>>w;
    cout<<(ts(p, v, w))<<'\n';





    return 0;
}