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
const db EPS = 1e-9;

typedef db T; 
struct P{
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const {
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator<(const P &p) const {
        return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS;
    }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    db ang() {
        db a = atan2(y, x);
        if (a < 0) a += 2. * PI;
        return a;
    }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(db a){ return rot(P(sin(a), cos(a))); }
};
P polar(db r, db a) { 
    if(a < 0) a += 2 * PI;
    if(a >= 2 * PI) a -= 2 * PI;
    return P(r * cos(a), r * sin(a));
}
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

bool inCirc(Circ &C, P &p) { return (p - C.center).norm() < C.r; }


pair<P, P> Tangent(Circ &C, P &p) {
    db a = (p - C.center).ang();
    db da = acos(C.r / (p - C.center).norm());
    P p1 = polar(C.r, a - da) + C.center;
    P p2 = polar(C.r, a + da) + C.center;
    return {p1, p2};
}


db mindist(P& p, db v, db w) {
    int iter = 1e6;
    db delta = db(1) / db(iter);
    db ans = 1e10;
    rep(i, iter) {
        db ang = 2. * PI * (i + delta) / db(iter);
        Circ C(perp(ang) * v / w, v / w);
        if(inCirc(C, p)) continue;

        // obtengo los dos puntos tangentes de C respecto a p
        // reviso cual esta en el sentido contra reloj respecto a p
        P tang1, tang2; tie(tang1, tang2) = Tangent(C, p);
        P realtang;
        if(turn(tang1, C.center, p) < EPS) realtang = tang1;
        else realtang = tang2;
        P zero(0, 0);
        db a0 = (zero - C.center).ang(), atang = (realtang - C.center).ang();
        db ang2;
        if(a0 > atang) ang2 = 2 * PI - (a0 - atang);
        else ang2 = atang - a0;
        if(abs(a0 - atang) < EPS) ang2 = 0;
        db curr = ang / w + ang2 / w + (realtang - p).norm() / v;
        ans = min(ans, curr);
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    P p; cin>>p;
    db v, w; cin>>v>>w;
    db ans1 = mindist(p, v, w);
    p.y *= -1;
    db ans2 = mindist(p, v, w);
    cout<<setprecision(8)<<fixed<<min(ans1, ans2)<<'\n';

    return 0;
}