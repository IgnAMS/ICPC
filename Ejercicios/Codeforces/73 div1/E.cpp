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

// POINT 2D

typedef ll T; struct P {
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


T turn(P a, P b, P c) { return (b - a) ^ (c - a); }

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

    // int pi = min_element(p.begin(), p.end()) - p.begin();
    // rotate(p.begin(), p.begin() + pi, p.end());
    // vector<P> s(n);
    // rep(i, n) s[i] = p[(pi + i) % n];
    // p.swap(s);
}


bool inConvexPol(vector<P>& p, P& q) { // first get rid of the collinear points
    if(turn(p[0], p[1], q) > 0 or turn(p.back(), p[0], q) > 0) return 0;
    int l = 1, r = p.size() - 2;
    while(l < r) {
        ll m = (l + r + 1) / 2;
        if(turn(p[0], p[m], q) <= 0) l = m;
        else r = m - 1;
    }
    // cout<<l<<' '<<r<<'\n';
    // cout<<-turn(p[l], p[l + 1], q)<<'\n';

    return turn(p[l], p[l + 1], q) <= 0;
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

vector<P> convexHull(vector<P> &p) {
    int n = p.size(), k = 0;
    vector<P> H(2 * n); sort(p.begin(), p.end());
    rep(i, n) {
        while(k >= 2 && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}

T left(P& a, P& b, P& p) { return (b - a) ^ (p - a); }
T in_convex(const vector<P> &p, P q) {
    int l = 1, h = p.size() - 2; assert(p.size() >= 3);
    while (l != h) { // collinear points are unsupported!
        int m = (l + h + 1) / 2;
        if(turn(p[0], p[m], q) <= 0) l = m;
        else h = m - 1;
    }
    // cout<<l<<' '<<h<<'\n';
    // cout<<-turn(p[0], p[1], q)<<' '<<-turn(p.back(), p[0], q)<<' '<<-turn(p[l], p[l + 1], q)<<'\n';
    T in = min(-turn(p[0], p[1], q), -turn(p.back(), p[0], q)); 
    return min(in, -turn(p[l], p[l + 1], q));
    // T in = min(q.left(p[0], p[1]), q.left(p.back(), p[0]));
    // return min(in, q.left(p[l], p[l + 1]));
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<P> ps[3];
    rep(i, 3) {
        int n; cin>>n;
        ps[i].resize(n);
        rep(j, n) cin>>ps[i][j];
        // cout<<"puntos\n";
        // rep(j, n) cout<<ps[i][j]<<", "; cout<<'\n';
    }
    vector<P> suma = minkowski(ps[0], ps[1]);
    // rep(i, suma.size()) cout<<suma[i]<<", "; cout<<'\n';
    suma = minkowski(suma, ps[2]);
    suma = convexHull(suma);
    // normalize(suma);

    // cout<<"resultado final :)\n";
    // rep(i, suma.size()) cout<<suma[i]<<", "; cout<<'\n';

    int q; cin>>q;
    while(q--) {
        P p; cin>>p;
        p = p * 3;
        // cout<<"pruebo "<<p<<'\n';
        ll res1 = in_convex(suma, p);
        // cout<<res1<<'\n';
        ll res2 = inConvexPol(suma, p);
        // cout<<"res1: "<<res1<<' '<<res2<<'\n';
        // if(res1 > 0) cout<<"Yes\n";
        if(res1 > 0) cout<<"YES\n"; 
        else cout<<"NO\n";
    }




    return 0;
}