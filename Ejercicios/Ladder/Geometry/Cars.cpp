#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<int,int> ii;
typedef double db;

#define ff first
#define ss second
const db PI = acos(-1.0L);
const db EPS =  1e-12;

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
bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p)
{
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q)
{
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

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

double f(double x, P &a, P dia, P &b, P dib) { // dado un tiempo x, me dice que tan cerca estan 
    return ((a + dia * x) - (b + dib * x)).norm();
}


vector<P> A(4, P(0, 0)), B(4, P(0, 0));

// find minimum (convex function)
double min_ternary_search(double l, double r, int times, P &a, P dia, P &b, P dib) {
    while (times--) {
        double d = (r - l) / 3.0;
        double m1 = l + d, m2 = r - d;
        double f1 = f(m1, a, dia, b, dib), f2 = f(m2, a, dia, b, dib);
        if (f1 <= f2) r = m2;
        if (f1 >= f2) l = m1;
    }
    vector<P> A1(4, P(0, 0)), B1(4, P(0, 0));

    rep(i, 4) A1[i] = A[i] + dia * (l+r)*.5;
    rep(i, 4) B1[i] = B[i] + dib * (l+r)*.5;
    A1.push_back(A1[0] + P(0.5, 0)); A1.push_back(A1[0] + P(0, 0.5)); // izquierda abajo
    A1.push_back(A1[1] + P(0.5, 0)); A1.push_back(A1[1] + P(0, -0.5)); // izquierda arriba
    A1.push_back(A1[2] + P(-0.5, 0)); A1.push_back(A1[2] + P(0, 0.5)); // derecha abajo
    A1.push_back(A1[3] + P(-0.5, 0)); A1.push_back(A1[3] + P(0, -0.5)); // derecha arriba
    //rep(i, A1.size()) cerr<<A1[i]<<' '; cerr<<'\n';
    bool oc = 0;
    rep(i, A1.size()) if(inPolygon(B1, A1[i], true)) oc = 1;
    return oc;
}




int main(){
    int t; cin>>t;
    map<string, P> mapa; 
    mapa["N"] = P(0.0, 1.0), mapa["S"] = P(0.0, -1.0);
    mapa["E"] = P(1.0, 0.0), mapa["W"] = P(-1.0, 0.0);
    string d1, d2;
    P c1, c2;
    int w1, w2, l1, l2, s1, s2;
    cin>>d1>>c1>>s1>>w1>>l1;
    cin>>d2>>c2>>s2>>w2>>l2;
    // dos positivos, dos negativos
    int cont = 0; // los dos primeros estan a la izquierda, abajo y arriba
    for(int i = -1; i <= 1; i+=2) for(int j = -1; j<=1; j+=2){
        A[cont] = c1 + P(i, 0.0) * 0.5 * w1 + P(0.0, j) * 0.5 * l1;
        B[cont] = c2 + P(i, 0.0) * 0.5 * w2 + P(0.0, j) * 0.5 * l2;
        cont++;
    }
    bool oc = 0;
    rep(i, 4) rep(j, 4){
        if(min_ternary_search(0, t, 1000, A[i], mapa[d1] * s1, B[j], mapa[d2] * s2)) oc = 1;
    }
    if(oc) cout<<"crash\n";
    else cout<<"safe\n";

    return 0;
}