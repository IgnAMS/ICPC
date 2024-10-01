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

typedef ll T; struct P {
    T x, y;
    P() {} P(T x, T y) : x(x), y(y) {}

    P operator+(const P &p) const { return P(x + p.x, y + p.y); }
    P operator-(const P &p) const { return P(x - p.x, y - p.y); }
    P operator*(const db &c) const { return P(x * c, y * c); }
    P operator/(const db &c) const { return P(x / c, y / c); }
    T operator^(const P &p) const { return x * p.y - y * p.x; }
    T operator*(const P &p) const { return x * p.x + y * p.y; }
    bool operator==(const P &p) const {
        return abs(x - p.x) + abs(y - p.y) == 0;
    }
    bool operator<(const P &p) const {
        return abs(x - p.x) > 0 ? p.x - x > 0 : p.y - y > 0;
    }

    T norm2() const { return x * x + y * y; }
    db norm() const { return sqrt(norm2()); }
    P unit() { return (*this) / norm(); }
    P perp() { return P(-y, x); }
    P rot(P r) { return P((*this) ^ r, (*this) * r); }
    P rot(db a){ return rot(P(sin(a), cos(a))); }
};
P polar(db r, db a) { return P(r * cos(a), r * sin(a)); }
istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

void reorder_polygon(vector<P>& p) {
    int pi = 0;
    repx(i, 1, (int)p.size()) {
        if(p[i].y < p[pi].y or (p[i].y == p[pi].y and p[i].x < p[pi].x)) 
            pi = i;
    }
    rotate(p.begin(), p.begin() + pi, p.end());
}

vector<P> minkowski(vector<P> ps, vector<P> qs) {
    if(qs.size() == 0) return ps;
    if(ps.size() == 0) return qs;
    reorder_polygon(ps), reorder_polygon(qs);
    ps.pb(ps[0]); ps.pb(ps[1]);
    qs.pb(qs[0]); qs.pb(qs[1]);
    vector<P> res; int i = 0, j = 0;
    while(i < ps.size() - 2 or j < qs.size() - 2) {
        res.pb(ps[i] + qs[j]);
        auto z = (ps[i + 1] - ps[i]) ^ (qs[j + 1] - qs[j]);
        if(z >= 0 and i < ps.size() - 2) ++i;
        if(z <= 0 and j < qs.size() - 2) ++j;
    }
    return res;
}

struct ST {
    vector<vector<P>> T;
    int n;
    ST(vector<vector<P>>& A) {
        n = A.size();
        T.resize(4 * n + 4, {});
        build(A, 0, n - 1, 0);
    }
    void build(vector<vector<P>> &A, ll l, ll r, ll u = 0) {
        if(l == r) {
            T[u] = A[l];
        }
        else {
            ll m = (l + r) / 2;
            build(A, l, m, 2 * u + 1), build(A, m + 1, r, 2 * u + 2);
            T[u] = minkowski(T[2 * u + 1], T[2 * u + 2]);
        }
    }
    vector<P> query(ll i, ll j, ll l, ll r, ll u = 0) {
        if(i <= l and r <= j) return T[u];
        if(r < i or j < l) return {};
        ll m = (l + r) / 2;
        return minkowski(query(i, j, l, m, 2 * u + 1), query(i, j, m + 1, r, 2 * u + 2));
    }

};


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    vector<vector<P>> Ps(n);
    rep(i, n) {
        int k; cin>>k;
        Ps[i].resize(k);
        rep(j, k) cin>>Ps[i][j];
    }
    ST st(Ps);
    int q; cin>>q;
    while(q--) {
        ll l, r; cin>>l>>r, l--, r--;
        vector<P> X = st.query(l, r, 0, n - 1, 0);
        cout<<X.size()<<'\n';
    }
    return 0;
}