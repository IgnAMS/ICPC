#include<bits/stdc++.h>
using namespace std;
#define repx(i, a, b) for(int i = a; i < b; i++)
#define rep(i, n) repx(i, 0, n)
typedef long long ll;
typedef vector<ll> vl;
typedef double db;
#define pb push_back

const db EPS = 1e-9;
typedef ll T;
struct P {
    ll x, y;
    P(): x(0), y(0) {}
    P(T x, T y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator/(const db& c) const { return P(x / c, y / c); }
    P operator*(const db& c) const { return P(x * c, y * c); }
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    bool operator==(const P& p) const { 
        return abs(x - p.x) + abs(y - p.y) < EPS;
    }
    bool operator<(const P& p) const {
        return abs(x - p.x) > EPS? p.x - x > EPS: p.y - y > EPS;
    }
};
istream &operator>>(istream &s, P &p) { return s>>p.x>>p.y; }
ostream &operator<<(ostream& s, const P& p) {
    return s <<'('<<p.x<<", "<<p.y<<")";
}

T turn(P &a, P &b, P& c) { return (b - a) ^ (c - a); }


bool inDisk(P &a, P& b, P& p) { return (a - p) * (b - p) <= 0; }
bool onSegment(P &a, P& b, P& p) {
    return abs(turn(a, b, p)) < EPS and inDisk(a, b, p);
}

bool properInter(P &a, P &b, P &c, P &d, P &out) {
    T ta = turn(c, d, a), tb = turn(c, d, b), tc = turn(a, b, c), td = turn(a, b, d);
    if(ta == tb) return 0;
    out = (a * tb - b *ta) / (tb - ta);
    return (ta * tb < 0 and tc * td < 0);
}

set<P> inter(P &a, P &b, P &c, P &d) {
    P out;
    if(properInter(a, b, c, d, out)) return {out};
    set<P> ans;
    if(onSegment(c, d, a)) ans.insert(a);
    if(onSegment(c, d, b)) ans.insert(b);
    if(onSegment(a, b, c)) ans.insert(c);
    if(onSegment(a, b, d)) ans.insert(d);
    return ans;
}

set<P> convexHull(vector<P> &p) {
    int n = p.size(), k = 0;
    vector<P> H(2 * n); sort(p.begin(), p.end());
    rep(i, n) {
        while(k >= 2 and turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t and turn(H[k - 2], H[k - 1], p[i]) <= 0) k--;
        H[k++] = p[i];
    }
    H.resize(k - 1);
    set<P> S;
    for(auto u: H) S.insert(u);
    return S;
}


bool half(P &p) {
    return p.y > 0 or (p.y == 0 and p.x >0);
}

void polarSort(vector<P> &v) {
    sort(v.begin(), v.end(), [](P &p1, P &p2) {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2? h1 > h2: (p1 ^ p2) > 0;
    });
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<P> p(n);
    rep(i, n) cin>>p[i];

    set<P> S = convexHull(p);
    // rep(i, n) {
    //     if(S.count(p[i])) cout<<i<<'\n';
    // }
    ll ans = 0;
    rep(i, n) if(!S.count(p[i])) {
        vector<P> p2;
        rep(j, n) if(i != j) p2.pb(p[j] - p[i]);
        polarSort(p2);
        rep(j, n - 1) {
            if(S.count(p2[j] + p[i]) and S.count(p2[(j + 1) % (n - 1)] + p[i])) ans++;
        }
    }
    cout<<ans + 1<<'\n';

    return 0;
}

