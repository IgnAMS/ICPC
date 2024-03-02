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


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    Point x1, x2; cin>>x1.x>>x1.y>>x2.x>>x2.y;
    int q; cin>>q;
    rep(i, q) {
        Point p; cin>>p.x>>p.y;
        if(turn(x1, x2, p) > 0) cout<<"I\n";
        else if(turn(x1, x2, p) < 0) cout<<"D\n";
        else cout<<"C\n";
    }


    return 0;
}