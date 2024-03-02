#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
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

typedef db T;
struct P {
    T x, y;
    P(): x(0), y(0) {}
    P(db x, db y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const T c) const { return P(x * c, y * c); }
    P operator/(const T c) const { return P(x / c, y / c); }
    T operator*(const P& p) const { return x * p.x + y * p.y; }
    T operator^(const P& p) const { return x * p.y - y * p.x; }
    T norm2() const { return x * x + y * y; }
};

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

T turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}

P bary(P &A, P &B, P &C, T a, T b, T c) {
    return (A * a + B * b + C * c) / (a + b + c);
}

P circum(P &A, P &B, P &C) {
    T a = (B - C).norm2(), b = (C - A).norm2(), c = (A - B).norm2();
    return bary(A, B, C, a * (b + c - a), b * (c + a - b), c * (a + b - c));
}


int main() { 
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    while(cin>>n and n) {
        P points[n];
        rep(i, n) cin>>points[i];

        ll ans = min(2, n);
        rep(i, n) repx(j, i + 1, n) repx(k, j + 1, n) { 
            if(((points[j] - points[i]) ^ (points[k] - points[i])) == 0) continue;

            P circ = circum(points[i], points[j], points[k]);
            T radio2 = (points[i] - circ).norm2();
            ll cont = 0;
            rep(a, n) if(abs((points[a] - circ).norm2() - radio2) <= 1e-40) cont++;
            ans = max(ans, cont + 3);
        }
        cout<<ans<<'\n';
    }

    return 0;
}