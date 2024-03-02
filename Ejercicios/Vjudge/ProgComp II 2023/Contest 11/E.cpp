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
};


ll turn(Point &a, Point &b, Point &c) {
    return (b - a) ^ (c - a);
}

Point dir[] = {Point(1, 0), Point(-1, 0), Point(0, 1), Point(0, -1)};

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t;
    while(t--) {
        Point x1, x2; cin>>x1.x>>x1.y>>x2.x>>x2.y;
        int k; cin>>k;
        Point p = x1;
        vector<Point> Pos;
        rep(h, 4) {
            p = p + dir[h];
            if((p.x == x1.x and p.y == x1.y) or (p.x == x2.x and p.y == x2.y)) continue;
            ll g1 = __gcd(abs((x1 - p).x), abs((x1 - p).y));
            ll g2 = __gcd(abs((x2 - p).x), abs((x2 - p).y));
            if(g1 == 1 and g2 == 1) Pos.push_back(p);
            p = p - dir[h];
        }
        // if(x1.y != x2.y) p.x += -1;
        // else p.y += -1; 
        
        
        Point d = x2 - x1;
        ll cont = 0;
        rep(i, k) {
            while(true) {
                bool flag = 0;
                for(auto& pos: Pos) {
                    pos = pos + d;
                    ll g1 = __gcd(abs((x1 - pos).x), abs((x1 - pos).y));
                    ll g2 = __gcd(abs((x2 - pos).x), abs((x2 - pos).y));
                    cont++;
                    if(g1 ==  1 and g2 == 1) { 
                        cout<<pos.x<<' '<<pos.y<<'\n';
                        flag = true; 
                        break; 
                    }
                }
                if(flag) break;
            }
            // cout<<p.x<<' '<<p.y<<'\n';
        }
        // cout<<cont<<'\n';
    }





    return 0;
}