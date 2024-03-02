#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma") // could make sigill runtime error
#include<bits/stdc++.h>
using namespace std;
#define repx(i,a,b) for(int i=a; i<b; i++)
#define rep(i,n) repx(i,0,n)
typedef long long ll;
typedef pair<ll, ll> pll;
typedef double db;
typedef pair<db, db> pdb;
typedef vector<ll> vl;
#define ff first
#define ss second
#define pb push_back
// g++ -std=c++11 A.cpp -o a && a <input.txt> output.txt
// ulimit -s 1000000
// g++ -O2 D.cpp && time ./a.out <input.txt> output.txt


db EPS = 1e-12;

struct P {
    ll x, y; 
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    P operator+(P p) const { return P(x + p.x, y + p.y); }
    P operator-(P p) const { return P(x - p.x, y - p.y); }
    P operator*(ll c) const { return P(c * x, c * y); }
    P operator/(ll c) const { return P(x / c, y / c); }
    ll operator*(P p) const { return x * p.x + y * p.y; }
    ll operator^(P p) const { return x * p.y - y * p.x; }
     bool operator<(const P &p) const
    {
        return abs(x - p.x) > 0 ? p.x - x > 0 : p.y - y > 0;
    }
};


const int mxN = 2e2+5;
const ll MOD = 1e9+7;
vector<P> Pol;

ll sign(ll x) { return x == 0? 0: (x > 0? 1: -1); }

ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}


bool inDisk(P &a, P &b, P &p) { return (a - p) * (b - p) <= 0; }
bool onSegment(P &a, P &b, P &p) {
    return abs(turn(a, b, p)) <= 0 && inDisk(a, b, p); 
}

bool properInter(P &a, P &b, P &c, P &d, P &out) {
    ll ta = turn(c, d, a), tb = turn(c, d, b),
      tc = turn(a, b, c), td = turn(a, b, d);
    if(tb != ta) out = (a * tb - b * ta) / (tb - ta);
    return (ta * sign(tb) < 0 && tc * sign(td) < 0);
}

bool inter(P &a, P &b, P &c, P &d) {
    P out;
    if(properInter(a, b, c, d, out)) return true;
    if(onSegment(c, d, a)) true;
    if(onSegment(c, d, b)) true;
    if(onSegment(a, b, c)) true;
    if(onSegment(a, b, d)) true;
    return false;
}

bool intersects(P& a, P& b) {
    rep(i, Pol.size()) {
        ll next = (i + 1 == Pol.size()? 0: i + 1);
        if(inter(Pol[i], Pol[next], a, b)) return false;
    }
    return true;
}


/// bool above(P &a, P &p) { return p.y >= a.y; }

bool above(pdb a, pdb p) { return p.ss >= a.ss; }
db turndb(pdb a, pdb b, pdb& c) {
    pdb aux1 = {b.ff - a.ff, b.ss - a.ss};
    pdb aux2 = {c.ff - a.ff, c.ss - a.ss};
    return aux1.ff * aux2.ss - aux1.ss * aux2.ff;
}
bool crossesRay(pdb a, pdb p, pdb q) {
    return (above(a, q) - above(a, p)) * turndb(a, p, q) > 0;
}

// if strict, returns false when a is on the boundary
bool inPolygon(vector<P> &p, pdb &a, bool strict = true) {
    int c = 0, n = p.size();
    rep(i, n) {
        pdb curr = {p[i].x, p[i].y};
        pdb next = {p[(i + 1) % n].x, p[(i + 1) % n].y};
        c += crossesRay(a, curr, next);
    }
    return c & 1;
}


ll DP[mxN][mxN];
ll Triang[mxN][mxN];
ll dp(ll i, ll j) {
    // cerr<<"holi "<<i<<' '<<j<<'\n';
    if(j - i <= 2) return 1;
    
    if(DP[i][j] != -1) return DP[i][j];
    
    DP[i][j] = 0;
    repx(k, i + 1, j) if(Triang[i][k] and Triang[k][j]) {
        DP[i][j] += dp(i, k) * dp(k, j) % MOD;
        if(DP[i][j] >= MOD) DP[i][j] -= MOD;
    }
    return DP[i][j];
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    Pol.resize(n);
    rep(i, n) cin>>Pol[i].x>>Pol[i].y;


    rep(i, n) repx(j, i + 1, n) {
        if(j == i + 1) Triang[i][j] = 1;
        else {
            Triang[i][j] = 1;
            rep(k, n) {
                ll curr = k, next = (k + 1 == n? 0: k + 1);
                P out;
                // checking if the line cross with the polygon
                if(properInter(Pol[curr], Pol[next], Pol[i], Pol[j], out)) Triang[i][j] = 0;
                if(curr != i and curr != j and onSegment(Pol[i], Pol[j], Pol[curr]))  Triang[i][j] = 0;
                if(next != i and next != j and onSegment(Pol[i], Pol[j], Pol[next]))  Triang[i][j] = 0;
                if(i != curr and i != next and onSegment(Pol[curr], Pol[next], Pol[i]))  Triang[i][j] = 0;
                if(j != curr and j != next and onSegment(Pol[curr], Pol[next], Pol[j]))  Triang[i][j] = 0;
            }
            pdb mid = {db(Pol[i].x + Pol[j].x) / 2., db(Pol[i].y + Pol[j].y) / 2.};
            if(!inPolygon(Pol, mid)) Triang[i][j] = 0;
            // cout<<mid.ff<<' '<<mid.ss<<'\n';
        }
        // cout<<i<<' '<<j<<' '<<Triang[i][j]<<'\n';
    }
    rep(i, mxN) rep(j, mxN) DP[i][j] = -1;
    cout<<dp(0, n - 1)<<'\n';

    return 0;
}