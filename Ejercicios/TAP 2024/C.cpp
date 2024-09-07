#pragma GCC optimize("Ofast")
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

const db PI = acos(-1.0L);
const db EPS = 1e-12;

typedef db T; struct P {
    T x, y, z;
    P(): x(0), y(0), z(0) {}
    P(db x, db y, db z) : x(x), y(y), z(z) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y, z + p.z); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y, z - p.z); }
    P operator*(const db &c) const { return P(x * c, y * c, z * c); }
    P operator/(const db &c) const { return P(x / c, y / c, z / c); }
    P operator^(const P &p) const {
        return P(y * p.z - z * p.y, 
                 z * p.x - x * p.z,
                 x * p.y - y * p.x);
    }
    T operator*(const P &p) const { return x * p.x + y * p.y + z * p.z; }
};

pair<P, T> plane(P& a, P& b, P& c) {
    P normal = (b - a) ^ (c - a);
    pair<P, db> p = {normal, (a * normal) * -1};
    return p;
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    P apex, sun;
    cin>>apex.x>>apex.y>>apex.z; cin>>sun.x>>sun.y>>sun.z;

    vector<P> ps(n);
    rep(i, n) cin>>ps[i].x>>ps[i].y, ps[i].z = 0;

    ll pos = 0, neg = 0;
    rep(i, n) {
        auto p = plane(ps[i], ps[(i + 1) % n], apex);
        // cout<<p.ff.x<<' '<<p.ff.y<<' '<<p.ff.z<<' '<<p.ss<<'\n';
        db val = (sun * p.ff) + p.ss;
        if(abs(val) < EPS) continue;
        if(val > 0) pos++;
        else neg++;
    }


    if(pos and neg) cout<<"S\n";
    else cout<<"N\n";

    return 0;
}