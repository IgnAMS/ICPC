#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define repx(i,a,b) for(int i=a;i<b;i++)
typedef long long ll;
typedef double db;

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

double integral(double x){
    return 0.5 * (sqrt(2*x - x*x) -x*(sqrt(2*x - x*x) - 2) + 2*asin(sqrt(1 - x/2.0)));
}

double arc_integral(double x, double r, double a, double b) {
    return x * r * (sin(b) - sin(a)) + r * r * 0.5 * (0.5 * (sin(2*b) - sin(2*a)) + b - a);
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    repx(i, 1, 3){
        double angle = atan(1.0 / double(i));
        cerr<<angle<<'\n';
        P p = P(1 + cos(3.0 * PI / 2.0 - angle), 1 + sin(3.0 * PI / 2.0 - angle));
        //cerr<<angle<<" "<<p.x<<" "<<p.y<<"\n";
        //double a1 = 1 - sin(angle) + 0.5 * angle - 0.25 * PI + 0.25 * sin(2.0 * angle);
        double a1 = arc_integral(1.0, 1.0, 3.0 * PI / 2.0 - angle, 3.0 * PI / 2.0);
        double a2 = 0.5 * p.x * p.y;
        cerr<<angle<<' '<< arc_integral(1.0, 1.0, 3.0 * PI / 2.0 - angle, 3.0 * PI / 2.0)<<' '<<a2<<'\n';
        //cerr<<a2<<'\n';
        //cerr<<a1<<" "<<a2<<"\n";
        //cerr<<a1 - a2<<" "<<(4.0 - PI)/4.0<<"\n";
        cout<<i<<" porcion: "<<(a1 - a2) / ((4.0 - PI)/4.0) * 100<<"\n";
    }





    return 0;
}