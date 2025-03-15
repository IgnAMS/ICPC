#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<int(b); i++)
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

struct P {
    ll x, y;
    P() {} P(ll x, ll y) : x(x), y(y) {}
    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    ll operator^(const P &p) const { return x * p.y - y * p.x; }
    ll operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const {
        return abs(x - p.x) + abs(y - p.y) == 0;
    }
    bool operator<(const P &p) const {
        return abs(x - p.x) > 0 ? p.x - x > 0 : p.y - y > 0;
    }
};

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

ll turn(P &a, P &b, P &c) { return (b - a) ^ (c - a); }

bool above(P &a, P &p) { return p.y >= a.y; }

bool crossesRay(P &a, P &p, P &q) {
    return (above(a, q) - above(a, p)) * turn(a, p, q) > 0;
}

bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }

bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) == 0 && inDisk(a, b, p); 
}

// if strict, returns false when a is on the boundary
bool inPolygon(vector<P> &p, P &a, bool strict = true) {
    int c = 0, n = p.size();
    rep(i, n) {
        if(onSegment(p[i], p[(i + 1) % n], a)) return !strict;
        c += crossesRay(a, p[i], p[(i + 1) % n]);
    }
    return c & 1;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    
    map<char, P> dir = {{'r', P(0, 1)}, {'u', P(-1, 0)}, {'d', P(1, 0)}, {'l', P(0, -1)}};
    vector<P> p1, p2;
    P x; cin>>x;
    string s; cin>>s;
    for(auto c: s) {
        x = x + dir[c];
        p1.pb(x);
    }

    cin>>x>>s;
    for(auto c: s) {
        x = x + dir[c];
        p2.pb(x);
    }

    rep(i, p1.size()) cout<<p1[i]<<", "; cout<<'\n';
    rep(i, p2.size()) cout<<p2[i]<<", "; cout<<'\n';

    ll cont = 0;
    bool pos = 1;
    rep(i, p1.size()) {
        if(inPolygon(p2, p1[i], 0) and !inPolygon(p2, p1[i], 1)) cont++;
        if(inPolygon(p2, p1[i], 1)) pos = 0;
    }
    rep(i, p2.size()) {
        if(inPolygon(p1, p2[i], 1)) pos = 0;
    }
    if(!pos) cout<<"Impossible\n";
    else cout<<cont<<'\n';
    
    return 0;
}