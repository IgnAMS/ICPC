#pragma GCC optimize("Ofast")
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
 
db EPS = 1e-14;
typedef long double T;
struct P {
    T x, y;
    P(): x(0), y(0) {}
    P(T x, T y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const T c) const { return P(x * c, y * c); }
    P operator/(const T c) const { return P(x / c, y / c); }
    T operator*(const P& p) const { return x * p.x + y * p.y; }
    T operator^(const P& p) const { return x * p.y - y * p.x; }
};
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}
 
int L, C, X, Y;
 
bool half(P p) { return p.y > 0 or (p.y == 0 and p.x > 0); }
 
struct Event: P {
    int ind, type;
};
 
int whichline(Event& p) {
    if(abs(p.y) < EPS) return 0;
    if(abs(p.x - X) < EPS) return 1;
    if(abs(p.y - Y) < EPS) return 2;
    return 3;
}
 
bool comp(Event& p1, Event& p2) {
    int h1 = whichline(p1), h2 = whichline(p2);
    if(h1 != h2) return h1 < h2;
    if(h1 == 0) return p1.x < p2.x;
    if(h1 == 1) return p1.y < p2.y;
    if(h2 == 2) return p1.x > p2.x;
    return p1.y > p2.y;
}
 
struct circle : P {
    db r;
};
 
struct Line {
    db a, b, c;
    bool equal(Line& l) { return abs(a - l.a) + abs(b - l.b) + abs(c - l.c) < 1e-4; }
};
 
void tangents (P c, db r1, db r2, vector<Line> & ans) {
    db r = r2 - r1;
    db z = c.x * c.x + c.y * c.y;
    db d = z - r * r;
    if(d < 0) return;
    d = sqrt(abs(d));
 
    Line l;
    l.a = (c.x * r + c.y * d) / z;
    l.b = (c.y * r - c.x * d) / z;
    l.c = r1;
    ans.push_back(l);
}
 
vector<Line> tangents(circle a, circle b) {
    vector<Line> ans;
    for (int i = -1; i <= 1; i += 2) {
        for (int j = -1; j <= 1; j += 2)
            tangents(b-a, a.r * i, b.r * j, ans);
    }
    for(int i = 0; i < ans.size(); ++i) {
        ans[i].c -= ans[i].a * a.x + ans[i].b * a.y;
    }
    vector<Line> ans2 = {ans[0], ans[3]};
    return ans2;
}
T turn(P& a, P& b, P& c) { return (b - a) ^ (c - a); }
 
bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) < EPS and (a - p) * (b - p) <= 0; 
}
 
bool inPolygon(vector<P> &p, P &a, bool strict = false) {
    int n = p.size();
    rep(i, n) {
        if (onSegment(p[i], p[(i + 1) % n], a)) return !strict;
    }
    return false;
}
 
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    while(cin>>L>>C>>X>>Y and L) {
        P lights[L];
        rep(i, L) cin>> lights[i].x >> lights[i].y;
        circle columns[C];
        rep(i, C) cin>> columns[i].x >> columns[i].y >> columns[i].r;
        vector<P> rect = {P(0, 0), P(X, 0), P(X, Y), P(0, Y)};
        
        vector<Event> E;
        int sombras = 0;
        multiset<int> S;
        rep(i, L) rep(j, C) {
            circle auxcirc;
            auxcirc.x = lights[i].x, auxcirc.y = lights[i].y, auxcirc.r = 0;
            vector<Line> lines = tangents(auxcirc, columns[j]);
            
            Event e[2];
            rep(il, 2) {
                Line& line = lines[il];
                P dir(-line.b, line.a);
                if(dir * (columns[j] - lights[i]) < 0) {
                    dir = dir * -1;
                    line.a *= -1, line.b *= -1, line.c *= -1;
                }
                P vec;
                if(abs(dir.x) < EPS) {
                    if(dir.y > 0) vec = P(lights[i].x, Y);
                    else vec = P(lights[i].x, 0);
                }
                else if(abs(dir.y) < EPS) {
                    if(dir.x > 0) vec = P(X, lights[i].y);
                    else vec = P(0, lights[i].y);
                }
                else {
                    P aux;
                    aux.x = 0, aux.y = -lines[il].c / lines[il].b;
                    if(inPolygon(rect, aux) and (aux - lights[i]) * (columns[j] - lights[i]) >= 0) vec = aux;
 
                    aux.x = X, aux.y = (-lines[il].c - lines[il].a * X) / lines[il].b;
                    if(inPolygon(rect, aux) and (aux - lights[i]) * (columns[j] - lights[i]) >= 0) vec = aux;
                    
                    aux.x = -lines[il].c / lines[il].a, aux.y = 0;
                    if(inPolygon(rect, aux) and (aux - lights[i]) * (columns[j] - lights[i]) >= 0) vec = aux;
                    
                    aux.x = (-lines[il].c - lines[il].b * Y) / lines[il].a, aux.y = Y;
                    if(inPolygon(rect, aux) and (aux - lights[i]) * (columns[j] - lights[i]) >= 0) vec = aux;
                }
                e[il].x = vec.x, e[il].y = vec.y, e[il].ind = i; 
            }
            if(turn(lights[i], e[0], e[1]) < 0) swap(e[0], e[1]);
            e[0].type = 0, e[1].type = 1;
            if(!comp(e[0], e[1])) {
                if(!S.count(i)) sombras++;
                S.insert(i);
            }
            E.pb(e[0]); E.pb(e[1]);
        }
 
        for(auto u: rect) {
            Event e; e.x = u.x, e.y = u.y, e.type = 2;
            E.pb(e);
        }
        sort(E.begin(), E.end(), comp);
 
        Event last; last.x = 0, last.y = 0;
        db ans = 0;
        for(auto e: E) {
            if(sombras < L) ans += abs(last.x - e.x) + abs(last.y - e.y);
            // cout<<sombras<<' '<<e<<'\n';
            if(e.type == 0) {
                if(!S.count(e.ind)) sombras++;
                S.insert(e.ind);
            }
            else if(e.type == 1 and S.count(e.ind)) {
                S.erase(S.find(e.ind));
                if(!S.count(e.ind)) sombras--;
            }
            last = e;
        }
        if(sombras < L) ans += abs(last.x - rect[0].x) + abs(last.y - rect[0].y);
        cout<<setprecision(4)<<fixed<<ans<<'\n';
    }
 
    return 0;
} 