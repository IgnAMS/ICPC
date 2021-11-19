#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;
typedef vector<ll> vi;
#define ff first
#define ss second
typedef pair<char, ii> mp;
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt

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

db segPoint(P &a, P &b, P &p)
{
    if ((p - a) * (b - a) >= 0 && (p - b) * (a - b) >= 0)
        return abs(((b - a) ^ (p - a)) / (b - a).norm());
    return min((p - a).norm(), (b - a).norm());
}

db segSeg(P &a, P &b, P &c, P &d)
{
    P aux;
    if (properInter(a, b, c, d, aux)) return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

// POLYGONS

db areaTriangle(P &a, P &b, P &c)
{
    return abs((b - a) ^ (c - a)) / 2.;
}

db areaPolygon(vector<P> &p)
{
    db ans = 0; int n = p.size();
    rep(i, n) ans += p[i] ^ p[(i + 1) % n];
    return abs(ans) / 2.;
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q)
{
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

// if strict, returns false when a is on the boundary
bool inPolygon(vector<P> &p, P &a, bool strict = true)
{
    int c = 0, n = p.size();
    rep(i, n)
    {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

bool outside(ii dif, ii p0, int n, int m){
    if(dif.ff + p0.ff >= n or dif.ss + p0.ss >= m) return 1;
    if(dif.ff + p0.ff < 0 or dif.ss + p0.ss < 0) return 1;
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    map<char, ii> change = {
        mp('H', ii(-1, -1)), mp('A', ii(-1, 0)), mp('B', ii(-1, 1)),
        mp('G', ii(0, -1)), mp('C', ii(0, 1)),
        mp('F', ii(1, -1)), mp('E', ii(1, 0)), mp('D', ii(1, 1)) 
    };
    while(cin>>n>>m>>k and n){
        vector<vector<char>> mat(n, vector<char>(m, '.'));
        rep(_, k){
            char fill; ii p0; int ni; cin>>fill>>p0.ff>>p0.ss>>ni; p0.ff--, p0.ss--;
            vector<P> Polygon;
            ii dif = ii(0, 0);
            bool pos = 1; // posible
            vector<ii> path ={ii(p0.ff, p0.ss)};
            rep(i, ni){
                if(outside(dif, p0, n, m)) {
                    pos = 0;
                    cout<<"REGION "<<fill<<" GOES OUTSIDE THE ARRAY\n";
                    break;
                }
                if(mat[dif.ff + p0.ff][dif.ss + p0.ss] != '.'){
                    pos = 0;
                    cout<<"REGION "<<fill<<" BOUNDARY INTERSECTS REGION "<<mat[dif.ff + p0.ff][dif.ss + p0.ss]<<'\n';
                    break;
                }
                path.push_back(ii(dif.ff + p0.ff, dif.ss + p0.ss));
                Polygon.push_back(P(p0.ff + dif.ff, p0.ss + dif.ss));
                char com; cin>>com; cerr<<com;
                dif = ii(dif.ff + change[com].ff, dif.ss + change[com].ss);
            }
            cerr<<"\n\n";
            if(!pos) continue;
            if(dif.ff != 0 or dif.ss != 0){
                cout<<"REGION "<<fill<<" BOUNDARY IS NOT CLOSED\n";
                continue;
            }
            // rep(i, Polygon.size()) cout<<Polygon[i]<<' '; cout<<'\n';
            for(auto& u: path) {
                mat[u.ff][u.ss] = fill;
            }
            rep(i, n) rep(j, m){
                P aux = P(i, j);
                if(inPolygon(Polygon, aux)) mat[i][j] = fill;
            }
        }
        
        rep(i, n) { rep(j, m) cout<<mat[i][j]; cout<<'\n'; }
        cout<<'\n';
    }

    return 0;
}