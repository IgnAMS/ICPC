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

db EPS = 1e-12;
struct P {
    ll x, y;
    P(): x(0), y(0) {}
    P(ll x, ll y): x(x), y(y) {}
    bool operator <(const P& p) const {
        return x < p.x or (x == p.x and y < p.y);
    }
    bool operator==(const P& p) const {
        return abs(x - p.x) < EPS and abs(y - p.y) < EPS;
    }
    P operator+(const P& p) const { return P(x + p.x, y + p.y); }
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator-() const { return P(-x, -y); }
    P operator*(ll c) const { return P(c * x, c * y); }
    P operator/(ll c) const { return P(x / c, y / c); }
    ll operator^(const P& p) const { return x * p.y - y * p.x; }
    
    ll operator*(const P& p) const { return x * p.x + y * p.y; }
    ll norm2() const { return x * x + y * y; }
    
};

bool ToLeft(P a, P b) { return (b ^ a) > 0;}
P LTL; 
inline bool Para(P& a, P& b){return !(a ^ b);}
inline bool cmpltl(P& a, P& b){a = a-LTL; b = b-LTL; return Para(a,b) ? a.norm2()<b.norm2() : ToLeft(b,a);}
bool half(P& p) { return p.y > 0 || (p.y == 0 && p.x > 0); }

bool cmp(P& a, P &b) {
    int h1 = half(a), h2 = half(b);
    return h1 != h2 ? h1 > h2 : (a ^ b) > 0;
}

void polarSort(vector<P> &v)
{
    sort(v.begin(), v.end(), [](P &p1, P &p2)
    {
        int h1 = half(p1), h2 = half(p2);
        return h1 != h2 ? h1 > h2 : (p1 ^ p2) > 0;
    });
}

ll turn(P& a, P& b, P& c) {
    return (b - a) ^ (c - a);
}


vector<P> CH(vector<P> &Pol) {
    ll n = Pol.size(), k = 0;
    vector<P> H(2 * n);
    sort(Pol.begin(), Pol.end());
    rep(i, n) {
        while(k >= 2 and turn(H[k - 2], H[k - 1], Pol[i]) <= 0) k--;
        H[k++] = Pol[i];
    }
    for(int i = n - 2, t = k + 1; i >= 0; i--) {
        while(k >= t and turn(H[k - 2], H[k - 1], Pol[i]) <= 0) k--;
        H[k++] = Pol[i];
    }
    H.resize(k - 1);
    return H;
}

// Convex hull to Vector to make a KMP
// length, angle, length, angle, length, ...
vl toV(vector<P>& C) {
    vl V;
    repx(i, 1, C.size() + 1) {
        V.pb((C[i % C.size()] - C[i - 1]).norm2());
        ll aux = (C[i % C.size()] - C[i - 1]) * (C[(i + 1) % C.size()] - C[i % C.size()]);
        ll sign = (C[i % C.size()] - C[i - 1]) * (C[(i + 1) % C.size()] - C[i % C.size()]);
        // sign = (sign > 0? 1: -1);
        // aux = aux * sign;
        V.pb(aux);
    }
    return V;
}

vl kmppre(vl& t) {
    vl r(t.size() + 1); 
    r[0] = -1;
    int j = -1;
    rep(i, t.size()) {
        while(j >= 0 and t[i] != t[j]) j = r[j];
        r[i + 1] = ++j;
    }
    return r;
}


bool kmp(vl& s, vl& t) {
    int j = 0;
    vl b = kmppre(t);
    rep(i, s.size()) {
        while(j >= 0 and s[i] != t[j]) j = b[j];
        if(++j == t.size()) return 1;
    }
    return 0;
}


int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, m; cin>>n>>m;
    vector<P> A(n), B(m);
    rep(i, n) cin>>A[i].x>>A[i].y;
    rep(i, m) cin>>B[i].x>>B[i].y;

    vector<P> CA = CH(A); 
    vector<P> CB = CH(B);
    
    // polarSort(CA);
    // polarSort(CB);
    // for(auto u: CA2) cout<<"("<<u.x<<", "<<u.y<<"), "<<'\n';
    // cout<<'\n';
    // for(auto u: CB2) cout<<"("<<u.x<<", "<<u.y<<"), "<<'\n';
    // cout<<'\n';

    
    vl SA = toV(CA);
    vl SB = toV(CB);

    int na = SA.size();
    repx(i, 0, na) SA.pb(SA[i]);
    // for(auto u: SB) cout<<u<<' '; cout<<'\n';
    // for(auto u: SA) cout<<u<<' '; cout<<'\n';
    cout<<(kmp(SA, SB)? "YES": "NO")<<"\n";

    return 0;
}