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
const db EPS =  1e-9;

typedef ll T;
struct P {
    T x, y;
    P() {} 
    P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll &c) const { return P(x * c, y * c); }
    P operator/(const ll &c) const { return P(x / c, y / c); }
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
};

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) < EPS && inDisk(a, b, p); 
}

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

bool inPolygon(vector<P> &p, P &a, bool strict = true) {
    int c = 0, n = p.size();
    rep(i, n) {
        if(onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

vector<P> A(4), B(4);

vector<P> convexHull(vector<P> &p) {
    int n = p.size(), k = 0;
    vector<P> H(2 * n);
    sort(p.begin(), p.end());

    rep(i, n) {
        while (k >= 2 && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for (int i = n - 2, t = k + 1; i >= 0; i--) {
        while (k >= t && turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    return H;
}


ll sign(ll x) {
    if(x < 0) return -1;
    if(x > 0) return 1;
    return 0;
}

bool properInter(P &a, P &b, P &c, P &d) {
    T ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    return (sign(ta) * sign(tb) < 0 && sign(tc) * sign(td) < 0);
}

int main() {
    int t; cin>>t;
    map<string, P> mapa; 
    mapa["N"] = P(0, 1), mapa["S"] = P(0, -1);
    mapa["E"] = P(1, 0), mapa["W"] = P(-1, 0);
    string d1, d2;
    P c1, c2;
    int w1, w2, l1, l2, s1, s2;
    cin>>d1>>c1>>s1>>w1>>l1;
    cin>>d2>>c2>>s2>>w2>>l2;
    
    c1 = c1 * 2, c2 = c2 * 2;
    s1 *= 2, s2 *= 2, w1 *= 2, l1 *= 2, w2 *= 2, l2 *= 2;

    int cont = 0;
    
    if(d1 == "N" or d1 == "S") swap(w1, l1);
    if(d2 == "N" or d2 == "S") swap(w2, l2);

    for(int i = -1; i <= 1; i += 2) for(int j = -1; j <= 1; j += 2){
        A[cont] = c1 + P(i, 0) * l1 / 2 + P(0, j) * w1 / 2;
        B[cont] = c2 + P(i, 0) * l2 / 2 + P(0, j) * w2 / 2;
        cont++;
    }
    swap(A[2], A[3]);
    
    P dira = mapa[d1] * s1, dirb = mapa[d2] * s2;
    rep(i, 4) {
        A.push_back(A[i] + (dira - dirb) * t);
    }
    swap(B[2], B[3]);
    
    bool oc = 0;
    vector<P> ch = convexHull(A);
    
    rep(i, 4) rep(j, ch.size()) {
        if(properInter(B[i], B[(i + 1) % 4], ch[j], ch[(j + 1) % ch.size()])) oc = 1;
    }

    rep(i, B.size()) if(inPolygon(ch, B[i])) oc = 1;
    rep(i, A.size()) if(inPolygon(B, A[i])) oc = 1;
    if(inPolygon(ch, c2)) oc = 1;
    
    if(oc) cout<<"crash \n";
    else cout<<"safe\n";

    return 0;
}