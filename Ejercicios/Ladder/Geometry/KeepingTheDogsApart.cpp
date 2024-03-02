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

db EPS = 1e-9;
typedef db T;
struct P {
    T x, y;
    P(): x(0), y(0) {}
    P(T x, T y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const T c) const { return P(x * c, y * c); }
    P operator/(const T c) const { return P(x / c, y / c); }
    T operator*(const P& p) const { return x * p.x + y * p.y; }
    T operator^(const P& p) const { return x * p.y - y * p.x; }
    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    bool operator==(const P& p) const { return abs(x - p.x) + abs(y - p.y) < EPS; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

db mindist(P& p1, P& p2, P& dir1, P& dir2, db t) {
    db l = 0, r = t;
    int iter = 100;
    rep(_, iter) {
        db d = (r - l) * 0.3333333333333;
        db m1 = l + d, m2 = r - d;
        db f1 = (p1 - p2 + (dir1 - dir2) * m1).norm(), f2 = (p1 - p2 + (dir1 - dir2) * m2).norm();
        if(f1 <= f2) r = m2;
        if(f1 >= f2) l = m1;
    }
    // cout<<"se minimiza en "<<(l + r) * 0.5<<" con "<<l<<' '<<r<<'\n';
    return (p1 - p2 + (dir1 - dir2) * (l + r) * 0.5).norm();
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> P1(n);
    rep(i, n) cin>>P1[i];
    int m; cin>>m;
    vector<P> P2(m);
    rep(i, m) cin>>P2[i];

    int i1 = 0, i2 = 0;
    P p1 = P1[0], p2 = P2[0];
    db ans = 1e11;
    while(i1 < n and i2 < m) {
        if(p1 == P1[i1]) {
            i1++;
            if(i1 == n) break;
        }
        if(p2 == P2[i2]) {
            i2++;
            if(i2 == m) break;
        }

        P dir1 = P1[i1] - p1, dir2 = P2[i2] - p2;
        
        db next_t = min(dir1.norm(), dir2.norm());
        // normas normalizadas
        dir1 = dir1 / dir1.norm(), dir2 = dir2 / dir2.norm();

        // min (p1 - p2) + (dir1 - dir2) * t
        ans = min(ans, mindist(p1, p2, dir1, dir2, next_t));

        p1 = p1 + dir1 * next_t;
        p2 = p2 + dir2 * next_t;
    }
    cout<<setprecision(10)<<fixed<<ans<<'\n';
    return 0;
}