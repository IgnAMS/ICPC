#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double db;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt

db EPS = 1e-9;
db PI = acos(-1.0);

typedef long double T;
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
    T operator==(const P& p) const { return abs(x - p.x) + abs(y - p.y) < EPS; }
    db ang() {
        db a = atan2(y, x);
        if(a > 2 * PI) a -= 2 * PI;
        if(a < 0) a += 2 * PI;
        return a;
    }
};

T turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

struct Circ: P{
    db r;
};

int n;
Circ C[101];


struct line {
    T a, b, c;
};

double sqr(T a) { return a * a; }

void tangents(P c, db r1, db r2, vector<line> & ans) {
    db r = r2 - r1;
    db z = sqr(c.x) + sqr(c.y);
    db d = z - sqr(r);
    if(d < -EPS)  return;
    d = sqrt (abs (d));
    line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    ans.push_back(l);
}

vector<line> tangents(Circ a, Circ b) {
    vector<line> ans;
    for(int i = -1; i <= 1; i += 2) {
        for(int j = -1; j <= 1; j += 2)
            tangents(b-a, a.r * i, b.r * j, ans);
    }
    for (size_t i = 0; i < ans.size(); ++i)
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    return ans;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    rep(i, n) cin >> C[i].x >> C[i].y >> C[i].r;

    vector<line> L;
    rep(i, n) repx(j, i + 1, n) {
        for(auto u: tangents(C[i], C[j])) L.pb(u);
    }

    for(auto [a, b, c]: L) {
        P dir = P(-b, a);
        cout<<a<<' '<<b<<' '<<c<<' '<<dir.ang()<<'\n';
    }

    return 0;
}