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

bool left(P& a, P& b, P& p) { return ((b - a) ^ (p - a)) > 0; }

ll inDisk(P& a, P& b, P& c) { return ((b - a) * (c - a)) <= 0; }

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
}

bool inConvexPol(vector<P>& p, P& q, bool strict=true) { // first get rid of the collinear points
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

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> A(n); rep(i, n) cin>>A[i];

    int m; cin>>m;
    vector<P> B(m); rep(i, m) cin>>B[i];

    normalize(A);
    bool flag = 1;
    rep(i, m) {
        if(!inConvexPol(A, B[i])) flag = 0;
    }
    if(flag == 0) cout<<"NO\n";
    else cout<<"YES\n";




    return 0;
}