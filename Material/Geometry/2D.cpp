#include "template.cpp"


const db PI = acos(-1.0L);
const db EPS = 1e-12;

// POINT 2D

typedef db T; struct P {
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
P polar(db r, db a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

db ang(db a) {
    while (a >= 2. * PI) a -= 2. * PI;
    while (a < 0) a += 2. * PI;
    return a;
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool left(P& a, P& b, P& p) { return (b - a) ^ (p - a) > 0; }


bool isConvex(vector<P> p) {
    int n = sz(p);
    bool hasPos = false, hasNeg = false, hasCol = false;
    rep(i, n) {
        int o = turn(p[i], p[(i + 1) % n], p[(i + 2) % n]);
        if (o > 0) hasPos = true;
        if (o < 0) hasNeg = true;
        if (o == 0) hasCol = true;
    }
    return !(hasPos && hasNeg) && !hasCol;
}

bool half(P &p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

void polarSort(vector<P> &v) {
    sort(v.begin(), v.end(), [](P &p1, P &p2) {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}

// LINE
struct L {
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

L bisector(L l1, L l2, bool in) {
    db sign = in ? 1 : -1;
    return L(l2.v / l2.v.norm() + l1.v / l1.v.norm() * sign,
             l2.c / l2.v.norm() + l1.c / l1.v.norm() * sign);
}

// Hashing for integer coordinates lines
struct HASH  {
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

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

T sign(T ta) { ta == 0? 0: (ta > 0? 1: -1); }  
bool properInter(P &a, P &b, P &c, P &d, P &out) {
    T ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    if(tb - ta == 0) return 0;
    out = (a * tb - b * ta) / (tb - ta);
    return (sign(ta) * sign(tb) < 0 && sign(tc) * sign(td) < 0);
}

set<P> inter(P &a, P &b, P &c, P &d) {
    P out;
    if (properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if (onSegment(c, d, a)) ans.insert(a);
    if (onSegment(c, d, b)) ans.insert(b);
    if (onSegment(a, b, c)) ans.insert(c);
    if (onSegment(a, b, d)) ans.insert(d);
    return ans;
}

db segPoint(P &a, P &b, P &p) {
    if ((p - a) * (b - a) >= 0 && (p - b) * (a - b) >= 0)
        return abs(((b - a) ^ (p - a)) / (b - a).norm());
    return min((p - a).norm(), (p - b).norm());
}


db segSeg(P &a, P &b, P &c, P &d) {
    P aux;
    if (properInter(a, b, c, d, aux)) return 0;
    return min({segPoint(a, b, c), segPoint(a, b, d),
                segPoint(c, d, a), segPoint(c, d, b)});
}

// POLYGONS
// pick theorem: A = i + b/2 - 1 -> 2 A = 2 i + b - 2 -> (2 * A - b + 2) / 2 = i
// border = sum gcd(abs(P[i].x - P[i + 1].x), abs(P[i].y - P[i + 1].y))

db areaTriangle(P &a, P &b, P &c) {
    return abs((b - a) ^ (c - a)) / 2.;
}

db areaPolygon(vector<P> &p) {
    db ans = 0; int n = sz(p);
    rep(i, n) ans += p[i] ^ p[(i + 1) % n];
    return abs(ans) / 2.;
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

// if strict, returns false when a is on the boundary
bool inPolygon(vector<P> &p, P &a, bool strict = true) {
    int c = 0, n = sz(p);
    rep(i, n) {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

// Slow O((NE)^2log(NE))
db areaPolygonUnion(vector<vector<P>> &pol)  {
    db area = 0;
    rep(i, sz(pol)) rep(j, sz(pol[i])) {
        int m = sz(pol[i]);
        P p1 = pol[i][j], p2 = pol[i][(j + 1) % m];

        vector<pair<db, int>> s; s.emplace_back(1., 0);

        rep(ii, sz(pol)) if (ii != i) rep(jj, sz(pol[ii])) {
            int mm = sz(pol[ii]);
            P p3 = pol[ii][jj], p4 = pol[ii][(jj + 1) % mm];

            db t1 = turn(p1, p2, p3), t2 = turn(p1, p2, p4),
                   t3 = turn(p3, p4, p1), t4 = turn(p3, p4, p2);
            if(!t1 && !t2 && (p2 - p1) * (p4 - p3) > 0 && i > ii) {
                s.emplace_back((p3 - p1) * (p2 - p1).unit(), 1);
                s.emplace_back((p4 - p1) * (p2 - p1).unit(), -1);
            }
            if(t1 >= 0 && t2 < 0) s.emplace_back(t3 / (t3 - t4), 1);
            if(t1 < 0 && t2 >= 0) s.emplace_back(t3 / (t3 - t4), -1);
        }

        sort(s.begin(), s.end());

        int c = 0;
        db last = 0, f = 0;
        for (auto e : s) {
            db now = min(1., max(0., e.ff));
            if (c == 0) f += now - last;
            c += e.ss, last = now;
        }

        area += (p1 ^ p2) * f;
    }
    
    return area;
}

vector<P> convexHull(vector<P> &p) {
    int n = sz(p), k = 0;
    vector<P> H(2 * n); sort(p.begin(), p.end());
    rep(i, n) {
        while(k >= 2 && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}

// Check if point is inside a convex polygon
void normalize(vector<P>& p) { // Normalize respect to the leftmost point
    int n = p.size();
    // anti clockwise
    if(turn(p[0], p[1], p[2]) > 0) reverse(p.begin(), p.end());
    vector<P> p2;
    // take out collinear points
    rep(i, n) {
        if(p2.empty()) p2.pb(p[i]);
        else if(((p2.back() - p[i]) * (p[(i+1)%n] - p[i])) < 0 and turn(p2.back(), p[i], p[(i+1)%n]) == 0) {
            continue;
        }
        else p2.pb(p[i]);
    }
    swap(p2, p);

    int pi = min_element(p.begin(), p.end()) - p.begin();
    rotate(p.begin(), p.begin() + pi, p.end());
    vector<P> s(n);
    rep(i, n) s[i] = p[(pi + i) % n];
    p.swap(s);
}

bool inConvexPol(vector<P>& p, P& q, bool strict=false) { // first get rid of the collinear points
    if(turn(p[0], p[1], q) > 0 or turn(p.back(), p[0], q) > 0) return 0;
    int l = 1, r = p.size() - 2;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        if(turn(p[0], p[m], q) <= 0) l = m;
        else r = m - 1;
    }
    if(strict) {
        if(inDisk(q, p[l], p[l + 1]) and turn(p[l], q, p[l + 1]) == 0) return 0;
        if(l == 1 and inDisk(q, p[0], p[l]) and turn(p[0], q, p[l]) == 0) return 0;
        if(l == p.size() - 2 and inDisk(q, p[l + 1], p[0]) and turn(p[0], q, p[l + 1]) == 0) return 0;
    }
    return turn(p[l], p[l + 1], q) <= 0;
}



// MISCELLANEOUS

// Smallest Enclosing cicle
P bary(P &A, P &B, P &C, db a, db b, db c) {
    return (A * a + B * b + C * c) / (a + b + c);
}

P circum(P &A, P &B, P &C) {
    db a = (B - C).norm2(), b = (C - A).norm2(), c = (A - B).norm2();
    return bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}

pair<P, db> smallestEnclosingCircle(vector<P> &p) {
    random_shuffle(all(p));
    P c = p[0]; db r = 0; int N = sz(p);
    rep(i, N) if (i && (p[i] - c).norm() > r + EPS) {
        c = p[i]; r = 0;
        rep(j, i) if ((p[j] - c).norm() > r + EPS) {
            c = (p[i] + p[j]) * 0.5;
            r = (p[i] - c).norm();
            rep(k, j) if ((p[k] - c).norm() > r + EPS) {
                c = circum(p[i], p[j], p[k]);
                r = (p[k] - c).norm();
            }
        }
    }

    return {c, r};
}


// Closest pair of points from array "a" (mindist: squared mindist)
const int MAXN = 1000010;

int n; T mindist;
pair<P, P> best;
P a[MAXN], t[MAXN];

T sq(T x) { return x * x; }

bool cmpY(P & a, P & b) { return a.y < b.y; }

void update(P &p1, P &p2) {
    T aux = (p1 - p2).norm2();
    if(aux < mindist) { mindist = aux; best = {p1, p2}; }
}

// sort "a" before usage (P must have default operator<)
void closest(int l, int r) {
    if(r - l <= 3) {
        repx(i, l, r) repx(j, i + 1, r) update(a[i], a[j]);
        sort(a + l, a + r, cmpY);
        return;
    }

    int m = (l + r) >> 1, xm = a[m].x;
    closest(l, m); closest(m, r);

    merge(a + l, a + m, a + m, a + r, t, cmpY);
    copy(t, t + r - l, a + l);

    int tsz = 0;
    repx(i, l, r)  if(sq(a[i].x - xm) < mindist) {
        for(int j = tsz - 1; j >= 0 && sq(a[i].y - t[j].y) < mindist; --j)
            update(a[i], a[j]);
        t[tsz++] = a[i];
    }
}

// Alternative closes pair of points in complexity O(n log(n))
ll dist(P& a, P& b) {
    return (a - b) * (a - b);
}
 
vector<P> Px;
 
bool lessx(P& a, P& b) {
    return a.x < b.x or (a.x == b.x and a.y <= b.y);
}
bool lessy(P& a, P& b) {
    return a.y < b.y or (a.y == b.y and a.x <= b.x);
}
 
ll bruteforce(vector<P>& Py) {
    ll ans = 8e18 + 10;
    rep(i, Py.size()) repx(j, i + 1, Py.size()) ans = min(ans, dist(Py[i], Py[j]));
    return ans;
}
 
void preprocess_DivAndConq() {
    vector<P> Py;
    rep(i, n) {
        Px.pb(Pol[i]);
        Py.pb(Pol[i]);
    }
    sort(Px.begin(), Px.end(), [&](const P a, const P b) {
        return a.x < b.x or (a.x == b.x and a.y < b.y);
    });
    sort(Py.begin(), Py.end(), [&](const P a, const P b) {
        return a.y < b.y or (a.y == b.y and a.x < b.x);
    });
    DivAndConq(Py, 0, n - 1);
}

ll DivAndConq(vector<P>& Py, int l, int r) {
    if(r - l  + 1 <= 100) {
        return bruteforce(Py);
    }
 
    int m = (l + r) / 2;
    vector<P> PL, PR;
    rep(i, Py.size()) {
        if(lessx(Py[i], Px[m])) PL.pb(Py[i]);
        else PR.pb(Py[i]);
    }
 
    ll dl = DivAndConq(PL, l, m);
    ll dr = DivAndConq(PR, m + 1, r);
    ll d = min(dl, dr);
 
    vector<P> S;
    rep(i, Py.size()) if((Py[i].x - Px[m].x) * (Py[i].x - Px[m].x) < d) S.pb(Py[i]);
    rep(i, S.size()) {
        repx(j, i + 1, S.size()) {
            if((S[i].y - S[j].y) * (S[i].y - S[j].y) > d) break;
            d = min(d, dist(S[i], S[j]));
        }
    }
    return d;
}
 