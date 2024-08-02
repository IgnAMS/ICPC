#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
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
// g++ -O2 H.cpp && time ./a.out <input.txt> output.txt

const db EPS = 1e-9;
typedef db T;
struct P {
    T x, y;
    P(): x(0), y(0) {}
    P(T x, T y): x(x), y(y) {}
    P operator+(const P& p) const { return P(x + p.x, y + p.y); } 
    P operator-(const P& p) const { return P(x - p.x, y - p.y); }
    P operator*(const db c) const { return P(x * c, y * c); }
    P operator/(const db c) const { return P(x / c, y / c); }
    db operator^(const P& p) const { return x * p.y - y * p.x; }
    db operator*(const P& p) const { return x * p.x + y * p.y; }
    bool operator<(const P& p) const { return abs(x - p.x) > EPS ? p.x - x > EPS : p.y - y > EPS; }
    bool operator==(const P& p) const { return abs(x - p.x) + abs(y - p.y) < EPS; }
};

istream &operator>>(istream &s, P &p) { return s >> p.x >> p.y; }
ostream &operator<<(ostream &s, const P &p) {
    return s << '(' << p.x << ", " << p.y << ')';
}

db turn(P a, P b, P c) {
    return (b - a) ^ (c - a); 
}


struct CH {
    set<P> ch;
    void add(P& p) {
        if(query(p)) return;
        set<P>::iterator x = ch.lower_bound(p);
        set<P>::iterator y = (x == ch.begin()? x: prev(x));

        while(y != ch.begin() and turn(*prev(y), *y, p) >= -EPS) {
            y = prev(y);
            ch.erase(next(y));
        }
        if(ch.size() >= 1 and ch.begin()->x - p.x <= EPS and ch.begin()->y - p.y <= EPS) {
            ch.erase(ch.begin());
        }
        
        while(x != ch.end() and next(x) != ch.end() and turn(*next(x), *x, p) <= EPS) {
            x = next(x);
            ch.erase(prev(x));
        }
        ch.insert(p);
    }

    bool query(P& p) {
        auto x = ch.lower_bound(p);
        if(x == ch.end()) return 0;
        if(x == ch.begin()) return p.y - x->y <= EPS;
        return turn(p, *prev(x), *x) <= EPS;
    }
};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin>>n;
    P X[n];
    rep(i, n) cin >> X[i].x >> X[i].y;
    int q; cin>>q;
    vector<vl> E;
    vl Init(n, 1);
    rep(_, q) {
        char c; cin>>c;
        if(c == 'c') {
            ll t, l, f; cin>>t>>l>>f;
            E.pb({0, t, l, f});
        }
        else {
            ll x; cin>>x; x--;
            Init[x] = 0;
            E.pb({1, x});
        }
    }
    reverse(E.begin(), E.end());

    CH ch;
    rep(i, n) if(Init[i]) {
        ch.add(X[i]);
    }
    vl Ans;
    for(auto& e: E) {
        if(e[0] == 0) {
            ll t, l, f; tie(t, l, f) = tie(e[1], e[2], e[3]);
            P p(l, f);
            p = p / db(t);
            Ans.pb(ch.query(p));
        }
        else {
            int x = e[1];
            ch.add(X[x]);
        }
    }

    reverse(Ans.begin(), Ans.end());
    for(auto u: Ans) cout<<(u == 0? "yes": "no")<<'\n';


    return 0;
}