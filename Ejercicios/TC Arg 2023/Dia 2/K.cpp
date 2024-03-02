#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<ll> vl;

#define rep(i, n) for(int i = 0; i<(int)n; ++i)

struct point { db x, y;
    point() {x = y = 0.0; }
    point(db _x, db _y) : x(_x), y(_y) {}

    point operator - (const point &p) const { return point(x - p.x, y - p.y);}
    point operator + (const point &p) const { return point(x + p.x, y + p.y);}
    db operator*(const point &p) const { return x * p.x + y * p.y;}
    point operator* (db p) const { return point(x*p, y*p);}
    db norm_sq() const {return x*x + y*y; }

};

db dist(point p1, point p2){
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y)* (p1.y - p2.y));
}

db distToLine(point p, point a, point b) {
    point c;
    point ap = (p - a), ab = (b - a);
    db u = ap * ab / ab.norm_sq();
    c = a + ab * u;
    return dist(p, c);
}

int main() {
    int n;
    cin >> n;
    vector<point>P;
    rep(i, n)
    {
        point p;
        cin >> p.x >> p.y;
        P.push_back(p);
    }

    db ans = 10000000000;

    rep(i, n)
    {
        ans = min(ans, distToLine(P[(i+1)%n], P[i], P[(i+2)%n])/2);
    }

    cout <<fixed << setprecision(8)<< ans << "\n";
}


// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt
