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
const db EPS = 1e-12;

typedef ll T;
struct P {
    T x, y;
    P(T x, T y) : x(x), y(y) {}
    P() : P(0, 0) {}

    friend ostream &operator<<(ostream &s, const P &r) {
        return s << "(" << r.x << ", " << r.y<<")";
    }
    friend istream &operator>>(istream &s, P &r) { return s >> r.x >> r.y; }

    P operator+(P r) const { return {x + r.x, y + r.y}; }
    P operator-(P r) const { return {x - r.x, y - r.y}; }
    P operator*(T r) const { return {x * r, y * r}; }
    P operator/(T r) const { return {x / r, y / r}; }
    P operator-() const { return {-x, -y}; }
    friend P operator*(T l, P r) { return {l * r.x, l * r.y}; }

    P rot() const { return {-y, x}; }
    T operator*(P r) const { return x * r.x + y * r.y; }
    T operator%(P r) const { return rot() * r; }
    T left(P a, P b) { return (b - a) % (*this - a); }

    T magsq() const { return x * x + y * y; }
    T mag() const { return sqrt(magsq()); }
    P unit() const { return *this / mag(); }

    bool half() const { return abs(y) <= EPS && x < -EPS || y < -EPS; }
    T angcmp(P r) const { // like strcmp(this, r)
        int h = (int)half() - r.half();
        return h ? h : r % *this;
    }

    bool operator==(P r) const { return abs(x - r.x) <= EPS && abs(y - r.y) <= EPS; }
};

// checks whether a point is inside a ccw simple polygon
// returns 1 if inside, 0 if on border, -1 if outside
int in_poly(const vector<P> &p, P q) {
    int w = 0;
    rep(i, p.size()) {
        P a = p[i], b = p[(i + 1) % p.size()];
        T k = (b - a) % (q - a);
        T u = a.y - q.y, v = b.y - q.y;
        if(k > 0 && u < 0 && v >= 0) w++;
        if(k < 0 && v < 0 && u >= 0) w--;
        if(k == 0 && (q - a) * (q - b) <= 0) return 0;
    }
    return w ? 1 : -1;
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

    ll pos1 = 0, zero = 0, neg1 = 0;
    rep(i, p1.size()) {
        ll val = in_poly(p2, p1[i]);
        if(val == 0) zero++;
        if(val == 1) pos1++;
        if(val == -1) neg1++;
    }
    ll pos2 = 0, neg2 = 0;
    rep(i, p2.size()) {
        ll val = in_poly(p1, p2[i]);
        if(val == 1) pos2++;
        if(val == -1) neg2++;
    }

    // p1 esta totalmente contenido dentro de p2
    if((pos1 and neg1) or (pos2 and neg2)) cout<<"Impossible\n";
    // if(pos1 or pos2) cout<<"Impossible\n";
    else cout<<zero<<'\n';
    
    return 0;
}