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

struct Point {
    ll x, y;
    Point() {}
    Point(ll x, ll y): x(x), y(y) {}
    Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
    Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
    Point operator*(const ll k) const { return Point(k * x, k * y); }
    ll operator*(const Point &p) const { return x * p.x + y * p.y; }
    ll operator^(const Point &p) const { return x * p.y - y * p.x; }    
    ll norm2() const { return x * x + y * y; }
    ll norm1(const Point &p) const { return abs(x - p.x) + abs(y - p.y); }
    bool operator==(const Point &p) const { return x == p.x and y == p.y; }
};



ll norm1(Point &a, Point &b) { 
    return abs(a.x - b.x) + abs(a.y - b.y); 
}
    

ll turn(Point &a, Point &b, Point &c) {
    return (b - a) ^ (c - a);
}

Point dir(Point &a, Point &b) {
    if(a.x == b.x and a.y < b.y) return Point(0, 1);
    if(a.x == b.x and a.y > b.y) return Point(0, -1);
    if(a.x < b.x and a.y == b.y) return Point(1, 0);
    if(a.x > b.x and a.y == b.y) return Point(-1, 0);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<Point> P1(n);
    for(auto& p: P1) cin>>p.x>>p.y;

    int m; cin>>m;
    vector<Point> P2(m);
    for(auto& p: P2) cin>>p.x>>p.y;

    vector<ll> T;
    ll t = 0;
    rep(i, n - 1) {
        t += norm1(P1[i], P1[i + 1]);
        T.pb(t);
    }
    t = 0;
    rep(i, m - 1) {
        t += norm1(P2[i], P2[i + 1]);
        T.pb(t);
    }

    sort(T.begin(), T.end());
    int c1 = 1, c2 = 1;
    Point a1 = P1[0], a2 = P1[1], b1 = P2[0], b2 = P2[1];
    ll t1 = 0, t2 = 0;
    db ans2 = 1e15;
    rep(i, T.size()) {
        if(c1 == n + 1 or c2 == m + 1) break;
        Point d1 = dir(a1, a2);
        Point d2 = dir(b1, b2);

        Point u = a1 - b1;
        cout<<"("<<a1.x<<", "<<a1.y<<"), ("<<a2.x<<", "<<a2.y<<")\n";
        cout<<"("<<b1.x<<", "<<b1.y<<"), ("<<b2.x<<", "<<b2.y<<")\n";
        Point d = d1 - d2;
        // min (u.x + d.x * t)^2 + (u.y + d.y * t)^2 
        // d/dt = 2 d.x (u.x + d.x * t) + 2 d.y (u.y + d.y * t)^2
        // t * (d.x^2 + d.y^2) = -2 d.x * u.x - 2 d.y * u.y
        // t = (-2 d.x * u.x  - 2 d.u * u.y) / (d.x^2 + d.y^2) = db(d * u * (-2)) / db(d * d)
        
        ll tf = min(norm1(a1, a2), norm1(b1, b2));
        if(d * d != 0) {
            db tp = db(d * u * (-2)) / db(d * d);
            if(0 <= tp and tp <= tf) {
                db dist = (u.x + tf * d.x) * (u.x + tf * d.x) + (u.y + tf * d.y) * (u.y + tf * d.y);
                ans2 = min(ans2, dist);
                cout<<"("<<u.x<<", "<<u.y<<"), ("<<d.x<<", "<<d.y<<")\n";
                cout<<dist<<'\n';
            }
        }
        cout<<u.norm2()<<' '<<(u + d * tf).norm2()<<'\n';
        ans2 = min({ans2, db(u.norm2()), db((u + d * tf).norm2())});

        cout<<ans2<<'\n';
        a1 = a1 + d1 * tf;
        b1 = b1 + d2 * tf;

        if(a1 == a2) {
            c1++;
            if(c1 < n) a2 = P1[c1];
        }
        if(b1 == b2) {
            c2++;
            if(c2 < m) b2 = P2[c2];
        }
    }
    cout<<ans2<<'\n';


    return 0;
}