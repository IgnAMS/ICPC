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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    repx(i, 1, 4){
        double angle = atan(1.0 / double(i));
        P p = P(1.0 - cos(angle), 1.0 - sin(angle));
        cerr<<angle<<" "<<p.x<<" "<<p.y<<" "<<angle<<"\n";
        //double a1 = sqrt(2) * sin(angle) * sin(angle) / 2 + 1 - p.x;
        double a1 = integral(1) - integral(p.x);
        double a2 = p.x * p.y / 2.0;
        cerr<<a1<<" "<<a2<<"\n";
        cerr<<a1+a2<<" "<<(4.0-PI)/4.0<<"\n";
        cout<<"porcion: "<<(a1 + a2) / ((4.0 - PI)/4.0)<<"\n";
    }





    return 0;
}