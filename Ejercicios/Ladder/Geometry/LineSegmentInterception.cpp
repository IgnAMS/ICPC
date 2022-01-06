#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
typedef long long ll;
#define repx(i, a, b) for(int i=a; i<b; i++)
#define db double

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

db ang(db a)
{
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool isConvex(vector<P> p)
{
    int n = p.size();
    bool hasPos = false, hasNeg = false, hasCol = false;
    rep(i, n)
    {
        int o = turn(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
        if (o == 0) hasCol = true;
    }
    return !(hasPos && hasNeg) && !hasCol;
}

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

void polarSort(vector<P> &v)
{
    sort(v.begin(), v.end(), [](P &p1, P &p2)
    {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}

// LINE

struct L
{
    P v; T c;
    L() {} L(P v, T c) : v(v), c(c) {}
    L(T a, T b, T c) : v(P(b, -a)), c(c) {}
    L(P p, P q) : v(q - p), c(v ^ p) {}

    T side(P p) { return (v ^ p) - c; }
    db dist(P p) { return abs(side(p) / v.norm()); }
    db dist2(P p) { return side(p) * side(p) / (db)v.norm2(); }
    L perp(P p) { return L(p, p + v.perp()); }
    L translate(P t) { return L(v, c + (v ^ t)); }
    P proj(P p) { return p - v.perp() * side(p) / v.norm2(); }
    P refl(P p) { return p - v.perp() * 2 * side(p) / v.norm2(); }
};

bool parallel(L l1, L l2) {return abs(l1.v ^ l2.v) < EPS; }

// only if not parallel
P inter(L l1, L l2) { return (l2.v * l1.c - l1.v * l2.c) / (l1.v ^ l2.v); }

L bisector(L l1, L l2, bool in)
{
    db sign = in ? 1 : -1;
    return L(l2.v / l2.v.norm() + l1.v / l1.v.norm() * sign,
             l2.c / l2.v.norm() + l1.c / l1.v.norm() * sign);
}

struct HASH // Hashing for integer coordinates lines
{
    ll a, b, c;
    HASH(const P &p1, const P &p2)
    {
        a = p1.y - p2.y, b = p2.x - p1.x;
        c = p1.x * (p2.y - p1.y) - p1.y * (p2.x - p1.x);
        ll sgn = (a < 0 or (a == 0 and b < 0)) ? -1 : 1;
        ll g = __gcd(abs(a), __gcd(abs(b), abs(c))) * sgn;
        a /= g, b /= g, c /= g;
    }
    bool operator<(const HASH &h) const
    {
        return a < h.a or (a == h.a and (b < h.b or (b == h.b and c < h.c)));
    }
};

// SEGMENT

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool properInter(P &a, P &b, P &c, P &d, P &out)
{
    T ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    out = (a * tb - b * ta) / (tb - ta);
    return (ta * tb < 0 && tc * td < 0);
}

set<P> inter(P &a, P &b, P &c, P &d)
{
    P out;
    if (properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if (onSegment(c, d, a)) ans.insert(a);
    if (onSegment(c, d, b)) ans.insert(b);
    if (onSegment(a, b, c)) ans.insert(c);
    if (onSegment(a, b, d)) ans.insert(d);
    return ans;
}


int main(){
    int t; cin>>t;
    while(t--){
        P p1, p2, p3, p4; 
        cin>>p1>>p2>>p3>>p4;
        set<P> inters = inter(p1, p2, p3, p4);
        if(inters.size() == 0){
            cout<<"none\n";
        }
        else{
            for(P p : inters){
                double x = abs(p.x) < EPS? 0.0: p.x;
                double y = abs(p.y) < EPS? 0.0: p.y;
                cout<<setprecision(2)<<fixed<<x<<" "<<y<<" ";
            }
            cout<<'\n';
        }


    }



    return 0;
}