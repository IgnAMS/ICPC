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

db EPS = 1e-15;

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
};


db turn(Point &a, Point &b, Point &c) {
    return (b - a) ^ (c - a);
}

// Check if (x1, x2) is crossed with  (y1, y2)
bool crossed(Point &x1, Point &x2, Point &y1, Point &y2) {
    db tx1 = turn(y1, y2, x1), tx2 = turn(y1, y2, x2), 
       ty1 = turn(x1, x2, y1), ty2 = turn(x1, x2, y2);
    return (ty1 * ty2 < 0) and (tx1 * tx2 < 0);
}


// Check if y is in the line of (x1, x2)
bool inLine(Point &x1, Point &x2, Point &y) {
    // The cross product must be 0, it must be in the same line
    return abs(turn(x1, x2, y)) < EPS and ((x1 - y) * (x2 - y)) <= 0; 
}

bool inHalfDisk(Point &x1, Point &x2, Point &y) {
    return (y - x1).norm2() <= (x2 - x1).norm2() + EPS and ((y - x1) * (x2 - x1)) > -EPS;
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int w, p; cin>>w>>p;
    Point tesoro; cin>>tesoro.x>>tesoro.y;

    vector<pair<Point, Point>> Walls(w);
    rep(i, w) {
        cin>>Walls[i].ff.x >> Walls[i].ff.y >> Walls[i].ss.x >> Walls[i].ss.y;
    }
    vector<pair<Point, Point>> Pirates(p);
    rep(i, p) {
        cin>>Pirates[i].ff.x >> Pirates[i].ff.y >> Pirates[i].ss.x >> Pirates[i].ss.y;
    }

    // cout<<(Pirates[0].ss - Pirates[0].ff) * (tesoro - Pirates[0].ff)<<'\n';

    rep(i, p) {
        bool visible = 1;
        if(!inHalfDisk(Pirates[i].ff, Pirates[i].ss, tesoro)) visible = 0;
        for(auto wall: Walls) {
            // cout<<inLine(Pirates[i].ff, tesoro, wall.ff)<<'\n';
            // cout<<inLine(Pirates[i].ff, tesoro, wall.ss)<<'\n';
            // cout<<crossed(Pirates[i].ff, tesoro, wall.ff, wall.ss)<<'\n';
            if(inLine(Pirates[i].ff, tesoro, wall.ff)) visible = 0;
            if(inLine(Pirates[i].ff, tesoro, wall.ss)) visible = 0;
            if(inLine(wall.ff, wall.ss, tesoro)) visible = 0;
            if(inLine(wall.ff, wall.ss, Pirates[i].ff)) visible = 0;
            if(crossed(Pirates[i].ff, tesoro, wall.ff, wall.ss)) visible = 0;
        }
        rep(j, p) {
            if(j != i and inLine(Pirates[i].ff, tesoro, Pirates[j].ff)) {
                visible = 0;
            }
        }

        if(visible) cout<<"visible\n";
        else cout<<"not visible\n";
    }


    return 0;
}