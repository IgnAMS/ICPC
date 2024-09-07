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

const db PI = acos(-1.0L);
const db EPS = 1e-12;

typedef ll T; struct P {
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T left(P a, P b) { return (b - a) ^ (*this - a); }
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

T turn(P a, P b, P c) { return (b - a) ^ (c - a); }
bool inDisk(P& a, P& b, P& c) { return ((b - a) * (c - a)) >= 0; }

// + if inside, 0 in border, - outside
T inConvexPol(vector<P>& p, P& q) { 
    // first get rid of the collinear points
    int l = 1, r = p.size() - 2; assert(p.size() >= 3);
    while(l < r) { // collinear points are unsupported!
        int m = (l + r + 1) / 2;
        if(turn(p[0], p[m], q) >= 0) l = m;
        else r = m - 1;
    }
    T in = min(turn(p[0], p[1], q), turn(p.back(), p[0], q));
    return min(in, turn(p[l], p[l + 1], q));
}

void reorder_polygon(vector<P>& p) {
    int pi = 0;
    repx(i, 1, (int)p.size()) {
        if(p[i].y < p[pi].y or (p[i].y == p[pi].y and p[i].x < p[pi].x)) 
            pi = i;
    }
    rotate(p.begin(), p.begin() + pi, p.end());
}

vector<P> minkowski(vector<P> ps, vector<P> qs) {
    reorder_polygon(ps), reorder_polygon(qs);
    ps.pb(ps[0]); ps.pb(ps[1]);
    qs.pb(qs[0]); qs.pb(qs[1]);
    vector<P> res; int i = 0, j = 0;
    while(i < ps.size() - 2 or j < qs.size() - 2) {
        res.pb(ps[i] + qs[j]);
        auto z = (ps[i + 1] - ps[i]) ^ (qs[j + 1] - qs[j]);
        if(z >= 0 and i < ps.size() - 2) ++i;
        if(z <= 0 and j < qs.size() - 2) ++j;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> ps(n);
    rep(i, n) cin>>ps[i];
    int m; cin>>m;
    vector<P> qs(m);
    rep(i, m) cin>>qs[i];

    vector<P> ps2, negps, negqs, qs2;
    rep(i, n) ps2.pb(ps[i] * 2), negps.pb(ps[i] * -1);
    rep(i, m) qs2.pb(qs[i] * 2), negqs.pb(qs[i] * -1);

    vector<P> ps_sum_qs = minkowski(ps, qs);
    vector<P> ps2_neg_qs = minkowski(ps2, negqs); 
    vector<P> qs2_neg_ps = minkowski(qs2, negps); 

    // x = (a + b) / 2 -> x2 = a + b
    // x = b + (b - a) = 2b - a
    // x = a + (a - b) = 2a - b


    int q; cin>>q;
    rep(_, q) {
        P x; cin>>x;
        P x2 = x * 2;
        // if(in_convex(ps_sum_qs, x2) >= 0 or in_convex(ps2_neg_qs, x) >= 0 or in_convex(qs2_neg_ps, x) >= 0) cout<<"Y";
        if(inConvexPol(ps_sum_qs, x2) >= 0 or inConvexPol(ps2_neg_qs, x) >= 0 or inConvexPol(qs2_neg_ps, x) >= 0) cout<<"Y";
        else cout<<"N";
    }
    cout<<'\n';


    return 0;
}