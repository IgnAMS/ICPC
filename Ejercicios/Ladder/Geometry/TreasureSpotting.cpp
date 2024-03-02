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

struct P {
    ll x, y;
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const ll& c) const { return P(x * c, y * c); }
    P operator/(const ll& c) const { return P(x / c, y / c); }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    ll norm2() const { return x * x + y * y; }
};

ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}


ll sign(ll x) {
    if(x > 0) return 1;
    if(x < 0) return -1;
    return 0;
}

bool properInter(P& a, P& b, P& c, P& d) {
    ll ta = turn(c, d, a), tb = turn(c, d, b), 
        tc = turn(a, b, c), td = turn(a, b, d);
    return sign(ta) * sign(tb) < 0 and sign(tc) * sign(td) < 0;
}

bool onSegment(P& a, P& b, P& p) {
    return turn(a, b, p) == 0 and (b - p) * (a - p) <= 0;
}

bool intersects(P& a, P& b, P& c, P& d) {
    if(onSegment(a, b, c) or onSegment(a, b, d) or onSegment(c, d, a) or onSegment(c, d, b)) return 1;
    if(properInter(a, b, c, d)) return 1;
    return 0; 
}



int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int w, p; cin>>w>>p;
    P Treasure; 
    cin>>Treasure.x>>Treasure.y;

    pair<P, P> W[w];
    rep(i, w) cin>>W[i].ff.x>>W[i].ff.y>>W[i].ss.x>>W[i].ss.y;

    pair<P, P> Pir[p];
    rep(i, p) cin>>Pir[i].ff.x>>Pir[i].ff.y>>Pir[i].ss.x>>Pir[i].ss.y;
    rep(i, p) {
       bool visible = 0;
       if(((Treasure - Pir[i].ff) * (Pir[i].ss - Pir[i].ff)) >= 0 and ((Pir[i].ff - Treasure).norm2() <= (Pir[i].ss - Pir[i].ff).norm2())) visible = 1;
       rep(j, p) if(i != j and onSegment(Pir[i].ff, Treasure, Pir[j].ff)) visible = 0;
       rep(j, w) if(intersects(Pir[i].ff, Treasure, W[j].ff, W[j].ss)) visible = 0;
       cout<<(visible? "visible": "not visible")<<'\n';
    }

    return 0;
}